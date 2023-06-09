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

Polinomio* obterElemento(Lista* lista, int posicao) {
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

int compararTermos(const void* a, const void* b) {
    const Termo* termoA = (const Termo*)a;
    const Termo* termoB = (const Termo*)b;

    // Ordenar em ordem decrescente com base nos graus
    if (termoA->grau > termoB->grau)
        return -1;
    else if (termoA->grau < termoB->grau)
        return 1;
    else
        return 0;
}
