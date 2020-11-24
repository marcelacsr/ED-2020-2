// cópia de uma árvore: TABB* copia (TABB *a);

#include "lib/TABB.h"

TABB* copia (TABB *a);

int main(int argc, char const *argv[]) {
	TABB *a = criar();
	a = TABB_insere(a, 61);
	a = TABB_insere(a, 34);
	a = TABB_insere(a, 78);
	a = TABB_insere(a, 19);
	a = TABB_insere(a, 47);
	a = TABB_insere(a, 64);
	a = TABB_insere(a, 87);
	a = TABB_insere(a, 15);
	a = TABB_insere(a, 29);
	a = TABB_insere(a, 42);
	a = TABB_insere(a, 53);
	a = TABB_insere(a, 76);
	a = TABB_insere(a, 84);

	TABB *a_cp = copia(a);
printf("Original:\n");
	TABB_imprime(a);
	printf("\n");
	TABB_libera(a);

printf("Copia:\n");
	TABB_imprime(a_cp);
	printf("\n");
	TABB_libera(a_cp);

	return 0;
}

TABB* copia (TABB *a) {
	if(!a) return NULL;
	TABB *aux = TABB_insere(NULL, a->info);
	aux->esq = copia(a->esq);	
	aux->dir = copia(a->dir);
	return aux;
}