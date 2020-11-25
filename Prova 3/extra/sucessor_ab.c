#include "lib/TAB.h"

int sucessor(TAB *a, int x);

int main(int argc, char const *argv[])
{
    TAB *a = inserir(61,
                     inserir(34,
                             inserir(19,
                                     inserir(15, NULL, NULL),
                                     inserir(29, NULL, NULL)),
                             inserir(47,
                                     inserir(42, NULL, NULL),
                                     inserir(53, NULL, NULL))),
                     inserir(78,
                             inserir(64,
                                     NULL,
                                     inserir(76, NULL, NULL)),
                             inserir(87,
                                     inserir(84, NULL, NULL),
                                     NULL)));

    printf("\n");
    imprimir(a);
    printf("\n");

    printf("61 -> %d\n", sucessor(a, 61));
    printf("34 -> %d\n", sucessor(a, 34));
    printf("78 -> %d\n", sucessor(a, 78));
    printf("87 -> %d\n", sucessor(a, 87));
    printf("84 -> %d\n", sucessor(a, 84));
    printf("15 -> %d\n", sucessor(a, 15));

    liberar(a);
    return 0;
}

int sucessor(TAB *a, int x)
{
    if (!a)
        return 0;
    if (!TAB_busca(x, a))
        return 0;
    TAB *elem = TAB_busca(x, a);
    if (elem->dir)
        return elem->dir->info;
    else
        return elem->info;
    return sucessor(a->esq, a->esq->info) && sucessor(a->dir, a->dir->info);
}