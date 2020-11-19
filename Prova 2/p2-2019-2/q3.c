#include <stdlib.h>
#include <stdio.h>

#include "lib/tlde.h"

int eh_mult(int x, int n)
{
    if (x % n == 0)
        return 1;
    else
        return 0;
}

//p12019.1 q3 LISTA DUPLA
// REMOVER os que NAO sao multiplos de n
void remove_multiplo_n_d(TLDE *l, int n)
{
    TLDE *p = l, *aux = NULL;
    if (!l)
        return;
    while (p)
    { // sem usar lista auxiliar
        if (!eh_mult(p->info, n))
        {
            if (p == l)
                l = l->prox;
            else
                p->ant->prox = p->prox;
            if (p->prox)
                p->prox->ant = p->ant;
            aux = p;
            p = aux->ant;
            free(aux);
        }
        else
            p = p->prox;
    }
}

int main(void)
{
    TLDE *ld = inicializa();
    ld = insere_ini_dupla(ld, 3);
    ld = insere_ini_dupla(ld, 12);
    ld = insere_ini_dupla(ld, 3);
    ld = insere_ini_dupla(ld, 2);
    ld = insere_ini_dupla(ld, 2);
    ld = insere_ini_dupla(ld, 3);
    imprime(ld);
    printf("\ndupla\n");
    remove_multiplo_n_d(ld, 3);
    imprime(ld);
    printf("\n");
}
