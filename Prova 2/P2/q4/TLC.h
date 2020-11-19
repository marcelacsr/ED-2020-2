#include <stdio.h>
#include <stdlib.h>

typedef struct lc{
  int info;
  struct lc *prox;
} TLC;

TLC* TLC_insere(TLC *l, int info);
TLC* TLC_retira(TLC *l, int info);
void TLC_imprime(TLC *l);
void TLC_libera(TLC *l);
