// uma função que, dadas duas árvores deste tipo, testa se estas árvores são iguais. A função
// retorna um se elas são iguais e zero, caso contrário. A função deve obedecer ao seguinte protótipo:
// int igual (TAB* a1, TAB* a2);

#include "lib/TAB.h"

int igual(TAB *a1, TAB *a2);

int main(int argc, char const *argv[])
{
	TAB *a1 = inserir(61,
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
									  inserir(80, NULL, NULL)
									  )));
	TAB *a3 = inserir(61,
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
									  NULL)));

	TAB *a4 = inserir(61,
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

	imprimir(a1);
	printf("\n");

	imprimir(a2);
	printf("\n");

	imprimir(a3);
	printf("\n");

	imprimir(a4);
	printf("\n");

	printf("1:\n");
	if (igual(a1, a2))
		printf("Igual\n");
	else
		printf("Diferente\n");
	if (igual(a1, a3))
		printf("Igual\n");
	else
		printf("Diferente\n");
	if (igual(a1, a4))
		printf("Igual\n");
	else
		printf("Diferente\n");
	printf("2:\n");
	if (igual(a2, a1))
		printf("Igual\n");
	else
		printf("Diferente\n");
	if (igual(a2, a3))
		printf("Igual\n");
	else
		printf("Diferente\n");
	if (igual(a2, a4))
		printf("Igual\n");
	else
		printf("Diferente\n");
	printf("3:\n");
	if (igual(a3, a1))
		printf("Igual\n");
	else
		printf("Diferente\n");
	if (igual(a3, a2))
		printf("Igual\n");
	else
		printf("Diferente\n");
	if (igual(a3, a4))
		printf("Igual\n");
	else
		printf("Diferente\n");
	printf("4:\n");
	if (igual(a4, a1))
		printf("Igual\n");
	else
		printf("Diferente\n");
	if (igual(a4, a2))
		printf("Igual\n");
	else
		printf("Diferente\n");
	if (igual(a4, a3))
		printf("Igual\n");
	else
		printf("Diferente\n");

	liberar(a1);
	liberar(a2);
	liberar(a3);
	liberar(a4);

	return 0;
}

int igual(TAB *a1, TAB *a2)
{
	if (!a1 && !a2)
		return 1;
	if ((!a1 && a2) || (a1 && !a2))
		return 0;
	if (a1->info != a2->info)
		return 0;
	return igual(a1->esq, a2->esq) && igual(a1->dir, a2->dir);
}