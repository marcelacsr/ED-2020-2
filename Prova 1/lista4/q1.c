// Q1) Problema 1514

#include <stdio.h>
#include <stdlib.h>

int cond1(int *vetor, int size_vetor)
{
    int cont = 0;
    for (int i = 0; i < size_vetor; i++)
    {
        if (vetor[i] == 1)
        {
            cont++;
        }
    }
    if (cont == size_vetor)
        return 0;
    return 1;
}

int cond4(int *vetor, int size_vetor)
{
    int cont = 0;
    for (int i = 0; i < size_vetor; i++)
    {
        if (vetor[i] == 0)
        {
            cont++;
        }
    }
    if (cont == size_vetor)
        return 0;
    return 1;
}

int cond2(int *vetor, int size_vetor)
{
    int cont = 0;
    for (int i = 0; i < size_vetor; i++)
    {
        if (vetor[i] == 0)
        {
            cont++;
        }
    }
    if (cont == size_vetor)
        return 0;
    return 1;
}

int cond3(int *vetor, int size_vetor)
{
    int cont = 0;
    for (int i = 0; i < size_vetor; i++)
    {
        if (vetor[i] == 1)
        {
            cont++;
        }
    }
    if (cont == size_vetor)
        return 0;
    return 1;
}

int calcula_caracteristicas(int **matriz, int tam_linha, int tam_coluna)
{
    int caracteristicas[4] = {1, 1, 1, 1};
    for (int i = 0; i < tam_linha; i++)
    {
        int *participantes = (int *)malloc(sizeof(int) * tam_coluna);
        int *problemas = (int *)malloc(sizeof(int) * tam_linha);
        for (int j = 0; j < tam_coluna; j++)
        {
            problemas[j] = matriz[i][j]; // [0][0], [0][1], [0][2] linha
            participantes[j] = matriz[j][i];
        }

        if (cond1(participantes, tam_coluna) == 0)
        {
            caracteristicas[0] = 0;
        }
        if (cond4(participantes, tam_coluna) == 0)
        {
            caracteristicas[1] = 0;
        }
        if (cond2(problemas, tam_linha) == 0)
        {
            caracteristicas[2] = 0;
        }
        if (cond3(problemas, tam_linha) == 0)
        {
            caracteristicas[3] = 0;
        }
        free(participantes);
        free(problemas);
    }
    int qtd = 0;
    for (int i = 0; i < 4; i++)
    {
        if (caracteristicas[i])
            qtd++;
    }

    return qtd;
}

int main()
{
    int n, m;
    while (1)
    {
        printf("N (participantes): - M (problemas):\n");
        scanf("%d%d", &n, &m);
        if ((n < 3 || n > 100) && (m < 3 || m > 100))
            return 0;
        int i, j;
        int retorno;
        int **matriz;

        printf("\n 1: resolveu \n 0: nao resolveu\n");

        matriz = (int **)malloc(sizeof(int *) * n);
        for (i = 0; i < n; i++)
            matriz[i] = (int *)malloc(sizeof(int) * m);

        // int matriz[n][m];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
                scanf("%d", &matriz[i][j]);
        }
        //tam_linha = n - tam_coluna = m
        retorno = calcula_caracteristicas(matriz, n, m);
        printf("\nSaida: %d caracteristicas citadas foram alcancadas\n", retorno);
    }
}