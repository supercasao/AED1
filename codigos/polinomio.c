#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "lista.h"
#include "polinomio.h"
#include "math.h"

Polinomio* inicializarPolinomio() {
    Polinomio* polinomio = (Polinomio*)malloc(sizeof(Polinomio));
    if (polinomio == NULL) {
        printf("Erro ao alocar memoria para o polinomio.\n");
        return NULL;
    }
    polinomio->termos = NULL;
    polinomio->tamanho = 0;
    return polinomio;
}

void exibirPolinomio(Polinomio* polinomio) {
    for (int i = 0; i < polinomio->tamanho; i++) {
        Termo termo = polinomio->termos[i];

        if (termo.coeficiente != 0) {
            if (termo.coeficiente > 0 && i != 0) {
                printf("+ ");
            }
            printf("%dx^%d ", termo.coeficiente, termo.expoente);
        }
    }
    printf("\n");
}

void inserirTermo(Polinomio* polinomio, int coeficiente, int expoente) {
    for (int i = 0; i < polinomio->tamanho; i++) {
        if (polinomio->termos[i].coeficiente == coeficiente && polinomio->termos[i].expoente == expoente) {
            int opcao;
            printf("O termo %dx^%d já existe no polinômio. Escolha uma opção:\n", coeficiente, expoente);
            printf("1. Inserir o novo termo na posição correspondente\n");
            printf("2. Substituir o termo existente pelo novo termo\n");
            printf("3. Adicionar o valor do novo termo ao valor já existente no termo\n");
            printf("Opção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1: {
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
                    polinomio->termos[i].coeficiente = coeficiente;
                    break;
                }
                case 3: {
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

    polinomio->termos = (Termo*)realloc(polinomio->termos, (polinomio->tamanho + 1) * sizeof(Termo));
    polinomio->termos[polinomio->tamanho].coeficiente = coeficiente;
    polinomio->termos[polinomio->tamanho].expoente = expoente;
    polinomio->tamanho++;
}


void eliminarTermo(Polinomio* polinomio, int expoente, int coeficiente) {
    int indice = -1;

    for (int i = 0; i < polinomio->tamanho; i++) {
        if (polinomio->termos[i].expoente == expoente && polinomio->termos[i].coeficiente == coeficiente) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Termo com expoente %d e coeficiente %d nao encontrado no polinomio.\n", expoente, coeficiente);
        return;
    }

    for (int i = indice; i < polinomio->tamanho - 1; i++) {
        polinomio->termos[i] = polinomio->termos[i + 1];
    }
    
    polinomio->tamanho--;

    polinomio->termos = (Termo*)realloc(polinomio->termos, polinomio->tamanho * sizeof(Termo));
}


void reinicializarPolinomio(Polinomio* polinomio) {
    free(polinomio->termos);
    polinomio->termos = (Termo*)malloc(sizeof(Termo));
    polinomio->termos[0].coeficiente = 0;
    polinomio->termos[0].expoente = 0;
    polinomio->tamanho = 1;
}

Polinomio* somarPolinomios(Lista* lista, int id1, int id2) {
    Polinomio* polinomio1 = obterElemento(lista, id1);
    Polinomio* polinomio2 = obterElemento(lista, id2);

    if (polinomio1 == NULL || polinomio2 == NULL) {
        printf("Polinomio(s) invalido(s)!\n");
        return NULL;
    }

    Polinomio* resultado = inicializarPolinomio();

    for (int i = 0; i < polinomio1->tamanho; i++) {
        Termo termo1 = polinomio1->termos[i];
        inserirTermo(resultado, termo1.coeficiente, termo1.expoente);
    }

    for (int i = 0; i < polinomio2->tamanho; i++) {
        Termo termo2 = polinomio2->termos[i];

        int termoExistente = 0;
        for (int j = 0; j < resultado->tamanho; j++) {
            if (resultado->termos[j].expoente == termo2.expoente) {
                resultado->termos[j].coeficiente += termo2.coeficiente;
                termoExistente = 1;
                break;
            }
        }

        if (!termoExistente) {
            inserirTermo(resultado, termo2.coeficiente, termo2.expoente);
        }
    }

    int idResultado = tamanhoLista(lista) + 1;
    inserir(lista, resultado);

    printf("Polinomio resultante adicionado com ID: %d\n", idResultado);

    return resultado;
}

int calcularResultado(Polinomio* polinomio, int x) {
    int resultado = 0;
    
    for (int i = 0; i < polinomio->tamanho; i++) {
        Termo termo = polinomio->termos[i];
        resultado += termo.coeficiente * pow(x, termo.expoente);
    }
    
    return resultado;
}

void destruirPolinomio(Polinomio* polinomio) {
    free(polinomio->termos);
    free(polinomio);
}

