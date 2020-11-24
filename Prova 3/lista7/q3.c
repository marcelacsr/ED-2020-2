// maior elemento da árvore: TAB* maior(TAB *a);

#include "lib/TAB.h"

TAB* maior(TAB *a);

int main(int argc, char const *argv[]) {
	TAB *a = criar();
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

	imprimir(a);
	printf("\n");

	TAB *no_maior = maior(a);
	printf("%d\n", no_maior->info);

	liberar(a);

	return 0;
}

TAB* max(TAB* esq, TAB* dir) {
	if(!esq && !dir) return NULL;
	if(esq && !dir) return esq;
	if(!esq && dir) return dir;
	if(esq->info > dir->info) return esq;
	return dir;
}

TAB* maior(TAB *a) {
	if(!a) return a;
	TAB *max_esq = maior(a->esq);
	TAB *max_dir = maior(a->dir);
	return max(a, max(max_esq, max_dir));
}