#include <stdio.h>
#include <stdlib.h>
#include "lista.c"
#include "polinomio.c"
#include "menu.c"

int main() {
    Lista* lista = criarLista();
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
            	limparTela();
                printf("=====================\n");
                printf("INSERIR NOVO POLINOMIO\n");
                printf("=====================\n");

                Polinomio* polinomio = inicializarPolinomio();
                int opcaoInserir = 1;

                while (opcaoInserir) {
                    int coeficiente, expoente;

                    printf("Inserir novo termo:\n");
                    printf("Coeficiente: ");
                    scanf("%d", &coeficiente);
                    printf("Expoente: ");
                    scanf("%d", &expoente);

                    inserirTermo(polinomio, coeficiente, expoente);

                    printf("Deseja inserir mais um termo? (1 - Sim, 0 - Nao): ");
                    scanf("%d", &opcaoInserir);
                    printf("\n");
                }

                printf("polinomio inserido:\n");
                exibirPolinomio(polinomio);

                int opcaoSalvar;
                printf("Deseja salvar o polinomio na lista? (1 - Sim, 0 - Nao): ");
                scanf("%d", &opcaoSalvar);

                if (opcaoSalvar) {
                    inserir(lista, polinomio);
                    printf("polinomio salvo com ID: %d\n", lista->fim->id);
                } else {
                    printf("polinomio não foi salvo na lista.\n");
                    free(polinomio->termos);
                    free(polinomio);
                }

                break;
            }

            case 2: {
                printf("============================\n");
                printf("CARREGAR POLINOMIOS SALVOS\n");
                printf("============================\n");

                exibirLista(lista);

                break;
            }

            case 3: {
                printf("===============================\n");
                printf("EDITAR POLINOMIOS ANTERIORES\n");
                printf("===============================\n");

                exibirLista(lista);

                int id;
                printf("Digite o ID do polinomio a ser editado (ou '0' para voltar): ");
                scanf("%d", &id);

                if (id == 0) {
                    break;
                }

                Polinomio* polinomio = obterElemento(lista, id);

                if (polinomio != NULL) {
                    printf("polinomio selecionado:\n");
                    exibirPolinomio(polinomio);

                    int opcao;
                    do {
                        printf("\nEscolha uma opcao:\n");
                        printf("1. Adicionar termo\n");
                        printf("2. Remover termo\n");
                        printf("3. Voltar\n");
                        printf("Opcao: ");
                        scanf("%d", &opcao);

                        switch (opcao) {
                            case 1: {
                                int coeficiente, expoente;
                                printf("Digite o coeficiente do novo termo: ");
                                scanf("%d", &coeficiente);
                                printf("Digite o expoente do novo termo: ");
                                scanf("%d", &expoente);
                                inserirTermo(polinomio, coeficiente, expoente);
                                break;
                            }
                            case 2: {
                                int coeficiente, expoente;
                                printf("Digite o coeficiente do termo a ser excluido: ");
                                scanf("%d", &coeficiente);
                                printf("Digite o expoente do termo a ser excluido: ");
                                scanf("%d", &expoente);
                                eliminarTermo(polinomio, expoente, coeficiente);
                                break;
                            }
                            case 3: {
                                break;
                            }
                            default: {
                                printf("Opcao invalida!\n");
                                break;
                            }
                        }

                        printf("polinomio atual:\n");
                        exibirPolinomio(polinomio);
                        printf("\n");

                    } while (opcao != 3);

                    printf("Edicao concluida.\n");
                } else {
                    printf("ID de polinomio invalido. Por favor, tente novamente.\n");
                }

                break;
            }

            case 4: {
                printf("==============================\n");
                printf("CALCULAR RESULTADO DO POLINIMIO\n");
                printf("==============================\n");

                exibirLista(lista);
                int id;
                printf("Digite o ID do polinomio a ser calculado: ");
                scanf("%d", &id);
                Polinomio* polinomio = obterElemento(lista, id);
                if (polinomio != NULL) {
                    printf("Digite o valor de x: ");
                    int x;
                    scanf("%d", &x);
                    int resultado = calcularResultado(polinomio, x);
                    printf("O resultado do polinomio P(x) = ");
                    exibirPolinomio(polinomio);
                    printf("para x = %d eh %d\n", x, resultado);
                }

                break;
            }

            case 5: {
                printf("===================\n");
                printf("SOMAR POLINOMIOS\n");
                printf("===================\n");

                exibirLista(lista);
                int id1, id2;
                printf("Digite o ID do primeiro polinomio: ");
                scanf("%d", &id1);
                printf("Digite o ID do segundo polinomio: ");
                scanf("%d", &id2);

                Polinomio* resultado = somarPolinomios(lista, id1, id2);
                if (resultado != NULL) {
                    printf("Resultado da soma: ");
                    exibirPolinomio(resultado);
                }

                break;
            }

            case 6: {
                printf("=================================\n");
                printf("|                               |\n");
                printf("|   Obrigado Professor          |\n");
                printf("|      Jose Gustavo.            |\n");
                printf("|                               |\n");
                printf("=================================\n");
                break;
            }

            default: {
                printf("Opcao invalida!\n");
                break;
            }
        }

        printf("\n");
        limparTela();

    } while(opcao != 6);

    destruirLista(lista);

    return 0;
}

