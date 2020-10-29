// Q4) Problema 1028

#include <stdio.h>
#include <stdlib.h>

int calcula_suspeito(int *v, int m)
{
    int i = 0, maior = 0;
    int penultimo=0;

    if (v[0] > v[1]) // caso o primeiro elem seja maior que o segundo
    {
        penultimo = 1; // recebe o ind 1 do segundo elem
        maior = 0;     //recebe o ind do primeiro elem
        i = 2;
    }

    for (i; i < m; i++)
    {
        if (v[maior] < v[i])
        {
            penultimo = maior; //penultimo recebe o indice do maior
            maior = i;         //maior recebe o indice do novo maior
        }
        else if (v[penultimo] < v[i]) //compara a segunda posicao com a atual
        {
            penultimo = i;
        }
    }
    return penultimo + 1;
}

int main()
{
    int n;
    while (1)
    {
        printf("casos de teste:\n");
        scanf("%d", &n);
        if (n < 2 || n > 1000)
            return 0;
        int i;
        int retorno;
        int v[n];
        for (i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
            if ((v[i] < 1) || (v[i] >= 10000))
                return 0;
        }
        retorno = calcula_suspeito(v, n);
        printf("\nSaida: %d \n", retorno);
    }
}
