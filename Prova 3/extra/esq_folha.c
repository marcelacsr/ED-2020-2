#include "lib/TAB.h"

int esq_folha(TAB *a);
int esq_folha_raiz(TAB *a);

int main(int argc, char const *argv[])
{
    TAB *a = inserir(61, inserir(84, NULL, NULL), inserir(88, inserir(83, NULL, NULL), inserir(90, inserir(82, NULL, NULL), NULL)));

    printf("\n");
    imprimir(a);
    printf("\n");

    if (esq_folha(a))
    {
        printf("eh esq_folha\n");
    }
    else
    {
        printf("nao eh esq_folha\n");
    }

    liberar(a);

    return 0;
}

// int esq_folha_raiz(TAB *a)
// {
//     if (!a)
//         return 1;
//     return esq_folha(a->esq) && esq_folha(a->dir); // testa a esq e dir da raiz
// }

int esq_folha(TAB *a)
{
    if (!a)
        return 1;
    if ((!a->esq->esq && !a->esq->dir))
        return 1; 
    else
        return 0;
    return esq_folha(a->dir);
}