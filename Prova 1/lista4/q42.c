#include <stdio.h>
#include <stdlib.h>

//void qsort(void* vet, int nelem, int tam_bytes, int (*cmp) (const void *, const void *));

typedef struct candidato
{
    int num_insc;
    float nota;
} TCAND;

int cmp(const void *x, const void *y);

TCAND *inicializa(int num, int nota)
{
    TCAND *resp = (TCAND *)malloc(sizeof(TCAND));
    resp->num_insc = num;
    resp->nota = nota;
    return resp;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n > 0)
    {
        TCAND **vet;
        vet = (TCAND **)malloc(sizeof(TCAND*)*n);
        int i;

        for (i = 0; i < n; i++) //scanf("%d%f", &vet[i].num_insc, &vet[i].nota);
        {
            vet[i] = inicializa(1+i, 2+i);        
        }
        for (i = 0; i < n; i++)
            printf("%d: %f\n", vet[i]->num_insc, vet[i]->nota);
        printf("Depois da ordenacao...\n");
        qsort(vet, n, sizeof(TCAND), cmp);
        for (i = 0; i < n; i++)
            printf("%d: %f\n", vet[i]->num_insc, vet[i]->nota);
    }
    return 0;
}

int cmp(const void *x, const void *y)
{    
    TCAND **px = (TCAND **)x, **py = (TCAND **)y;
    TCAND *a = (*px), *b = (*py);

    if (a->nota > b->nota)
        return -1;
    if (a->nota < b->nota)
        return 1;
    if (a->num_insc < b->num_insc)
        return -1;
    return 1;
}