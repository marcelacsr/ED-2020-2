
#include "lib/TAB.h"
#include <stdlib.h>

int mesma_info(TAB *a1, TAB *a2);
void a2vaux(TAB *a, int *vet, int *pos);
int *ab2vet(TAB *a, int qtde);
int conta_nos(TAB *a);
int igual(int a, int b);

int cmp_int_dec(const void *px, const void *py)
{
	int *ix = (int *)px, *iy = (int *)py;
	if ((*ix) > (*iy))
		return -1;
	if ((*ix) < (*iy))
		return 1;
	return 0;
}

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
									  NULL,
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
									  inserir(80, NULL, NULL))));
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
	if (mesma_info(a1, a2))
		printf("mesma_info\n");
	else
		printf("Diferente\n");
	if (mesma_info(a1, a3))
		printf("mesma_info\n");
	else
		printf("Diferente\n");
	if (mesma_info(a1, a4))
		printf("mesma_info\n");
	else
		printf("Diferente\n");
	printf("2:\n");
	if (mesma_info(a2, a1))
		printf("mesma_info\n");
	else
		printf("Diferente\n");
	if (mesma_info(a2, a3))
		printf("mesma_info\n");
	else
		printf("Diferente\n");
	if (mesma_info(a2, a4))
		printf("mesma_info\n");
	else
		printf("Diferente\n");
	printf("3:\n");
	if (mesma_info(a3, a1))
		printf("mesma_info\n");
	else
		printf("Diferente\n");
	if (mesma_info(a3, a2))
		printf("mesma_info\n");
	else
		printf("Diferente\n");
	if (mesma_info(a3, a4))
		printf("mesma_info\n");
	else
		printf("Diferente\n");
	printf("4:\n");
	if (mesma_info(a4, a1))
		printf("mesma_info\n");
	else
		printf("Diferente\n");
	if (mesma_info(a4, a2))
		printf("mesma_info\n");
	else
		printf("Diferente\n");
	if (mesma_info(a4, a3))
		printf("mesma_info\n");
	else
		printf("Diferente\n");

	//conta nos
	int nos1 = conta_nos(a1);
	int nos2 = conta_nos(a2);
	printf("a1: %d, a2:%d\n", nos1, nos2);
	int *vet1, *vet2;
	if (nos1 == nos2)
	{
		//passa para vetor
		vet1 = ab2vet(a1, nos1);
		vet2 = ab2vet(a2, nos2);
	}
	//ordena vetor
	int i;
	for (i = 0; i < nos1; i++)
		printf("%d ", vet1[i]);
	printf("\n");
	for (i = 0; i < nos2; i++)
		printf("%d ", vet2[i]);
	printf("\n");

	qsort(vet1, nos1, sizeof(int), cmp_int_dec);
	qsort(vet2, nos2, sizeof(int), cmp_int_dec);

	printf("\n");
	for (i = 0; i < nos1; i++)
		printf("%d ", vet1[i]);
	printf("\n");
	for (i = 0; i < nos2; i++)
		printf("%d ", vet2[i]);
	printf("\n");
	//compara os vetores sao iguais

	for (i = 0; i < nos1; i++)
		if (igual(vet1[i], vet2[i]))
		{
			printf(" Igual ");
		}
		else
		{
			printf(" Dif ");
		}
	liberar(a1);
	liberar(a2);
	liberar(a3);
	liberar(a4);

	return 0;
}

int igual(int a, int b)
{
	if (a == b)
		return 1;
	else
		return 0;
}

int mesma_info(TAB *a1, TAB *a2)
{
	if (!a1 && !a2)
		return 1;
	if ((!a1 && a2) || (a1 && !a2))
		return 0;

	if (a1->info != a2->info)
		return 0;
	return mesma_info(a1->esq, a2->esq) && mesma_info(a1->dir, a2->dir);
}
//ABB para VETOR
void a2vaux(TAB *a, int *vet, int *pos)
{
	if (a)
	{
		a2vaux(a->esq, vet, pos);
		vet[(*pos)] = a->info;
		(*pos)++;
		a2vaux(a->dir, vet, pos);
	}
}

int *ab2vet(TAB *a, int qtde)
{
	int *resp = (int *)malloc(sizeof(int) * qtde), pos = 0;
	a2vaux(a, resp, &pos);
	return resp;
}

int conta_nos(TAB *a)
{
	if (vazia(a))
		return 0;
	return 1 + conta_nos(a->esq) + conta_nos(a->dir);
}
