// Q4) Problema 1028

#include <stdio.h>
#include <stdlib.h>

int existe_elemento(int *vetor, int size_vetor, int valor)
{
    for (int i = 0; i < size_vetor; i++)
    {
        if (vetor[i] == valor)
        {
            return 1;
        }
    }
    return 0;
}

int calcula_bilhetes(int *bilhetes, int qtd_bilhetes)
{
    int i, j, size_vetor = 0;
    //cria vet vazio
    int *b_falsos = (int*) malloc(sizeof(int));

    for (i = 0; i < qtd_bilhetes; i++)
    {
        for (j = i + 1; j <= qtd_bilhetes - 1; j++)
        {
            if (bilhetes[i] == bilhetes[j])
            {
                if (!(existe_elemento(b_falsos, size_vetor, bilhetes[i])))
                {
                    size_vetor++;
                    b_falsos = (int*) realloc(b_falsos, size_vetor * (sizeof(int)));
                    b_falsos[size_vetor - 1] = bilhetes[i];
                }
            }
        }
    }
    free(b_falsos);
    return size_vetor;
}

int main()
{
    int n, m;
    while (1)
    {
        printf("casos de teste:\n");
        scanf("%d%d", &n, &m);
        if ((n <= 0 || n > 10000) && (m <= 0 || m > 20000))
            return 0;
        int i;
        int retorno;

        printf("digite os bilhetes:  ");
        int vet[m];
        for (i = 0; i < m; i++)
        {
            scanf("%d", &vet[i]);
        }
        retorno = calcula_bilhetes(vet, m);
        printf("\nSaida: %d bilhetes foram falsificados\n", retorno);
    }
}