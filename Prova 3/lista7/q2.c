// espelho de uma árvore (o que está a esquerda na árvore original, estará a direita no espelho, e
// vice-versa): TAB* espelho (TAB *a);
#include "lib/TAB.h"

TAB *espelho(TAB *a);

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

	TAB *a_esp = espelho(a);

	imprimir(a);
	printf("\n");
	liberar(a);
	printf("Espelhada:\n");
	imprimir(a_esp);
	printf("\n");
	liberar(a_esp);

	return 0;
}

TAB *espelho(TAB *a)
{
	if (vazia(a))
		return NULL;
	return inserir(a->info, espelho(a->dir), espelho(a->esq));
}