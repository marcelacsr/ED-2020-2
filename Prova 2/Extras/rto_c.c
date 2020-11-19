#include <stdlib.h>
#include <stdio.h>

#include "lib/tlse.h"
TLSE *rto(TLSE *l, int x)
{
    TLSE *p = l->prox, *ant = l, *t = NULL;
    if (!l)
        return l;

    while (p != l)
    {
        ant = p;
        p = p->prox;
    } // posiciona os ponteiros
    while (1)
    {
        while (p->info != x)
        {
            ant = p;
            p = p->prox;
            if (p == l)
                return l;
        }
        if (p == l)
            l = l->prox;
        if ((l->prox == l) && (l->info == x))
        {
            free(l);
            return NULL;
        }
        ant->prox = p->prox;
        free(p);
        p = ant->prox;
    }
}

int main(void)
{
    TLSE *l = inicializa();
    l = insere_circular(l, 2);// buga
    l = insere_circular(l, 2);
    l = insere_circular(l, 2);
    l = insere_circular(l, 3);
    l = insere_circular(l, 4);
    l = insere_circular(l, 2);
    l = insere_circular(l, 6);
    l = insere_circular(l, 2);
    l = insere_circular(l, 2);
    imprime_circular(l);
    l=rto(l, 2);
    imprime_circular(l);
}