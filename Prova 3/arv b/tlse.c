#include "tlse.h"

// Inicializa a lista.
TLSE *inicializa()
{
	return NULL;
}

// Insere no inicio da list.
TLSE *insere_ini(TLSE *l, int info)
{
	TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
	novo->info = info;
	novo->prox = l;
	return novo;
}

// Insere no fim da lista.
TLSE *insere_fim(TLSE *l, int info)
{
	if (!l)
		return insere_ini(l, info);

	TLSE *p = l;
	while (p->prox)
		p = p->prox;

	TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
	novo->info = info;
	novo->prox = NULL;

	p->prox = novo;
	return l;
}

// Retonar o nó onde se encontra o elemento, caso não encontre retorna NULL.
TLSE *busca(TLSE *l, int info)
{
	TLSE *p = l;
	while (p && p->info != info)
		p = p->prox;
	return p;
}

// Remove a informação passada por parametro.
TLSE *TLSE_remover(TLSE *l, int info)
{
	if (!l)
		return l;

	TLSE *p = l, *ant = NULL;
	while (p && p->info != info)
	{
		ant = p;
		p = p->prox;
	}

	// remove no inicio
	if (!ant)
	{
		TLSE *temp = p;
		p = p->prox;
		free(temp);
		return p;
	}

	ant->prox = p->prox;
	free(p);
	return l;
}

// Libera a lista da memoria.
void libera(TLSE *l)
{
	TLSE *p = l;
	while (p)
	{
		TLSE *temp = p->prox;
		free(p);
		p = temp;
	}
}

// Printa os elementos no terminal.
void imprime(TLSE *l)
{
	TLSE *p = l;
	while (p)
	{
		printf(" %d ", p->info);
		p = p->prox;
	}
	printf("\n");
}

TLSE *insere_circular(TLSE *l, int info)
{
	TLSE *p = l;
	TLSE *no = (TLSE *)malloc(sizeof(TLSE));
	no->info = info;
	if (p == NULL)
	{
		no->prox = no;
	}
	else
	{
		while (p->prox != l)
			p = p->prox;
		no->prox = p->prox;
		p->prox = no;
	}
	p = no->prox;
	return p;
}

void imprime_circular(TLSE *l)
{
	TLSE *p = l;
	while (p && p->prox != l)
	{
		printf(" %d ", p->info);
		p = p->prox;
	}
	printf(" %d ", p->info);
	printf("\n");
}

TLSE* junta_listas(TLSE* l1, TLSE* l2) {
	if(!l1 && l2) return l2;
	if(l1 && !l2) return l1;
    if(!l1 && !l2) return NULL;

	TLSE *p = l1;
	while(p->prox) p = p->prox;

	p->prox = l2;
	return l1;
}
