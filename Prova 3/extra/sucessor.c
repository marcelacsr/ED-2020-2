#include "lib/TAB.h"

int sucessor(TAB *a, int x);
int maior(int esq, int dir);


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
                                     inserir(88, NULL, NULL),
                                     NULL)));

    printf("\n");
    imprimir(a);
    printf("\n");

    printf("61 -> %d\n", sucessor(a, 61));
    printf("34 -> %d\n", sucessor(a, 34));
    printf("78 -> %d\n", sucessor(a, 78));
    printf("87 -> %d\n", sucessor(a, 87));
    printf("88 -> %d\n", sucessor(a, 88));
    printf("15 -> %d\n", sucessor(a, 15));
    printf("64 -> %d\n", sucessor(a, 64));

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
    if (elem->dir && !elem->esq)
        return elem->dir->info;
    if (!elem->dir && elem->esq)
        return elem->esq->info;
    if (elem->dir && elem->esq)
    {
        //dir maior que esq
        if (maior(elem->esq->info, elem->dir->info))
            return elem->dir->info;
        else
            return elem->esq->info;
    }
    else
    {
        return elem->info; //elem eh o maior
    }
    return sucessor(a->esq, a->esq->info) && sucessor(a->dir, a->dir->info);
}

int maior(int esq, int dir)
{
    return esq < dir;
}