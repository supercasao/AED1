#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
    #define PAUSE_COMMAND "pause"
#else
    #define CLEAR_COMMAND "clear"
    #define PAUSE_COMMAND "read -p 'Pressione Enter para continuar...'"
#endif

void limparTela(){
    system(PAUSE_COMMAND);  
    system(CLEAR_COMMAND);
}

void exibirMenu() {
    printf("=====================\n");
    printf("       MENU\n");
    printf("=====================\n");
    printf("1. Inserir novo polinomio\n");
    printf("2. Carregar polinomios salvos\n");
    printf("3. Editar polinomios anteriores\n");
    printf("4. Calcular resultado do polinomio\n");
    printf("5. Somar polinomios\n");
    printf("6. Sair\n");
    printf("=====================\n");
    printf("Opcao: ");
}

