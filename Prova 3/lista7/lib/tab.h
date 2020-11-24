#include <stdio.h>
#include <stdlib.h>

#ifndef TAB_H
#define TAB_H

typedef struct ab {
	int info;
	int cor;
	struct ab *esq, *dir;
} TAB;

TAB* criar (void);
TAB* inserir (int info, TAB* e, TAB* d);
TAB* remover (TAB* a, int info);
TAB* buscar (TAB* a, int info);
TAB* liberar (TAB* a);
int vazia (TAB* a);
int tamanho(TAB* a);
int pertence (TAB* a, int info);
void imprimir (TAB* a);
void imprimir_cores (TAB* a);
void pre_ordem(TAB *a);
void in_ordem(TAB *a);
void pos_ordem(TAB *a);

#endif // TAB_H