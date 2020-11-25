#include "lib/TAB.h"

int um_filho_raiz(TAB *a);
int um_filho(TAB *a);

int main(int argc, char const *argv[])
{
	TAB *a1 = inserir(61,
					  inserir(34,
							  inserir(19,
									  inserir(15, NULL, NULL),
									  NULL),
							  NULL),

					  inserir(78,
							  NULL,
							  inserir(87,
									  inserir(84, NULL, NULL),
									  NULL)));

	TAB *a2 = inserir(61,
					  inserir(34,
							  inserir(19,
									  inserir(15, NULL, NULL),
									  inserir(29, NULL, NULL)),
							  inserir(47,
									  inserir(42, NULL, NULL),
									  inserir(53, NULL, NULL))),
					  inserir(78,
							  inserir(64,
									  NULL,
									  inserir(76, NULL, NULL)),
							  inserir(87,
									  inserir(84, NULL, NULL),
									  //inserir(80, NULL, NULL)
									  NULL)));

	printf("\n");
	imprimir(a1);
	printf("\n");
	printf("\n");
	imprimir(a2);
	printf("\n");

	if (um_filho_raiz(a1))
		printf("possuem 1 filho\n");
	else
		printf("nao\n");

	if (um_filho_raiz(a2))
		printf("possui 1 filho\n");
	else
		printf("nao\n");

	liberar(a1);
	liberar(a2);

	return 0;
}

int um_filho_raiz(TAB *a)
{
	if (!a)
		return 1;
	return um_filho(a->esq) && um_filho(a->dir); // testa a esq e dir da raiz
}

int um_filho(TAB *a)
{
	if (!a)
		return 1;
	if ((a->esq && !a->dir) || (!a->esq && a->dir))
		return 1;
	else
		return 0;
	return um_filho(a->esq) && um_filho(a->dir);
}