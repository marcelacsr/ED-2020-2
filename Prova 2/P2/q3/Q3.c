#include "TLSE.c"

void misc(TLSE *l, int n)
{
  TLSE *p = l, *nova, *del, *aux = NULL;
  if (!p)
    return;
  while (p)
  {
    if (p->info == n)
    {
      nova = NULL;
      // remover n elem DPS
      for (int i = 0; i < n; i++)
      {
        del = p->prox;
        if (del)
        {
          p->prox = p->prox->prox;
          free(del);
        }
      }
      //add n elem ANTES
      for (int i = 0; i < n; i++)
      {
        nova = TLSE_insere(nova, n); // 2 2
      }
        aux=p->prox;
        p->prox = nova;
        while (nova->prox)
          nova = nova->prox;
        nova->prox = aux;
        p = nova; //IMP!
    }
    p = p->prox;
  }
}

int main(void)
{
  TLSE *l = NULL;
  int n;
  // do{
  //   scanf("%d", &n);
  //   if(n < 0) break;
  //   l = TLSE_insere(l, n);
  // }while(1);
  l = TLSE_insere(l, 2);
  l = TLSE_insere(l, 1);
  l = TLSE_insere(l, 5);
  l = TLSE_insere(l, 2);
  l = TLSE_insere(l, 3);
  l = TLSE_insere(l, 4);
  l = TLSE_insere(l, 2);

  // scanf("%d", &n);
  TLSE_imprime(l);
  printf("\n");
  misc(l, 1);
  TLSE_imprime(l);
  printf("\n");

  TLSE_libera(l);
  return 0;
}
