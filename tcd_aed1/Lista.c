#include <stddef.h>

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

void destruiLista(Lista* lista) {
    No* no_atual = lista->inicio;
    while (no_atual != NULL) {
        No* proximo = no_atual->proximo;
        free(no_atual);
        no_atual = proximo;
    }
    free(lista);
}

void inserirInicio(Lista* lista, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = lista->inicio;
    lista->inicio = novo_no;
    if (lista->fim == NULL) {
        lista->fim = novo_no;
    }
    lista->tamanho++;
}

void inserirFim(Lista* lista, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    if (lista->fim == NULL) {
        lista->inicio = novo_no;
    } else {
        lista->fim->proximo = novo_no;
    }
    lista->fim = novo_no;
    lista->tamanho++;
}

void inserirPosicao(Lista* lista, int valor, int posicao) {
    if (posicao < 0 || posicao > lista->tamanho) {
        printf("Posição inválida.\n");
        return;
    }
    if (posicao == 0) {
        inserir_inicio(lista, valor);
    } else if (posicao == lista->tamanho) {
        inserir_fim(lista, valor);
    } else {
        No* novo_no = (No*)malloc(sizeof(No));
        novo_no->valor = valor;

        No* no_anterior = lista->inicio;
        int i;
        for (i = 1; i < posicao; i++) {
            no_anterior = no_anterior->proximo;
        }

        No* no_proximo = no_anterior->proximo;
        no_anterior->proximo = novo_no;
        novo_no->proximo = no_proximo;

        lista->tamanho++;
    }
}

void removerInicio(Lista* lista) {
    if (lista->inicio == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    No* no_removido = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    free(no_removido);
    lista->tamanho--;

    if (lista->inicio == NULL) {
        lista->fim = NULL;
    }
}

void removerFim(Lista* lista) {
    if (lista->fim == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    if (lista->inicio == lista->fim) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        No* no_anterior = lista->inicio;
        while (no_anterior->proximo != lista->fim) {
            no_anterior = no_anterior->proximo;
        }

        free(lista->fim);
        no_anterior->proximo = NULL;
        lista->fim = no_anterior;
    }

    lista->tamanho--;
}

void removerPosicao(Lista* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posição inválida.\n");
        return;
    }

    if (posicao == 0) {
        remover_inicio(lista);
    } else if (posicao == lista->tamanho - 1) {
        remover_fim(lista);
    } else {
        No* no_anterior = lista->inicio;
        int i;
        for (i = 1; i < posicao; i++) {
            no_anterior = no_anterior->proximo;
        }

        No* no_removido = no_anterior->proximo;
        No* no_proximo = no_removido->proximo;
        no_anterior->proximo = no_proximo;
        free(no_removido);

        lista->tamanho--;
    }
}

int obterElemento(Lista* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posição inválida.\n");
        return -1;
    }

    No* no_atual = lista->inicio;
    int i;
    for (i = 0; i < posicao; i++) {
        no_atual = no_atual->proximo;
    }

    return no_atual->valor;
}

int tamanhoLista(Lista* lista) {
    return lista->tamanho;
}

void exibirLista(Lista* lista) {
    No* no_atual = lista->inicio;
    while (no_atual != NULL) {
        printf("%d ", no_atual->valor);
        no_atual = no_atual->proximo;
    }
    printf("\n");
}

Polinomio* inicializarPolinomio() {
    Polinomio* polinomio = (Polinomio*)malloc(sizeof(Polinomio));
    polinomio->termos = NULL;
    polinomio->tamanho = 0;
    return polinomio;
}

void exibirPolinomio(Polinomio* polinomio) {
    if (polinomio->tamanho == 0) {
        printf("P(x) = 0x^0\n");
        return;
    }

    printf("P(x) = ");
    for (int i = 0; i < polinomio->tamanho; i++) {
        Termo termo = polinomio->termos[i];

        if (termo.coeficiente != 0) {
            // Exibir o coeficiente e o expoente somente se o coeficiente for diferente de zero
            if (termo.coeficiente > 0 && i != 0) {
                printf("+ ");
            }
            printf("%dx^%d ", termo.coeficiente, termo.expoente);
        }
    }
    printf("\n");
}

