// Q3)
#include <stdio.h>
#include <stdlib.h>

//void qsort(void* vet, int nelem, int tam_bytes, int (*cmp) (const void *, const void *));

typedef struct data
{
    int mes, ano;
} TDATA;

typedef struct produto
{
    int cod;
    int peso, preco;
    TDATA *validade;
} TPRODUTO;

TPRODUTO *inicializa(int ano, int mes, int cod, int peso, int preco)
{
    TPRODUTO *resp = (TPRODUTO *)malloc(sizeof(TPRODUTO));
    resp->validade = (TDATA *)malloc(sizeof(TDATA));
    resp->validade->ano = ano;
    resp->validade->mes = mes;
    resp->cod = cod;
    resp->peso = peso;
    resp->preco = preco;
    return resp;
}

int cmp(const void *x, const void *y);
int ordena1(TPRODUTO **prat, int n);

int main(void)
{
    int n = 10;
    TPRODUTO *vet[n];
    int i;
    vet[0] = inicializa(2021, 12, 3, 12, 3);
    vet[1] = inicializa(2022, 4, 3, 2, 109);
    vet[2] = inicializa(2021, 12, 4, 22, 99);
    vet[3] = inicializa(2022, 5, 5, 32, 89);
    vet[4] = inicializa(2023, 7, 6, 2, 79);
    vet[5] = inicializa(2023, 7, 6, 2, 59);
    vet[6] = inicializa(2024, 10, 10, 1, 4);
    vet[7] = inicializa(2020, 11, 11, 1, 2);
    vet[8] = inicializa(2020, 12, 7, 1, 1);
    vet[9] = inicializa(2020, 2, 7, 1, 1);

    for (i = 0; i < n; i++)
    {
        printf("\ncod[%d] peso: %d preco: %d\n", vet[i]->cod, vet[i]->peso, vet[i]->preco);
        printf(" -> validade: %d/%d\n", vet[i]->validade->mes, vet[i]->validade->ano);
    }
    printf("\nDepois da ordenacao...\n");

    // qsort(vet, n, sizeof(TPRODUTO), ordena1);
    ordena1(vet, n);

    for (i = 0; i < n; i++)
    {
        printf("\ncod[%d] peso: %d preco: %d\n", vet[i]->cod, vet[i]->peso, vet[i]->preco);
        printf(" -> validade: %d/%d\n", vet[i]->validade->mes, vet[i]->validade->ano);
    }
    return 0;
}

int ordena1(TPRODUTO **prat, int n)
{
    qsort(prat, n, sizeof(TPRODUTO *), cmp);
}

int cmp(const void *x, const void *y)
{
    TPRODUTO **px = (TPRODUTO **)x, **py = (TPRODUTO **)y;
    TPRODUTO *a = (*px), *b = (*py);

    if (a->cod < b->cod)
        return -1;
    if (a->cod > b->cod)
        return 1;
    if (a->cod == b->cod)
    {
        if (a->validade->ano < b->validade->ano)
            return -1;
        if (a->validade->ano > b->validade->ano)
            return 1;
        if (a->validade->ano == b->validade->ano)
        {
            if (a->validade->mes < b->validade->mes)
                return -1;
            if (a->validade->mes > b->validade->mes)
                return 1;
            if (a->validade->mes == b->validade->mes)
            {
                if (a->preco < b->preco)
                    return 1;
                if (a->preco > b->preco)
                    return -1;
            }
        }
    }
    return 0;
}
