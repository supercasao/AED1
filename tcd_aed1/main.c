#include <stdio.h>
#include <stdlib.h>

int main(){
    int OpcaoMenu;
    do {
    	printf("---- Escolha uma opcao: ---- \n");
        printf("1. Iniciar polinomio\n");
        printf("2. Carregar polinomios anteriores\n");
        printf("3. Mostrar historico\n");
        printf("0. Sair\n");
        scanf("%d", &OpcaoMenu);
        switch (OpcaoMenu) {
            case 1:
                IniciaPolinomio(); //função carrega polinomio
                break;
            case 2:
                LoadPolinomio(); //função carregar polinomio especifico
                break;
            case 3:
                MostrarHistorico(); //função carrega historico
                break;
            case 0:
                Sair();
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (OpcaoMenu > 3 || OpcaoMenu < 0);
    
    system("pause")
    return 0;
}
