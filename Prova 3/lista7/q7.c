// se esta estrutura TAB tivesse um campo cor (int cor), defina uma função em C que, ao
// receber uma árvore binária “sem cor” e totalmente balanceada (isto é, a distância da raiz a qualquer
// folha da árvore é sempre a mesma), retorne esta árvore com os nós coloridos somente de vermelho e
// preto, sendo que o nó pai NUNCA pode ter a mesma cor de seus filhos. A função deve possuir o
// seguinte protótipo: void colore (TAB* arv);


#include "lib/tab.h"

#define VERMELHO 0
#define PRETO 1

void colore (TAB* arv);

int main(int argc, char const *argv[]) {
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

	colore(a);

	imprimir_cores(a);

	liberar(a);

	return 0;
}

void colore (TAB* arv) {
	if(arv) {
		colore(arv->esq);
		colore(arv->dir);
		if((arv->esq && arv->esq->cor == VERMELHO) || (arv->dir && arv->dir->cor == VERMELHO)) {
			arv->cor = PRETO;
		} else {
			arv->cor = VERMELHO;
		}
	} 
}