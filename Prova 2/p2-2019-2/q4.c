#include <stdlib.h>
#include <stdio.h>

#include "lib/tlse.h"

int eh_mult(int x, int n)
{
    if (x % n == 0)
        return 1;
    else
        return 0;
}

//p12019.1 q4 LISTA CIRCULAR
void remove_multiplo_n_cir(TLSE *l, int n)
{
    if (!l)
        return;
    TLSE *p = l->prox, *aux = NULL, *ant = l;
    while (p != l)
    {
        if (!eh_mult(p->info, n))
        {
            ant->prox = p->prox;
            free(p);
            p = ant->prox;
        }
        else
        {
            ant = p;
            p = p->prox;
        }

        if ((p == l) && !eh_mult(p->info, n))
        {
            int temp = p->info;
            p->info = p->prox->info;
            p->prox->info = temp;
            aux = p->prox;
            p->prox = aux->prox;
            free(aux);
        }
    }
}
//p12019.1 LISTA SIMPLES
void remove_multiplo_n(TLSE *l, int n)
{
    TLSE *p = l, *aux = NULL, *ant = NULL;
    while (p)
    {
        if (!eh_mult(p->info, n))
        {
            if (p->prox)
            {
                int temp = p->info;
                p->info = p->prox->info;
                p->prox->info = temp;
                aux = p->prox;
                p->prox = aux->prox;
                free(aux);
            }
            else
            {
                ant->prox = p->prox;
                free(p);
            }
        }
        if (eh_mult(l->info, n))
        {
            ant = p;
            p = p->prox;
        }
    }
}

//p12019.2 q2
void remove_x(TLSE *l, int x)
{
    TLSE *p = l, *ant = NULL, *del = NULL;
    if (!p)
        return;
    while (p)
    {
        if ((p->info == x) && (p->prox) && (ant))
        {
            int temp = p->info;
            p->info = ant->info;
            ant->info = temp;
            del = p;
            p = p->prox->prox;
            ant->prox = p;
            free(del->prox);
            free(del);
        }
        ant = p;
        p = p->prox;
    }
}

int main(void)
{
    TLSE *l = inicializa();
    l = insere_circular(l, 4);
    l = insere_circular(l, 2);
    l = insere_circular(l, 3);
    l = insere_circular(l, 4);
    l = insere_circular(l, 5);
    l = insere_circular(l, 6);
    l = insere_circular(l, 7);
    l = insere_circular(l, 4);
    printf(" lista circular: ");
    imprime_circular(l);
    printf(" removendo nao multiplos de 2: \n");
    remove_multiplo_n_cir(l, 2);
    imprime_circular(l);

    printf("\n");
    TLSE *list = inicializa();
    list = insere_ini(list, 4);
    list = insere_ini(list, 2);
    list = insere_ini(list, 3);
    list = insere_ini(list, 4);
    list = insere_ini(list, 5);
    list = insere_ini(list, 6);
    list = insere_ini(list, 7);
    list = insere_ini(list, 4);
    printf(" lista simples: ");
    imprime(list);
    printf(" removendo nao multiplos de 2: \n");
    remove_multiplo_n(list, 2);
    imprime(list);
}
