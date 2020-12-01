#include <stdio.h>
#include <stdlib.h>
#include "TH.h"

int esq(int ind)
{
  return (ind * 2 + 1);
}

int dir(int ind)
{
  return (ind * 2 + 2);
}

int pai(int ind)
{
  if (ind)
    return (ind - 1) / 2;
  return -1;
}
// min_heapfy
void min_heapfy(int *vet, int n, int ind)
{
  int e = esq(ind), d = dir(ind), menor = ind;
  if (e < n && vet[e] < vet[ind])
    menor = e;
  if (d < n && vet[d] < vet[menor])
    menor = d;
  if (menor != ind)
  {
    int temp = vet[ind];
    vet[ind] = vet[menor];
    vet[menor] = temp;
    min_heapfy(vet, n, menor);
  }
}

void build_min_heap(int *v, int n)
{
  int i, ultimo_pai = pai(n - 1);
  for (i = ultimo_pai; i >= 0; i--)
    min_heapfy(v, n, i);
}
//------

// max_heapfy
void max_heapfy(int *vet, int n, int ind)
{
  int e = esq(ind), d = dir(ind), maior = ind;
  if (e < n && vet[e] > vet[ind])
    maior = e;
  if (d < n && vet[d] > vet[maior])
    maior = d;
  if (maior != ind)
  {
    int temp = vet[ind];
    vet[ind] = vet[maior];
    vet[maior] = temp;
    max_heapfy(vet, n, maior);
  }
}

void build_max_heap(int *v, int n)
{
  int i, ultimo_pai = pai(n - 1);
  for (i = ultimo_pai; i >= 0; i--)
    max_heapfy(v, n, i);
}
//-----
void heapsort(int *v, int n)
{
  int i;
  build_max_heap(v, n);
  // build_min_heap(v, n);
  for (i = n - 1; i >= 1; i--)
  {
    int temp = v[i];
    v[i] = v[0];
    v[0] = temp;
    max_heapfy(v, i, 0);
    // min_heapfy(v, i, 0); 
  }
}

int main(void)
{
  int *vet, n, i = 0;
  // printf("Digite o tamanho do vetor de elementos a serem ordenados... ");
  // scanf("%d", &n);
  n = 15;
  if (n <= 0)
    return 0;
  vet = (int *)malloc(sizeof(int) * n);

  for (i = 0; i < n; i++)
    vet[i] = rand() % n;

  printf("Antes de ordenar com heapsort...\n");
  for (i = 0; i < n; i++)
    printf("%d ", vet[i]);
  printf("\n");

  heapsort(vet, n);

  printf("Depois de ordenar com heapsort...\n");
  for (i = 0; i < n; i++)
    printf("%d ", vet[i]);
  printf("\n");

  free(vet);
// ----------------------------
  n = 5;
  int m = 5;
  if ((n <= 1) || (m <= 1))
    return 0;

  TH tab;
  TH_inicializa(tab, m);
  i = 0;
  int mat;
  float cr;
  for (i = 0; i < n; i++)
  {
    printf("Digite a matricula e o cr...\n");
    scanf("%d", &mat);
    scanf("%f", &cr);
    TH_insere(tab, m, mat, cr);
  }
  TH_imprime(tab, m);

  char resp;
  do
  {
    printf("Digite a matricula a ser removida... ");
    scanf("%d", &mat);
    cr = TH_retira(tab, m, mat);
    if (cr != -1)
      printf("%d\t%f saiu\n", mat, cr);
    printf("Quer continuar? ");
    scanf(" %c", &resp);
  } while ((resp != 'N') && (resp != 'n'));
  TH_imprime(tab, m);

  do
  {
    printf("Digite a matricula a ser procurada... ");
    scanf("%d", &mat);
    TA *p = TH_busca(tab, m, mat);
    if (!p)
      printf("Elemento nao encontrado!\n");
    else
      printf("%d\t%f\n", p->mat, p->cr);
    printf("Quer continuar? ");
    scanf(" %c", &resp);
  } while ((resp != 'N') && (resp != 'n'));
  TH_imprime(tab, m);

  for (i = 0; i < n / 2; i++)
  {
    printf("Digite a matricula e o cr...\n");
    scanf("%d", &mat);
    scanf("%f", &cr);
    TH_insere(tab, m, mat, cr);
  }
  TH_imprime(tab, m);
  TH_libera(tab, m);

  return 0;
}
