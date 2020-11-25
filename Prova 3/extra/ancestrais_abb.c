// Ancestrais

#include "lib/TABB.h"
#include "lib/tlse.h"

TLSE *ancestrais(TABB *a, int x);
TLSE *ancestrais_com_elemento(TABB *a, int x);

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

    printf("Original:\n");
    TABB_imprime(a);
    printf("\n");

    TLSE *anc = ancestrais(a, 42);
    printf("Ancestrais: 42\n");
    imprime(anc);
    printf("\n");

    TLSE *anc2 = ancestrais(a, 53);
    printf("Ancestrais: 53\n");
    imprime(anc2);
    printf("\n");

    TLSE *anc3 = ancestrais_com_elemento(a, 42);
    printf("Ancestrais com: 42\n");
    imprime(anc3);
    printf("\n");

    TLSE *anc4 = ancestrais_com_elemento(a, 53);
    printf("Ancestrais com: 53\n");
    imprime(anc4);
    printf("\n");

    TABB_libera(a);
    return 0;
}

TLSE *ancestrais(TABB *a, int x)
{
    if (!a)
        return NULL;
    if (!TABB_busca(x, a))
        return NULL;
    TLSE *l = inicializa();
    TABB *aux = a;
    while (aux->info != x)
    {
        l = insere_ini(l, aux->info);
        if (aux->info < x)
            aux = aux->dir;
        if (aux->info > x)
            aux = aux->esq;
    }
    return l;
}

TLSE *ancestrais_com_elemento(TABB *a, int x)
{
    if (!a)
        return NULL;
    if (!TABB_busca(x, a))
        return NULL;
    TLSE *l = inicializa();
    TABB *aux = a;
    while (aux->info != x)
    {
        l = insere_ini(l, aux->info);
        if (aux->info < x)
            aux = aux->dir;
        if (aux->info > x)
            aux = aux->esq;
    }
    l = insere_ini(l, x);
    return l;
}