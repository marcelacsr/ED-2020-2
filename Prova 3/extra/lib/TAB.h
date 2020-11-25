#include <stdio.h>
#include <stdlib.h>

typedef struct arvbin{
    int info;
    struct arvbin *esq, *dir;
}TAB;

TAB* inserir(int x, TAB* e, TAB* d);
void imprimir(TAB *t);
void liberar(TAB* t);
TAB* TAB_busca(int e, TAB* t);
TAB* inicializar (void);
int vazia (TAB* t);
TAB* criar (void);
//void imprimir (TAB* a);
//void imprimir_cores (TAB* a);
void pre_ordem(TAB *a);
void in_ordem(TAB *a);
void pos_ordem(TAB *a);
