#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "polinomio.h"


int main()
{
    Lista *l = criarLista();
    int op,opcao;
    int coef,expo;
    char id;
    Polinomio *po;
    //explica para o usuario o salvamento do polinomio
    printf("antes de iniciar um novo polinomio salve o atual.Caso voce inicie um novo polinomio sem salvar, o atual ele sera perdido.\n");
    //confirmacao de continuacao
    int a;
        do{
            printf("Digite 1 para continuar:");
            scanf("%d",&a);
        }while(a != 1);
    //menu principal
    do{
        do{
            system("cls");
            printf("Escolha uma das opcoes abaixo:\n");
            printf("(1)Iniciar um novo Polinomio.\n");
            printf("(2)Inserir um novo termo.\n");
            printf("(3)exibir o Polinomio.\n");
            printf("(4)Eliminar um termo.\n");
            printf("(5)Reiniciar o polinomio.\n");
            printf("(6)Salvar o polinomio.\n");
            printf("(7)Somar dois Polinomios.\n");
            printf("(8)Calcular com valor X.\n");
            printf("(9)Selecionar um polinomio.\n");
            printf("(0)Sair.\n");
            printf("Digite o numero da opcao:");
            scanf("%d",&op);
        }while((op < 0)||(op > 8));
        //limpa o buffer para a leitura do id
        fflush(stdin);
        if(op == 1){
            po = inicializarPolinomio();
        }
        if(op == 2){
            //impede o usuario de adicionar termo a um polinomio nao iniciado
            if(po == NULL){
                printf("polinomio nao iniciado.\n");
            int x;
            do{
                printf("Digite 1 para continuar:");
                scanf("%d",&x);
            }while(x != 1);
            }else{
            printf("digite um valor para coeficiente:");
            scanf("%d",&coef);
            printf("digite um valor para o expoente:");
            scanf("%d",&expo);
            inserirTermo(po,coef,expo);
            }
    }
        if(op == 3){
            exibirPolinomio(po);
            int x;
            do{
                printf("Digite 1 para continuar:");
                scanf("%d",&x);
            }while(x != 1);
        }
        if(op == 4){
            printf("digite o expoente do termo:");
            scanf("%d",&expo);
            eliminarTermo(po,expo);
        }
        if(op == 5)
            reinicializarPolinomio(po);
        if( op == 6){
            printf("Digite um identificador para o polinomio:");
            scanf("%c",&id);
            inserirFim(l,po,id);
        }
        if(op == 7){
            char id1,id2;
            printf("digite o id do primeiro polinomio:");
            scanf("%c",&id1);
            printf("digite o id do segundo polinomio:");
            scanf("%c",&id2);
            Polinomio *p1 = obterElemento(l,id1);
            Polinomio *p2 = obterElemento(l,id2);
            somarPolinomios(p1,p2);

        }
        if(op == 8){
            float x;
            printf("digite um valor para X:");
            scanf("%f",&x);
            float e = calcular_valorPolinomio(po,x);
            printf("o valor com X = %f eh: %f\n",x,e);
            int y;
            do{
                printf("Digite 1 para continuar:");
                scanf("%d",&y);
            }while(y != 1);
        }
        if(op == 9){
            printf("digite o id do polinomio:");
            scanf("%c",&id);
            po = obterElemento(l,id);
        }
    }while(op != 0);


    return 0;
}
