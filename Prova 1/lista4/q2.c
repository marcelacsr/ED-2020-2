// Q1) Problema 1127

#include <stdio.h>
#include <stdlib.h>

int calcula_qtd_vezes(int *vetor, int tam, int valor)
{
    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] == valor)
        {
            cont++;
        }
    }

    return cont;
}

int ordena_vetor(int *vetor, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        int j, menor = i;
        for (j = i + 1; j < tam; j++)
            if (vetor[j] < vetor[menor])
                menor = j;
        if (menor != i)
        {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

int main()
{
    int n;
    while (1)
    {
        printf("Qtd de valores:\n");
        scanf("%d", &n);
        if (n < 1 || n > 2000)
            return 0;
        int v[n];
        int retorno;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
        }

        ordena_vetor(v, n);

        for (int j = 0; j < n; j++)
        {
            retorno = calcula_qtd_vezes(v, n, v[j]);
            if (v[j] != v[j + 1])
                printf(" %d aparece %d vez(es)\n", v[j], retorno);
        }
    }
    return 0;
}