#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void qsort(void* vet, int n, int tam_bytes, int (*cmp) (const void *, const void *));

typedef struct candidato
{
    int mat;
    float nota;
    char data_nasc[11];
} TC;

int cmp(const void *x, const void *y);
void ordena(TC **vet, int n);

int main(void){
  int n;
  scanf("%d", &n);
  if(n > 0){
    TC *vet[n];
    int i;
    for(i = 0; i < n; i++) vet[i] = (TC *) malloc(sizeof(TC *));
    for(i = 0; i < n; i++){
      scanf("%d%f", &vet[i]->mat, &vet[i]->nota);
      scanf(" %10[^\n]", vet[i]->data_nasc);
    }
    ordena(vet, n);
    for(i = 0; i < n; i++) printf("%d\n", vet[i]->mat);
    for(i = 0; i < n; i++) free(vet[i]);
  }
  return 0; 
}

void ordena(TC **vet, int n)
{
    qsort(vet, n, sizeof(TC *), cmp);
}

int cmp(const void *x, const void *y)
{
    TC **px = (TC **)x, **py = (TC **)y;
    TC *a = (*px), *b = (*py);

    char ano_a[5], ano_b[5], mes_a[3], mes_b[3], dia_a[3], dia_b[3];
    strncpy(ano_a, a->data_nasc + 6, 4);
    strncpy(ano_b, b->data_nasc + 6, 4);
    ano_a[4] = '\0';
    ano_b[4] = '\0';
    strncpy(mes_a, a->data_nasc + 3, 2);
    strncpy(mes_b, b->data_nasc + 3, 2);
    mes_a[2] = '\0';
    mes_b[2] = '\0';

    strncpy(dia_a, a->data_nasc, 2);
    strncpy(dia_b, b->data_nasc, 2);
    dia_a[2] = '\0';
    dia_b[2] = '\0';

    if (a->nota > b->nota)
    {
        return -1;
    }
    if (a->nota < b->nota)
    {
        return 1;
    }
    if (atoi(ano_a) < atoi(ano_b))
    {
        return -1;
    }
    if (atoi(ano_a) > atoi(ano_b))
    {
        return 1;
    }
    if (atoi(ano_a) == atoi(ano_b)) // ano igual
    {
        if (atoi(mes_a) < atoi(mes_b)) //mes
        {
            return -1;
        }
        if (atoi(mes_a) > atoi(mes_b)) //mes
        {
            return 1;
        }

        if (atoi(mes_a) == atoi(mes_b)) //ano e mes igual
        {
            if (atoi(dia_a) < atoi(dia_b)) //dia
            {
                return -1;
            }
            if (atoi(dia_a) > atoi(dia_b)) //dia
            {
                return 1;
            }
        }
    }
    if (a->mat < b->mat)
    {
        return -1;
    }
    return 1;
}