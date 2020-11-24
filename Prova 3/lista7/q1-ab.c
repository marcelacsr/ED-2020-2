// cópia de uma árvore: TAB* copia (TAB *a);

#include "lib/TAB.h"

TAB* copia (TAB *a);

int main(int argc, char const *argv[]) {
	TAB *a = inicializar();
	a = inserir(2, 
		inserir(3, 
			inserir(4, NULL, NULL), 
			inserir(6, NULL, NULL)
		), 
		inserir(5, 
			inserir(7, NULL, NULL), 
			inserir(11, NULL, NULL)
		)
	);

	TAB *a_cp = copia(a);

	imprimir(a);
	printf("\n");
	liberar(a);

	imprimir(a_cp);
	printf("\n");
	liberar(a_cp);

	return 0;
}

TAB* copia (TAB *a) {
	if(vazia(a)) return NULL;
	return inserir(a->info, copia(a->esq), copia(a->dir));
}