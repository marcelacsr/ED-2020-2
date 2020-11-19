#include <stdlib.h>
#include <stdio.h>

#include "lib/tlse.h"

//p12019.2 q2
void remove_x(TLSE *l, int x)
{
  TLSE *p = l, *ant = NULL, *del = NULL;
  if (!p)
    return;
  while (p)
  {
    if ((p->info == x) && (p->prox) && (ant))
    {
      int temp = p->info;
      p->info = ant->info;
      ant->info = temp;
      del = p;
      p = p->prox->prox;
      ant->prox = p;
      free(del->prox);
      free(del);
    }
    ant = p;
    p = p->prox;
  }
}

int main(void)
{
  TLSE *l = inicializa();
  l = insere_ini(l, 2);

  l = insere_ini(l, 2);
  l = insere_ini(l, 2);
  l = insere_ini(l, 7);

  l = insere_ini(l, 11);
  l = insere_ini(l, 13);
  l = insere_ini(l, 17);

  l = insere_ini(l, 19);
  l = insere_ini(l, 2);
  l = insere_ini(l, 21);

  l = insere_ini(l, 22);
  l = insere_ini(l, 23);
  l = insere_ini(l, 24);
  l = insere_ini(l, 2);
  l = insere_ini(l, 2);
  imprime(l);
 remove_x(l, 2);
  imprime(l);
}