#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include "lista.h"

Polinomio* inicializarPolinomio();
void exibirPolinomio(Polinomio* polinomio);
void inserirTermo(Polinomio* polinomio, int coeficiente, int expoente);
void eliminarTermo(Polinomio* polinomio, int expoente, int coeficiente);
void reinicializarPolinomio(Polinomio* polinomio);
Polinomio* somarPolinomios(Lista* lista, int id1, int id2);
int calcularResultado(Polinomio* polinomio, int x);
void destruirPolinomio(Polinomio* polinomio);

#endif // POLINOMIO_H_INCLUDED
