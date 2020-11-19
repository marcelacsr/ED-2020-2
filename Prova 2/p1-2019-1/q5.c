#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lib/tlse.h"

//p12019.1 q5 LISTA CIRCULAR
int jp(TLSE *l, int passo){
  if((!l) || (passo <= 0)) return 0;

  if(l->prox == l) return 1;

  TLSE *laux = NULL;
  laux = insere_ini(laux, l->info);
  TLSE *p = l->prox;
  while(p != l){
    laux = insere_ini(laux, p->info);
    p = p->prox;
  }

  int j;
  p = laux;
  while(laux->prox != laux){
    j = 0;
    while(j != passo){
      j++;
      p = p->prox;
    }
    printf("%d morreu...\n", p->info);
    char aux[31];
    strcpy(aux, p->info);
    p = p->prox;
    laux = remover(laux, aux);
  }

  int num = 1;
  p = l;
  do{
    if(strcmp(p->info, laux->info) == 0){
      libera(laux);
      return num;
    }
    num++;
    p = p->prox;
  } while(p != l);
}

int main(void)
{
  TLSE *l = inicializa();
  l = insere_circular(l, 1);
  l = insere_circular(l, 2);
  l = insere_circular(l, 3);
  l = insere_circular(l, 4);
  l = insere_circular(l, 5);
  l = insere_circular(l, 6);
  l = insere_circular(l, 7);
  l = insere_circular(l, 8);
  imprime_circular(l);
}