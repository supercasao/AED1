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
typedef struct lista Lista;
Lista* criar ();
typedef struct no No;
void mostrar (Lista *l, int num);
int inserir (Lista *l, Poli x);
int listavazia (Lista*l);
int removerk (Lista *l, int idx, int k);
int reinicializar (Lista *l, int idx);
int soma (Lista *l, int idx, Lista *J, int idy);
int valorpx (Lista *l, int idx, int num);
int inseretermo (Lista *l, int idx, int coef, int pot);
