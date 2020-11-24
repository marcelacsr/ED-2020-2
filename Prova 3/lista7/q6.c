// uma função em C que, dada uma árvore binária qualquer, retire todos os elementos pares da
// árvore original. A função deve ter o seguinte protótipo: TAB* retira_pares (TAB* arv);


#include "lib/TAB.h"

TAB* retira_pares (TAB* arv);
int tamanho(TAB* a);

int main(int argc, char const *argv[]) {
	TAB* a = inserir(61,
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

	pre_ordem(a);
	printf("\n");
    imprimir(a);
    printf("\n");

	a = retira_pares(a);

	pre_ordem(a);
	printf("\n");
    imprimir(a);
    printf("\n");

	liberar(a);

	return 0;
}


/* 
A ideia aqui é tentar pegar o ultimo nó do ramo que possui a maior quantidade de nós, 
assim a arvore não fica muito desbalanceada.
*/
TAB* pega_ultimo_no(TAB* a) {
	if(!a) return NULL;
	int esq = 0;

	TAB *p = a, *ant = NULL;
	while(p->esq || p->dir) {
		ant = p;
		if(tamanho(p->esq) > tamanho(p->dir)) {
			p = p->esq;
			esq = 1;
		} else {
			p = p->dir;
			esq = 0;
		}
	}
	if(esq) ant->esq = NULL;	
	else ant->dir = NULL;
	return p;
}

TAB* remove_raiz(TAB *arv) {
	if(!arv->esq && !arv->dir) {
		free(arv);
		return NULL;
	}
	if(arv->esq && !arv->dir) {
		TAB *no = arv->esq;
		free(arv);
		return no;
	}
	if(!arv->esq && arv->dir) {
		TAB *no = arv->dir;
		free(arv);
		return no;
	}
	TAB* no = pega_ultimo_no(arv); 
	no->esq = arv->esq;
	no->dir = arv->dir;
	free(arv);
	return no;
}

TAB* retira_pares (TAB* arv) {
	if(!arv) return NULL;
	arv->esq = retira_pares(arv->esq);
	arv->dir = retira_pares(arv->dir);
	if(arv->info % 2 == 0) return remove_raiz(arv);
	return arv;
}

int tamanho(TAB* a) {
	if(!a) return 0;
	return 1 + tamanho(a->esq) + tamanho(a->dir);
}
