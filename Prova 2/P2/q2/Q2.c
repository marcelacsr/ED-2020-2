#include "TLDE.c"

void cross(TLDE *l1, TLDE *l2, int x)
{
  TLDE *p1 = l1, *p2 = l2, *aux2 = NULL, *aux1 = NULL;
  if (!l1 || !l2)
    return;
  while (p1->prox || p2->prox)
  {
    while (p1 && p1->prox && (p1->info != x))
      p1 = p1->prox;
    while (p2 && p2->prox && (p2->info != x))
      p2 = p2->prox;
    // p1 e p2 estao em x
    aux2 = p2->prox;
    aux1 = p1->prox;    
    p2->prox = aux1;
    p1->prox = aux2;
    if (p1->prox) p1 = p1->prox;
    if (p2->prox) p2 = p2->prox;
  }
  return;
}

int main(void)
{
  int x;
  TLDE *l1 = NULL;
  // do{
  //   scanf("%d", &x);
  //   if(x < 0) break;
  //   l1 = TLDE_insere(l1, x);
  // }while(1);
  // l1 = TLDE_insere(l1, 5);
  l1 = TLDE_insere(l1, 1);
  l1 = TLDE_insere(l1, 3);
  l1 = TLDE_insere(l1, 1);
    l1 = TLDE_insere(l1, 5);
  l1 = TLDE_insere(l1, 3);
  l1 = TLDE_insere(l1, 2);
  l1 = TLDE_insere(l1, 1);

  TLDE *l2 = NULL;
  // do{
  //   scanf("%d", &x);
  //   if(x < 0) break;
  //   l2 = TLDE_insere(l2, x);
  // }while(1);

  // l2 = TLDE_insere(l2, 1);
  l2 = TLDE_insere(l2, 0);
  l2 = TLDE_insere(l2, 1);
  l2 = TLDE_insere(l2, 2);
  l2 = TLDE_insere(l2, 1);

  TLDE_imprime(l1);
  printf("\n");
  TLDE_imprime(l2);
  printf("\n");
  // scanf("%d", &x);
  cross(l1, l2, 1);
  TLDE_imprime(l1);
  printf("\n");
  TLDE_imprime(l2);
  printf("\n");

  TLDE_libera(l1);
  TLDE_libera(l2);
  return 0;
}
