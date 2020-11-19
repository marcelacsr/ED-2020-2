#include <stdlib.h>
#include <stdio.h>

#include "lib/tlse.h"

//p12019.1 q3
void troca_x(TLSE *l, int x)
{
  TLSE *p = l, *ant = NULL;
  if (!p)
    return;
  while (p)
  {
    ant = p;
    p = p->prox;
    if ((p->info == x) && (p != NULL))
    {
      int temp = ant->info;
      ant->info = p->prox->info;
      p->prox->info = temp;
    }
  }
}
//p12019.1 q3
void troca_x2(TLSE *l, int x)
{
  TLSE *p = l, *ant = NULL;
  if (!p)
    return;
  while (p)
  {
    if ((p->prox) && (p->info == x) && (ant))
    {
      imprime(l);
      int temp = p->prox->info;
      p->prox->info = ant->info;
      ant->info = temp;
    }
    ant = p;
    p = p->prox;
  }
}
//p12019.1 q4
void add_antes_depois_x(TLSE *l, int x)
{
  { // 2 2 3 4 5 2 3 4 5
    // l->1 2 (2) 1 2 | 1 2 (2) 1 2 | 4 5 | 1 2 (2) 1 2 | 3 4 5
    TLSE *p = l, *aux = NULL, *nova = NULL;
    int i;
    if (!p)
      return;
    while (p)
    {
      if (p->info == x)
      {
        nova = NULL;
        p->info = 1;
        for (int i = x; i >= 1; i--)
        {
          nova = insere_ini(nova, i); //3 2 1 -> 1 2 3
        }
        nova = insere_ini(nova, x); //3
        for (int i = x; i > 1; i--)
        {
          nova = insere_ini(nova, i); //3 2 -> 2 3
        }
        aux = p->prox;
        p->prox = nova;
        while (nova->prox)
          nova = nova->prox;
        nova->prox = aux;
        p = nova; //IMP!
      }
      p = p->prox;
    }
  }
}

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
  // l = insere_ini(l, 1);

  l = insere_ini(l, 3);

  l = insere_ini(l, 2);
  l = insere_ini(l, 7);
  l = insere_ini(l, 11);
  l = insere_ini(l, 13);
  l = insere_ini(l, 17);
  l = insere_ini(l, 19);

  l = insere_ini(l, 3);

  l = insere_ini(l, 21);
  l = insere_ini(l, 22);  
  l = insere_ini(l, 24);
  l = insere_ini(l, 2);
  l = insere_ini(l, 2);

  l = insere_ini(l, 3);

  imprime(l);
  printf("\ntroca 3\n");
  troca_x2(l, 3);
  imprime(l);
  printf("\nadd_antes_depois_x\n");
  add_antes_depois_x(l, 3);
  imprime(l);
  printf("\nremove_x\n");
  remove_x(l, 3);
  imprime(l);
}