void inserirTermo(Polinomio* polinomio, int coeficiente, int expoente) {
    // Verificar se o termo já existe
    for (int i = 0; i < polinomio->tamanho; i++) {
        if (polinomio->termos[i].expoente == expoente) {
            int opcao;
            printf("O termo %dx^%d já existe no polinômio. Escolha uma opção:\n", coeficiente, expoente);
            printf("1. Inserir o novo termo na posição correspondente\n");
            printf("2. Substituir o termo existente pelo novo termo\n");
            printf("3. Adicionar o valor do novo termo ao valor já existente no termo\n");
            printf("Opção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1: {
                    // Inserir o novo termo na posição correspondente
                    polinomio->termos = (Termo*)realloc(polinomio->termos, (polinomio->tamanho + 1) * sizeof(Termo));
                    for (int j = polinomio->tamanho - 1; j >= i; j--) {
                        polinomio->termos[j + 1] = polinomio->termos[j];
                    }
                    polinomio->termos[i].coeficiente = coeficiente;
                    polinomio->termos[i].expoente = expoente;
                    polinomio->tamanho++;
                    break;
                }
                case 2: {
                    // Substituir o termo existente pelo novo termo
                    polinomio->termos[i].coeficiente = coeficiente;
                    break;
                }
                case 3: {
                    // Adicionar o valor do novo termo ao valor já existente no termo
                    polinomio->termos[i].coeficiente += coeficiente;
                    break;
                }
                default: {
                    printf("Opção inválida!\n");
                    return;
                }
            }

            return;
        }
    }

    // Inserir o novo termo no final do polinômio
    polinomio->termos = (Termo*)realloc(polinomio->termos, (polinomio->tamanho + 1) * sizeof(Termo));
    polinomio->termos[polinomio->tamanho].coeficiente = coeficiente;
    polinomio->termos[polinomio->tamanho].expoente = expoente;
    polinomio->tamanho++;
}

void eliminarTermo(Polinomio* polinomio, int expoente) {
    int indice = -1;

    // Encontrar o índice do termo com o expoente k
    for (int i = 0; i < polinomio->tamanho; i++) {
        if (polinomio->termos[i].expoente == expoente) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Termo com expoente %d não encontrado no polinômio.\n", expoente);
        return;
    }

    // Remover o termo do polinômio
    for (int i = indice; i < polinomio->tamanho - 1; i++) {
        polinomio->termos[i] = polinomio->termos[i + 1];
    }
    polinomio->tamanho--;

    // Redimensionar o array de termos
    polinomio->termos = (Termo*)realloc(polinomio->termos, polinomio->tamanho * sizeof(Termo));
}

void reinicializarPolinomio(Polinomio* polinomio) {
    // Limpar os termos existentes
    free(polinomio->termos);

    // Criar um novo termo com coeficiente 0 e expoente 0
    polinomio->termos = (Termo*)malloc(sizeof(Termo));
    polinomio->termos[0].coeficiente = 0;
    polinomio->termos[0].expoente = 0;
    polinomio->tamanho = 1;
}


Polinomio* somarPolinomios(Polinomio* polinomio1, Polinomio* polinomio2) {
    Polinomio* resultado = inicializar_polinomio();

    int indice1 = 0;
    int indice2 = 0;

    while (indice1 < polinomio1->tamanho && indice2 < polinomio2->tamanho) {
        Termo termo1 = polinomio1->termos[indice1];
        Termo termo2 = polinomio2->termos[indice2];

        if (termo1.expoente == termo2.expoente) {
            int coeficiente = termo1.coeficiente + termo2.coeficiente;
            inserir_termo(resultado, coeficiente, termo1.expoente);
            indice1++;
            indice2++;
        } else if (termo1.expoente < termo2.expoente) {
            inserir_termo(resultado, termo1.coeficiente, termo1.expoente);
            indice1++;
        } else {
            inserir_termo(resultado, termo2.coeficiente, termo2.expoente);
            indice2++;
        }
    }

    // Copiar os termos restantes do polinômio 1
    while (indice1 < polinomio1->tamanho) {
        Termo termo1 = polinomio1->termos[indice1];
        inserir_termo(resultado, termo1.coeficiente, termo1.expoente);
        indice1++;
    }

    // Copiar os termos restantes do polinômio 2
    while (indice2 < polinomio2->tamanho) {
        Termo termo2 = polinomio2->termos[indice2];
        inserir_termo(resultado, termo2.coeficiente, termo2.expoente);
        indice2++;
    }

    return resultado;
}

void calcular_valorPolinomio(Polinomio* polinomios, int num_polinomios, float x) {
    float menor_valor = INFINITY;
    float maior_valor = -INFINITY;
    int indice_menor_valor = -1;
    int indice_maior_valor = -1;

    for (int i = 0; i < num_polinomios; i++) {
        Polinomio* polinomio = polinomios[i];
        float valor = 0.0;

        for (int j = 0; j < polinomio->tamanho; j++) {
            Termo termo = polinomio->termos[j];
            valor += termo.coeficiente * pow(x, termo.expoente);
        }

        printf("Valor de P(x) para o polinômio %d: %.2f\n", i + 1, valor);

        if (valor < menor_valor) {
            menor_valor = valor;
            indice_menor_valor = i;
        }

        if (valor > maior_valor) {
            maior_valor = valor;
            indice_maior_valor = i;
        }
    }

    printf("Polinômio com o menor valor: %d\n", indice_menor_valor + 1);
    printf("Polinômio com o maior valor: %d\n", indice_maior_valor + 1);
}

void destruirPolinomio(Polinomio* polinomio) {
    free(polinomio->termos);
    free(polinomio);
}
