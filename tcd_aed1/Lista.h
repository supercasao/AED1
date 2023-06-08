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
void inserirInicio(Lista* lista, Polinomio *valor, char id);
void inserirFim(Lista* lista, Polinomio *valor, char id);
void inserirPosicao(Lista* lista, Polinomio *valor, int posicao, char id);
void removerInicio(Lista* lista);
void removerFim(Lista* lista);
void removerPosicao(Lista* lista, int posicao);
Polinomio* obterElemento(Lista* lista, char id);
int tamanhoLista(Lista* lista);
void exibirLista(Lista* lista);

#endif /* LISTA_H */
