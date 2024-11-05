#include "conjunto.h"
#include <stdio.h>

static int tamanhoDoConjunto = 0;

void fazConjuntoVazio(ConjuntoDeInteiros conjunto){
    tamanhoDoConjunto = 0;
}

void imprimeConjunto(ConjuntoDeInteiros conjunto) {
    printf("{ ");
    for (int i=0; i < tamanhoDoConjunto; i++){
        printf("%d", conjunto[i]);
        if (i < tamanhoDoConjunto - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

int pertenceAoConjunto(int number, ConjuntoDeInteiros conjunto){
    for (int i=0; i < tamanhoDoConjunto; i++){
        if (number == conjunto[i]){
            return True;
        }
    }
    return False;
}

int inserirNoConjunto(int number, ConjuntoDeInteiros conjunto){
    if (tamanhoDoConjunto >= MAX_SIZE){
        printf("Erro ao inserir no conjuto: Tamanho máximo atingido\n");
        return False;
    } else if (pertenceAoConjunto(number, conjunto) == True){
        printf("Erro ao inserir no conjuto: %d já pertence ao conjunto\n", number);
        return False;
    } else {
        conjunto[tamanhoDoConjunto] = number;
        tamanhoDoConjunto++;
        printf("Sucesso ao inserir o número %d\n", number);
        return True;
    }
}

int retiraDoConjunto(int number, ConjuntoDeInteiros conjunto){
    if (tamanhoDoConjunto <= 0){
        printf("Erro ao remover do conjuto: O conjunto está vazio\n");
        return False;
    } else if (pertenceAoConjunto(number, conjunto) == False){
        printf("Erro ao remover do conjuto: %d não pertence ao conjunto\n", number);
        return False;
    }
    else {
        for (int i=0; i < tamanhoDoConjunto; i++){
            if (conjunto[i] == number){
                for (int j=i; j < tamanhoDoConjunto-1; j++){
                    conjunto[j] = conjunto[j+1];
                }
                break;
            }
        }
        tamanhoDoConjunto--;
        printf("Sucesso ao remover o número %d\n", number);
        return True;
    }
}

int maxDoConjunto(int *maiorElemento, ConjuntoDeInteiros conjunto){
    if (tamanhoDoConjunto == 0) return False;
    else {
        *maiorElemento = conjunto[0];
        for (int i=1; i < tamanhoDoConjunto; i++){
            if (conjunto[i] > *maiorElemento){
                *maiorElemento = conjunto[i];
            }
        }
        return True;
    }
}

int maxMinDoConjunto(int *maiorElemento, int *menorElemento, ConjuntoDeInteiros conjunto){
    if (tamanhoDoConjunto == 0) return False;
    else {
        *maiorElemento = conjunto[0];
        *menorElemento = conjunto[0];
        for (int i=1; i < tamanhoDoConjunto; i++){
            if (conjunto[i] > *maiorElemento){
                *maiorElemento = conjunto[i];
            } else if (conjunto[i] < *menorElemento){
                *menorElemento = conjunto[i];
            }
        }
        return True;
    }
}

int maxMinDoConjunto2(int *maiorElemento, int *menorElemento, ConjuntoDeInteiros conjunto){
    if (tamanhoDoConjunto == 0) return False;

    int i, FimDoAnel;

    if ((tamanhoDoConjunto & 1) > 0) {
        conjunto[tamanhoDoConjunto] = conjunto[tamanhoDoConjunto - 1];
        FimDoAnel = tamanhoDoConjunto;
    } else {
        FimDoAnel = tamanhoDoConjunto - 1;
    }
    if (conjunto[0] > conjunto[1]) {
        *maiorElemento = conjunto[0];
        *menorElemento = conjunto[1];
    } else {
        *maiorElemento = conjunto[1];
        *menorElemento = conjunto[0];
    }

    i = 2;
    while (i <= FimDoAnel) {
        if (conjunto[i - 1] > conjunto[i]) {
            if (conjunto[i - 1] > *maiorElemento) {
                *maiorElemento = conjunto[i - 1];
            }
            if (conjunto[i] < *menorElemento) {
                *menorElemento = conjunto[i];
            }
        } else {
            if (conjunto[i] > *maiorElemento) {
                *maiorElemento = conjunto[i];
            }
            if (conjunto[i - 1] < *menorElemento) {
                *menorElemento = conjunto[i - 1];
            }
        }
        i += 2;
    }
    return True;
}
