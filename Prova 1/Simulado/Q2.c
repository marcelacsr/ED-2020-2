#include <stdio.h>
#include <stdlib.h>

int *axd(int *vet, int n, int x, int *tam)
{
    if (n <= 0)
        return 0;
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == x)
            cont = cont + 2;
        cont = cont + 1;
    }
    int *v = (int *)malloc((cont) * sizeof(int));
    v[0] = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == x)
        {
            v[j] = x - 1;
            v[j + 1] = x; //vet[i];
            v[j + 2] = x + 1;
            j = j + 2;
        }
        else
        {
            v[j] = vet[i];
        }
        j++;
    }
    *tam = cont;
    return v;
}

int main(void)
{
    while (1)
    {
        int n;
        scanf("%d", &n);
        if (n <= 0)
            return 0;
        int vet[n], x;
        int i;
        for (i = 0; i < n; i++)
            scanf("%d", &vet[i]);
        scanf("%d", &x);
        int nresp;
        int *resp = axd(vet, n, x, &nresp);
        for (i = 0; i < nresp; i++)
            printf("%d ", resp[i]);
        printf("\n");
        free(resp);
    }
}