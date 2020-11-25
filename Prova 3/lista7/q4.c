// menor elemento da árvore: TAB* menor(TAB *a);

#include "lib/TAB.h"

TAB *menor(TAB *a);

int main(int argc, char const *argv[])
{
	TAB *a = criar();
	a = inserir(2,
				inserir(3,
						inserir(4, NULL, NULL),
						inserir(6, NULL, NULL)),
				inserir(5,
						inserir(7, NULL, NULL),
						inserir(11, NULL, NULL)));

	imprimir(a);
	printf("\n");

	TAB *no_min = menor(a);
	printf("%d\n", no_min->info);

	liberar(a);

	return 0;
}

TAB *min(TAB *esq, TAB *dir)
{
	if (!esq && !dir)
		return NULL;
	if (esq && !dir)
		return esq;
	if (!esq && dir)
		return dir;
	if (esq->info < dir->info)
		return esq;
	return dir;
}

TAB *menor(TAB *a)
{
	if (!a)
		return a;
	TAB *min_esq = menor(a->esq);
	TAB *min_dir = menor(a->dir);
	return min(a, min(min_esq, min_dir));
}