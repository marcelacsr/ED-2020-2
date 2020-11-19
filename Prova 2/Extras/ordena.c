#include <stdlib.h>
#include <stdio.h>

#include "lib/tlse.h"

int conta(TLSE *l)
{
    if (!l)
        return 0;
    return 1 + conta(l->prox);
}

int compara(const void *x, const void *y)
{
    TLSE **px = (TLSE **)x, **py = (TLSE **)y;
    TLSE *a = (*px), *b = (*py);
    if (a->info < b->info)
        return -1;
    if (a->info > b->info)
        return 1;
    return 0;
}

void ordena(TLSE *l)
{
    int n = conta(l), i = 0;
    TLSE *p = l, *vet[n];
    if (!p)
        return;
    while (p)
    {
        vet[i++] = p;
        p = p->prox;
    }
    qsort(vet, n, sizeof(TLSE *), compara);
    p = l;
    for (i = 0; i < n; i++)
    {
        p->info = vet[i]->info;
        if (i == (n - 1))
            p->prox = NULL;
        else
            p->prox = vet[i + 1];
        p = p->prox;
    }
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
    ordena(l);
    imprime(l);
}