#include <stdlib.h>
#include <stdio.h>

typedef struct prod
{
  int cod;
  float preco, peso;
  struct prod *prox;
} TPROD;

typedef struct prat
{
  float peso_a, peso_t;
  TPROD *ini, *fim;
} TPRAT;

TPRAT *cria(float peso_total)
{
  TPRAT *prateleira = (TPRAT *)malloc(sizeof(TPRAT));
  prateleira->fim = prateleira->ini = NULL;
  prateleira->peso_a = 0;
  prateleira->peso_t = peso_total;
  return prateleira;
};

TPROD *retira(TPRAT *p)
{
  if (!p) //nao existe prateleira
    return NULL;
  if (!p->ini) //nao existe produto
    return NULL;
  TPROD *aux = p->ini;                  //para retornar apos retirar
  p->peso_a = p->peso_a - p->ini->peso; //modifica o peso na prateleira
  p->ini = p->ini->prox;                //faz apontar o inicio da fila para o prox
  if (!p->ini)                          // caso tenha apenas 1 produto
  {
    p->fim = NULL; // p->fim deixa de apontar para o produto para apontar para NULL, ja que nao ha mais produtos
  }
  return aux; //retorna o 1o produto
};

TPROD *busca(TPROD *l, int cod)
{
  TPROD *p = l;
  if (!p)
    return NULL;
  while (p)
  {
    if (p->cod == cod)
    {
      return p;
    }
    p = p->prox;
  }
  return NULL;
};

void imprime(TPRAT *p)
{
  TPROD *aux = p->ini;
  while (aux)
  {
    printf("\nCOD: %d peso: %f preco: %f\n", aux->cod, aux->peso, aux->preco);
    aux = aux->prox;
  }
  printf("\n Peso atual: %f - Peso max: %f\n", p->peso_a, p->peso_t);
}

void insere(TPRAT *p, int cod, float preco, float peso)
{
  if (!p)
    return; //exit(1);

  TPROD *aux = p->ini;

  while (aux) //busca e altera
  {
    if (aux->cod == cod)
    {
      if ((peso + p->peso_a - aux->peso) > p->peso_t)
        return;
      p->peso_a = p->peso_a - aux->peso; //remove o peso antigo da prateleira
      p->peso_a = p->peso_a + peso;      //adiciona o peso novo a prateleira
      aux->preco = preco;
      aux->peso = peso;
      return;
    }
    aux = aux->prox;
  }

  if ((peso + p->peso_a) > p->peso_t)
    return;

  if (p->ini == NULL && p->fim == NULL)
  { // nenhum elem
    TPROD *novo = (TPROD *)malloc(sizeof(TPROD));
    p->peso_a = p->peso_a + peso; //adiciona o peso novo a prateleira
    novo->cod = cod;
    novo->preco = preco;
    novo->peso = peso;
    p->fim = novo;
    p->ini = p->fim; //apenas 1 elemento
    return;
  }

  TPROD *novo = (TPROD *)malloc(sizeof(TPROD));
  p->peso_a = p->peso_a + peso; //adiciona o peso novo a prateleira
  novo->cod = cod;
  novo->preco = preco;
  novo->peso = peso;
  p->fim->prox = novo;
  p->fim = novo;
  return;
};

int main(void)
{
  int n = 10;
  TPRAT *p = cria(n);
  for (int i = 1; i <= n; i++)
  {
    insere(p, i, i, i);
  }
  printf("Altera 3\n");
  insere(p, 3, 1, 2);
  imprime(p);
  printf("\nRetira\n");
  retira(p);
  imprime(p);
  printf("\nRetira\n");
  retira(p);
  imprime(p);
  printf("\nInsere 5\n");
  insere(p, 5, 1, 1);
  imprime(p);
}