#include <stdio.h>
#include <stdlib.h>

// Lista simplesmente encadeada.
typedef struct lista {
	int info;
	struct lista *prox;
} TLSE;

// Interface da lista.
TLSE* inicializa();
TLSE* insere_ini(TLSE* l, int info);
TLSE* insere_fim(TLSE* l, int info);
TLSE* insere_circular(TLSE* l, int info);
void imprime_circular(TLSE*l);
TLSE* busca(TLSE* l, int info);
TLSE* TLSE_remover(TLSE* l, int info);
void libera(TLSE* l);
void imprime(TLSE* l);
TLSE* junta_listas(TLSE* l1, TLSE* l2);
