#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int coeficiente;
    int expoente;
} Termo;

typedef struct {
    int grau;
    Termo* termos;
    int tamanho;
} Polinomio;


typedef struct No {	
	int id;		
    Polinomio* polinomio;
    struct No* proximo;
} No;

typedef struct Lista {
    No* inicio;
    No* fim;
    int tamanho;
} Lista;

Lista* criarLista();
void destruirLista(Lista* lista);
void inserir(Lista* lista, Polinomio* polinomio);
void removerFim(Lista* lista);
void removerInicio(Lista* lista);
void removerPosicao(Lista* lista, int id);
Polinomio* obterElemento(Lista* lista, int id);
int tamanhoLista(Lista* lista);
void exibirLista(Lista* lista);
Polinomio* obterElemento(Lista* lista, int id);

#endif /* LISTA_H */
