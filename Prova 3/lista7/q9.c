// ache a quantidade de nós folha: int nf(TAB *a);


#include "lib/TAB.h"

int nf(TAB *a);

int main() {
	TAB *a = criar();
	a = inserir(61,
		inserir(34, 
			inserir(19, 
				inserir(15, NULL, NULL), 
				inserir(29, NULL, NULL)
			),
			inserir(47, 
				inserir(42, NULL, NULL), 
				inserir(53, NULL, NULL)
			)
		),
		inserir(78, 
			inserir(64, 
				NULL, 
				inserir(76, NULL, NULL)
			),
			inserir(87, 
				inserir(84, NULL, NULL), 
				NULL
			)
		)
	);

	imprimir(a);
	printf("\n");
	
	printf("%d nos folha.\n", nf(a));

	liberar(a);

	return 0;
}

int nf(TAB *a) {
	if(a && !a->esq && !a->dir) return 1;
	if(a && a->esq && !a->dir) return nf(a->esq);
	if(a && !a->esq && a->dir) return nf(a->dir);
	return nf(a->esq) + nf(a->dir);
}