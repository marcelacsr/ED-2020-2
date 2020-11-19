#include <stdio.h>
#include <stdlib.h>

typedef struct lde{
  int info;
  struct lde *ant, *prox;
} TLDE;
TLDE* inicializa();
TLDE* insere_ini_dupla(TLDE *l, int elem);
void imprime(TLDE *l);
void TLDE_libera(TLDE *l);
TLDE* TLDE_retira(TLDE *l, int elem);
TLDE* TLDE_busca(TLDE *l, int elem);


