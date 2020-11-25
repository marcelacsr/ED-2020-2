// estritamente binaria

#include "lib/TAB.h"

int estbin(TAB *a);

int main(int argc, char const *argv[])
{
	TAB *a = inserir(61,
					 inserir(34,
							 inserir(19,
									 inserir(15, NULL, NULL),
									 inserir(29, NULL, NULL)),
							 inserir(47,
									 inserir(42, NULL, NULL),
									 inserir(53, NULL, NULL))),
					 inserir(78,
							 inserir(64,
									 NULL, //nao eh estbin
									 inserir(76, NULL, NULL)),
							 inserir(87,
									 inserir(84, NULL, NULL),
									 NULL //nao eh estbin
									 )));

	printf("\n");
	imprimir(a);
	printf("\n");

	// possuem 0 ou 2 filhos
	if (estbin(a))
	{
		printf("eh est bin\n");
	}
	else
	{
		printf("nao eh est bin\n");
	}

	liberar(a);

	return 0;
}

int estbin(TAB *a)
{
	if (!a)
		return 0;
	if (!a->esq && !a->dir)
		return 1;
	if (!a->esq && a->dir)
		return 0;
	return estbin(a->esq) && estbin(a->dir);
}