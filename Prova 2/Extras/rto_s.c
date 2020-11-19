#include <stdlib.h>
#include <stdio.h>

#include "lib/tlse.h"

TLSE *rto(TLSE *l, int x)
{
    TLSE *p = l, *ant = NULL, *t = NULL;
    if (!l)
        return l;
    while (p)
    {
        while ((p) && (p->info != x))
        {
            ant = p;
            p = p->prox;
        }
        if (!p)
            return l;
        if (!ant)
            l = l->prox;
        else
            ant->prox = p->prox;
        t = p;
        p = p->prox;
        free(t);
    }
    return l;
}

int main(void)
{
    TLSE *l = inicializa();
    l = insere_ini(l, 1);

    l = insere_ini(l, 2);
    l = insere_ini(l, 2);
    l = insere_ini(l, 7);

    l = insere_ini(l, 11);
    l = insere_ini(l, 13);
    l = insere_ini(l, 17);

    l = insere_ini(l, 19);
    l = insere_ini(l, 2);
    l = insere_ini(l, 21);

    l = insere_ini(l, 22);
    l = insere_ini(l, 23);
    l = insere_ini(l, 24);
    l = insere_ini(l, 2);
    l = insere_ini(l, 2);
    imprime(l);
    l = rto(l, 2);
    imprime(l);
}