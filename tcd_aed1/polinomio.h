#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

Polinomio* inicializarPolinomio();
void exibirPolinomio(Polinomio* polinomio);
void inserirTermo(Polinomio* polinomio, int coeficiente, int expoente);
void eliminarTermo(Polinomio* polinomio, int expoente);
void reinicializarPolinomio(Polinomio* polinomio);
Polinomio* somarPolinomios(Polinomio* polinomio1, Polinomio* polinomio2);
int calcular_valorPolinomio(Polinomio* polinomios,  float x);
void destruirPolinomio(Polinomio* polinomio);

#endif // POLINOMIO_H_INCLUDED
