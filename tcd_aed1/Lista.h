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

typedef struct {
    int coeficiente;
    int expoente;
} Termo;

typedef struct {
    int grau;
    Termo* termos;
    int tamanho;
} Polinomio;

Lista* criarLista();
void destruirLista(Lista* lista);
void inserirInicio(Lista* lista, int valor);
void inserirFim(Lista* lista, int valor);
void inserirPosicao(Lista* lista, int valor, int posicao);
void removerInicio(Lista* lista);
void removerFim(Lista* lista);
void removerPosicao(Lista* lista, int posicao);
int obterElemento(Lista* lista, int posicao);
int tamanhoLista(Lista* lista);
void exibirLista(Lista* lista);

#endif /* LISTA_H */
