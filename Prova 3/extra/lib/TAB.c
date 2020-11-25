#include "TAB.h"

void liberar(TAB* t){
  if(t){
    liberar(t->esq);
    liberar(t->dir);
    free(t);
  }
}

TAB* TAB_busca(int e, TAB* t){
  if((!t) || (t->info == e)) return t;
  TAB *resp = TAB_busca(e, t->esq);
  if(resp) return resp;
  return TAB_busca(e, t->dir);
}

void imprime_aux(TAB* a, int andar){
  if(a){
    int j;
    imprime_aux(a->esq, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t");
    printf("%d\n", a->info);
    imprime_aux(a->dir, andar + 1);
  }
}

void imprimir(TAB* a){
  imprime_aux(a, 1);
}

TAB* inserir(int x, TAB* e, TAB* d){
  TAB* a = (TAB*) malloc(sizeof(TAB));
  a->info = x;
  a->esq = e;
  a->dir = d;
  return a;
}

TAB* inicializar (void) {
	return NULL;
}

TAB* criar (void) {
	return NULL;
}

int vazia (TAB* a) {
	return a == NULL;
}

// A comunidade C de desenvolvimento, costuma utilizar "_" na frente de funções "privadas", 
// ou seja, as que não estão nos headers (.h).
void _imprime(TAB *a, int andar){
  if(a){
    _imprime(a->esq, andar + 1);
    for(int i=0; i <= andar; i++) printf("   ");
    printf("%d\n", a->info);
    _imprime(a->dir, andar + 1);
  }
}
/*
void imprimir (TAB* a) {
	_imprime(a, 0);
}

void _imprime_cores(TAB *a, int andar){
  if(a){
    _imprime_cores(a->esq, andar + 1);
    for(int i=0; i <= andar; i++) printf("    ");
    printf("%d (%d)\n", a->info, a->cor);
    _imprime_cores(a->dir, andar + 1);
  }
}


void imprimir_cores (TAB* a) {
	_imprime_cores(a, 0);
}
*/
void pre_ordem(TAB *a) {
	if(!vazia(a)) {
		printf(" %d ", a->info);
		pre_ordem(a->esq);
		pre_ordem(a->dir);
	}
}

void in_ordem(TAB *a) {
	if(!vazia(a)) {
		in_ordem(a->esq);
		printf(" %d ", a->info);
		in_ordem(a->dir);
	}
}

void pos_ordem(TAB *a) {
	if(!vazia(a)) {
		pos_ordem(a->esq);
		pos_ordem(a->dir);
		printf(" %d ", a->info);
	}
}
