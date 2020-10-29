#include <stdio.h>
#include <stdlib.h>

// Escreva uma função que, “infinitamente”, receba um vetor de inteiros vet, de tamanho n, e um inteiro x e que insira, no vetor de saída, antes e depois de cada elemento x do vetor original, o elemento x – 1 e o elemento x + 1, respectivamente.O VETOR DE SAÍDA DEVE POSSUIR O TAMANHO CORRETO, EM RELAÇÃO AO VETOR DE ENTRADA, ISTO É, A FUNÇÃO NÃO PODERÁ RETORNAR UM VETOR COM TAMANHO ADICIONAL NÃO UTILIZADO.O prótotipo deste método é o seguinte : int *axd(int *vet, int n, int x, int *tam).Seu programa para quando n ≤ 0

int *axd(int *vet, int n, int x, int *tam) // *tam conteudo de tam
{
    int i, j = 0;
    int cont = 0;
    for (i = 0; i < n; i++) //contar qual o tamanho do novo array
    {
        if (vet[i] == x)
            cont++;
    }
    int tam_total = n + (cont * 2); //contar qual o tamanho do novo array
    int *resp = (int *)malloc(sizeof(int) * (tam_total));
    *tam = tam_total; //mudar o conteudo do ponteiro tam, com o tamanho do novo array

    for (i = 0; i < n; i++)
    {
        if (vet[i] == x)
        {
            resp[j] = x - 1;
            resp[j + 1] = x;
            resp[j + 2] = x + 1;
            j = j + 2;
        }
        else
        {
            resp[j] = vet[i];
        }
        j++;
    }
    return resp;
}

int main(void)
{
    while (1)
    {
        int n, i;
        scanf("%d", &n);
        if (n <= 0)
            return 0;
        int vet[n];
        for (i = 0; i < n; i++)
            scanf("%d", &vet[i]);
        int x;
        scanf("%d", &x);
        int tam;
        int *resp = axd(vet, n, x, &tam); //passa o end de &tam
        for (i = 0; i < tam; i++) // conteudo de tam foi alterado dentro da funcao
            printf("%d ", resp[i]);
        free(resp);
    }
}
