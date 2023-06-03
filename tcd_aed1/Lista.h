#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int valor;
    struct no* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Lista;

Lista* criar_lista();
void destruir_lista(Lista* lista);
void inserir_inicio(Lista* lista, int valor);
void inserir_fim(Lista* lista, int valor);
void inserir_posicao(Lista* lista, int valor, int posicao);
void remover_inicio(Lista* lista);
void remover_fim(Lista* lista);
void remover_posicao(Lista* lista, int posicao);
int obter_elemento(Lista* lista, int posicao);
int tamanho_lista(Lista* lista);
void exibir_lista(Lista* lista);

#endif /* LISTA_H */
