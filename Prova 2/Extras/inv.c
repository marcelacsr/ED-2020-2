#include <stdlib.h>
#include <stdio.h>

#include "lib/tlse.h"

void inverte_lista(TLSE *l)
{
  TLSE *p = l, *aux = NULL, *t = NULL;
  if (!p)
    return;
  while (p)
  {
    aux = insere_ini(aux, p->info);
    t = p;
    p = p->prox;
    if (t != l)
      free(t); // guardar primeira posicao da lista
  }
  l->info = aux->info;
  l->prox = aux->prox;
  free(aux); //free na aux
}

int main(void)
{
  TLSE *l = inicializa();
  l = insere_ini(l, 1);

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
  inverte_lista(l);
  imprime(l);
}