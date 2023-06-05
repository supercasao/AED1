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
Polinomio* inicializarPolinomio();
void exibirPolinomio(Polinomio* polinomio);
void inserirTermo(Polinomio* polinomio, int coeficiente, int expoente);
void eliminarTermo(Polinomio* polinomio, int expoente);
void reinicializarPolinomio(Polinomio* polinomio);
Polinomio* somarPolinomios(Polinomio* polinomio1, Polinomio* polinomio2);
void calcular_valorPolinomio(Polinomio* polinomios, int num_polinomios, float x);
void destruirPolinomio(Polinomio* polinomio);

#endif /* LISTA_H */
