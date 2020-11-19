#include <stdlib.h>
#include <stdio.h>

#include "lib/TF.h"

void separa_fila_par_impar(TF *f, TF *p, TF *i)
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
    separa_fila_par_impar(l, p, i);
    printf("\n original: ");
    TF_imprime(l);
    printf("\n par: ");
    TF_imprime(p);
    printf("\n impar: ");
    TF_imprime(i);
}