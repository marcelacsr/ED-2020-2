#include <stdlib.h>
#include <stdio.h>

#include "lib/tlde.h"

void inv_entre(TLSE *l, int N, int M)
{
	printf("\nn: %d, m: %d\n", N, M);
	TLSE *primeiro = NULL;
	TLSE *ultimo = NULL;
	TLSE *p = l;
	if (!p)
		return;
	while (p)
	{				   //para quando p->info eh igual a N ou M
		if (p == NULL) // nao encontrou N ou M
			return;
		if ((p->info == N || p->info == M) && (primeiro == NULL))
			primeiro = p; // p eh N ou M
		else if ((p->info == N || p->info == M) && (primeiro))
			ultimo = p; // p eh N ou M
		p = p->prox;
	}
	
	while(1)
	{
		int temp = primeiro->prox->info;
		primeiro->prox->info = ultimo->ant->info;
		ultimo->ant->info = temp;
		primeiro = primeiro->prox;
		ultimo = ultimo->ant;
		if (primeiro->prox == ultimo->ant) //eh o msm elemento
		return;
		if (primeiro->prox == ultimo || ultimo->ant == primeiro) //vai cruzar
		return;
	}
};

int main(int argc, char const *argv[])
{
	TLSE *l = inicializa();
	l = insere_ini(l, 2);
	l = insere_ini(l, 3);
	l = insere_ini(l, 5);

	l = insere_ini(l, 7);

	l = insere_ini(l, 11);
	l = insere_ini(l, 13);
	l = insere_ini(l, 17);
	l = insere_ini(l, 19);

	l = insere_ini(l, 20);

	l = insere_ini(l, 21);

	l = insere_ini(l, 22);
	l = insere_ini(l, 23);
	l = insere_ini(l, 24);
	l = insere_ini(l, 25);
	l = insere_ini(l, 20);

	l = insere_ini(l, 27);
	imprime(l);

	inv_entre(l, 20, 7);
	imprime(l);

	inv_entre(l, 20, 20);
	imprime(l);

	return 0;
}