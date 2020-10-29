#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int info, prox;
}TNO;

typedef struct lista{
  int tam, ini, fim; 
  TNO **vet;
}TLSEV;

TLSEV* TLSEV_cria(int n);
void TLSEV_insere(TLSEV *l, int elem);
void TLSEV_imprime(TLSEV *l);
void TLSEV_libera(TLSEV *l);
void TLSEV_retira(TLSEV *l, int elem);
