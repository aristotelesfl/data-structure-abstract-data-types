#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED

#define MAX_SIZE 100
#define True 1
#define False 0

typedef int ConjuntoDeInteiros[MAX_SIZE];

void imprimeConjunto(ConjuntoDeInteiros conjunto);
void fazConjuntoVazio(ConjuntoDeInteiros conjunto);
int inserirNoConjunto(int number, ConjuntoDeInteiros conjunto);
int pertenceAoConjunto(int number, ConjuntoDeInteiros conjunto);
int retiraDoConjunto(int number, ConjuntoDeInteiros conjunto);
int maxDoConjunto(int *maiorElemento, ConjuntoDeInteiros conjunto);
int maxMinDoConjunto(int *maiorElemento, int *menorElemento, ConjuntoDeInteiros conjunto);
int maxMinDoConjunto2(int *maiorElemento, int *menorElemento, ConjuntoDeInteiros conjunto);

#endif
