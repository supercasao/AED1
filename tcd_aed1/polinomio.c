#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "lista.h"
#include "polinomio.h"

Polinomio* inicializarPolinomio() {
    Polinomio* polinomio = (Polinomio*)malloc(sizeof(Polinomio));
    polinomio->termos = (Termo*)malloc(sizeof(Termo) * 1);
    polinomio->tamanho = 1;
    return polinomio;
}

void exibirPolinomio(Polinomio* polinomio) {
    printf("P(x) = 0x^0");
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
            printf("O termo %dx^%d ja existe no polinomio. Escolha uma opcao:\n", coeficiente, expoente);
            printf("1. Inserir o novo termo na posição correspondente\n");
            printf("2. Substituir o termo existente pelo novo termo\n");
            printf("3. Adicionar o valor do novo termo ao valor ja existente no termo\n");
            printf("Opcao: ");
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

Polinomio* somarPolinomios(int id1, int id2) {
    Polinomio* polinomio1 = obterPolinomioPorId(id1);
    Polinomio* polinomio2 = obterPolinomioPorId(id2);

    if (polinomio1 == NULL || polinomio2 == NULL) {
        printf("Polinômio(s) inválido(s)!\n");
        return NULL;
    }

    Polinomio* resultado = inicializarPolinomio();

    // Percorre o primeiro polinômio e insere os termos no resultado
    for (int i = 0; i < polinomio1->tamanho; i++) {
        Termo termo1 = polinomio1->termos[i];
        inserirTermo(resultado, termo1.coeficiente, termo1.expoente);
    }

    // Percorre o segundo polinômio e realiza a soma dos termos
    for (int i = 0; i < polinomio2->tamanho; i++) {
        Termo termo2 = polinomio2->termos[i];

        int termoExistente = 0;
        for (int j = 0; j < resultado->tamanho; j++) {
            if (resultado->termos[j].expoente == termo2.expoente) {
                // Soma o coeficiente do termo2 ao coeficiente do termo existente no resultado
                resultado->termos[j].coeficiente += termo2.coeficiente;
                termoExistente = 1;
                break;
            }
        }

        if (!termoExistente) {
            // O termo2 não existe no resultado, então insere o termo2 no resultado
            inserirTermo(resultado, termo2.coeficiente, termo2.expoente);
        }
    }

    return resultado;
}
