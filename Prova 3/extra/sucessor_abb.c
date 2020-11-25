#include "lib/TABB.h"

int sucessor(TABB *a, int x);

int main(int argc, char const *argv[])
{
    TABB *a = criar();
    a = TABB_insere(a, 61);
    a = TABB_insere(a, 34);
    a = TABB_insere(a, 78);
    a = TABB_insere(a, 19);
    a = TABB_insere(a, 47);
    a = TABB_insere(a, 64);
    a = TABB_insere(a, 87);
    a = TABB_insere(a, 15);
    a = TABB_insere(a, 29);
    a = TABB_insere(a, 42);
    a = TABB_insere(a, 53);
    a = TABB_insere(a, 76);
    a = TABB_insere(a, 84);

    printf("\n");
    TABB_imprime(a);
    printf("\n");

    printf("61 -> %d\n", sucessor(a, 61));
    printf("34 -> %d\n", sucessor(a, 34));
    printf("78 -> %d\n", sucessor(a, 78));
    printf("87 -> %d\n", sucessor(a, 87));
    printf("84 -> %d\n", sucessor(a, 84));
    printf("15 -> %d\n", sucessor(a, 15));

    TABB_libera(a);
    return 0;
}

int sucessor(TABB *a, int x)
{
    if (!a)
        return 0;
    if (!TABB_busca(x, a))
        return 0;
    TABB *elem = TABB_busca(x, a);
    if (elem->dir)
        return elem->dir->info;
    else
        return elem->info;
    return sucessor(a->esq, a->esq->info) && sucessor(a->dir, a->dir->info);
}