#include <stddef.h>

typedef struct polinomio {
    int id;
    int *coeficientes;
    int *potencias;
} Poli;
/*
struct do tipo polinomio, com tres campos
id - identificador do polinomio
coeficientes - ponteiro que aponta para um vetor alocado dinamicamente que armazena os coeficientes
potencias - ponteiro que aponta para um vetor alocado dinamicamente que armazena as potencias
*/

typedef struct lista {
    No *inicio;
    int tam;
} Lista;
/*
lista encadeada
inicio - ponteiro do tipo No que aponta para a primeira posicao
tam - armazena o numero de polinomios na lista
*/

typedef struct no {
    Poli valor;
    struct no *prox;
} No;
/*

*/

Lista* criar () {
    Lista *l = (Lista*) malloc (sizeof (Lista));
    if (l == NULL) return 2;
    l -> inicio = NULL;
    return l;    
}
/*
funcao que cria uma lista e retorna um ponteiro 
*/

int listavazia (Lista*l) {
    if (l == NULL) return 2;
    if (l -> inicio == NULL) return 0;
    return 1;
}
/*
funcao que verifica se a lista esta vazia, retorna 0 caso esteja e 1 caso nao esteja
*/

int inserirpolinomio (Lista *l, Poli x) {
    
}
/*
funcao que insere um novo polinomio na lista
*/

int inseretermo (Lista *l, int idx, int coef, int pot) {

}
/*
funcao que insere um novo termo em um polinomio da lista 
a funcao recebe uma lista de polinomios, um identificador para qual polinomio deve ser alterado na lista, e o coeficiente e potencia do termo adicionado
*/

void mostrar (Lista *l, int idx) {

}
/*
funcao que mostra ao usuario o polinomio da lista l e de identificador idx com a formatacao especificada
*/

int removerk (Lista *l, int idx, int k) {

}
/*
funcao que recebe uma lista, um identificador idx e elimina o termo associado a k-esima potencia, fazendo os ajustes necessarios para o polinomio continuar valido
*/

int reinicializar (Lista *l, int idx) {

}
/*
funcao que recebe uma lista e um identificador idx e reinicializa o polinomio indicado para a forma 0x^0
*/

int soma (Lista *l, int idx, Lista *J, int idy) {

}
/*
funcao que soma dois polinomios, recebe a lista e o identificador de cada polinomio
*/

int valorpx (Lista *l, int idx, int num) {

}
/*
funcao que calcula o valor de p(x) para um valor x solicitado
*/