#include <stdio.h>
#include <locale.h>
#include "conjunto.h"
#include "conjunto.c"

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int maiorElemento, menorElemento;
    ConjuntoDeInteiros conjunto;
    int number;

    fazConjuntoVazio(conjunto);

    inserirNoConjunto(1, conjunto);
    inserirNoConjunto(4, conjunto);
    inserirNoConjunto(50, conjunto);
    inserirNoConjunto(10, conjunto);

    imprimeConjunto(conjunto);

    retiraDoConjunto(4, conjunto);

    if (maxMinDoConjunto(&maiorElemento, &menorElemento, conjunto)==True) {
        printf("maxMinDoConjunto: maior = %d, menor = %d\n", maiorElemento, menorElemento);
    } else {
        printf("erro na busca\n");
    }

    if (maxMinDoConjunto2(&maiorElemento, &menorElemento, conjunto)==True) {
        printf("maxMinDoConjunto2: maior = %d, menor = %d\n", maiorElemento, menorElemento);
    } else {
        printf("erro na busca\n");
    }

    imprimeConjunto(conjunto);

    return 0;
}
