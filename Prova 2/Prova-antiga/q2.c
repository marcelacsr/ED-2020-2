#include <stdlib.h>
#include <stdio.h>

#include "lib/TF.h"
// 2-A
// (a) Implemente uma função que receba três filas, f, impares e pares (as duas últimas estão
// vazias), e separe todos os valores guardados em f de tal forma que os valores pares são
// colocados na fila pares e os valores ímpares na impares. Ao final da execução desta função,
// f permanecerá com todos os seus elementos, e as filas impares e pares estarão com os
// elementos invertidos em relação a f. O protótipo desta função é o seguinte: void
// inverte_filas(TFila* f, TFila* pares, TFila* impares).
void inverte_filas(TF *f, TF *p, TF *i)
{
    TF *aux = TF_inicializa();
    if (!f)
        return;
    while (!TF_vazia(f))
    {
        int x = TF_retira(f);
        if (x % 2 == 0)
            TF_insere(p, x);
        else
            TF_insere(i, x);
        TF_insere(aux, x);
    }
    while (!TF_vazia(aux))
    {
        TF_insere(f, TF_retira(aux));
    }
    TF_libera(aux);
}

int main(void)
{
    TF *l = TF_inicializa();
    TF *p = TF_inicializa();
    TF *i = TF_inicializa();
    TF_insere(l, 1);

    TF_insere(l, 2);
    TF_insere(l, 2);
    TF_insere(l, 7);

    TF_insere(l, 11);
    TF_insere(l, 13);
    TF_insere(l, 17);

    TF_insere(l, 19);
    TF_insere(l, 2);
    TF_insere(l, 21);

    TF_insere(l, 22);
    TF_insere(l, 23);
    TF_insere(l, 24);
    TF_insere(l, 2);
    TF_insere(l, 2);
    TF_imprime(l);
    inverte_filas(l, p, i);
    printf("\n original: ");
    TF_imprime(l);
    printf("\n par: ");
    TF_imprime(p);
    printf("\n impar: ");
    TF_imprime(i);
}