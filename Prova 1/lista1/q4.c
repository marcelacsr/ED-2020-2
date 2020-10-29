// Q4) Problema 1028

#include <stdio.h>

int calcula_tam_max_pilha(int f1, int f2)
{
    int div, i, maior;
    if (f1 > f2)
    {
        maior = f1;
    }
    if (f2 > f1)
    {
        maior = f2;
    }
    
    for (i = maior; i >= 1; i--)
    {
        if ((f1 % i == 0) && (f2 % i == 0))
        {
            return i;
            // printf("%d", i);
        }
    }

    // for (i = 1; i < maior; i++)
    // {
    //     if ((f1 % i == 0) && (f2 % i == 0))
    //     {
    //         div = i;
    //         // printf("%d", i);
    //     }
    // }
    // return div;
}

int main()
{
    int n;
    while (1)
    {
        printf("casos de teste:\n");
        scanf("%d", &n);
        if (n <= 0 || n > 3000)
            return 0;
        int i, f1, f2;
        int retorno;
        for (i = 0; i < n; i++)
        {
            printf("caso de teste [%d] -digite f1 e f2\n", i);
            scanf("%d %d", &f1, &f2);
            if (((f1 < 1) || (f1 >= 1000)) || ((f2 < 1) || (f2 >= 1000)))
                return 0;
            retorno = calcula_tam_max_pilha(f1, f2);
            printf("\nSaida: %d figurinhas em cada pilha\n", retorno);
        }
    }
}
