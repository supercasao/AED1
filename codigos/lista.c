#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

void destruirLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual->polinomio->termos);
        free(atual->polinomio);
        free(atual);
        atual = proximo;
    }
    free(lista);
}

void inserir(Lista* lista, Polinomio* polinomio) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->id = lista->tamanho + 1;
    novoNo->polinomio = polinomio;
    novoNo->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
    } else {
        lista->fim->proximo = novoNo;
        lista->fim = novoNo;
    }

    lista->tamanho++;
}

Polinomio* obterElemento(Lista* lista, int id) {
    No* noAtual = lista->inicio;
    while (noAtual != NULL) {
        if (noAtual->id == id) {
            return noAtual->polinomio;
        }
        noAtual = noAtual->proximo;
    }
    return NULL;
}

void exibirLista(Lista* lista) {
    No* noAtual = lista->inicio;
    while (noAtual != NULL) {
    	printf("ID: %d - ", noAtual->id);
        for (int i = 0; i < noAtual->polinomio->tamanho; i++) {
            Termo termo = noAtual->polinomio->termos[i];

            if (termo.coeficiente != 0) {
                if (termo.coeficiente > 0 && i != 0) {
                    printf("+ ");
                }
                printf("%dx^%d ", termo.coeficiente, termo.expoente);
            }
        }
        printf("\n");
        noAtual = noAtual->proximo;
    }
}


void removerInicio(Lista* lista) {
    if (lista->inicio == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    No* no_removido = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    free(no_removido);

    No* noAtual = lista->inicio;
    int id = 1;
    while (noAtual != NULL) {
        noAtual->id = id;
        noAtual = noAtual->proximo;
        id++;
    }

    lista->tamanho--;

    if (lista->inicio == NULL) {
        lista->fim = NULL;
    }
}

void removerFim(Lista* lista) {
    if (lista->fim == NULL) {
        printf("A lista esta vazia.\n");
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

void removerPosicao(Lista* lista, int id) {
    if (id < 0 || id >= lista->tamanho) {
        printf("Posicao invalida.\n");
        return;
    }

    if (id == 0) {
        removerInicio(lista);
    } else if (id == lista->tamanho - 1) {
        removerFim(lista);
    } else {
        No* no_anterior = lista->inicio;
        int i;
        for (i = 1; i < id; i++) {
            no_anterior = no_anterior->proximo;
        }

        No* no_removido = no_anterior->proximo;
        No* no_proximo = no_removido->proximo;
        no_anterior->proximo = no_proximo;
        free(no_removido);

        No* noAtual = no_proximo;
        int novoId = id + 1;
        while (noAtual != NULL) {
            noAtual->id = novoId;
            noAtual = noAtual->proximo;
            novoId++;
        }

        lista->tamanho--;
    }
}

int tamanhoLista(Lista* lista) {
    int tamanho = 0;
    No* noAtual = lista->inicio;
    while (noAtual != NULL) {
        tamanho++;
        noAtual = noAtual->proximo;
    }
    return tamanho;
}


