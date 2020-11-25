// estritamente binaria

#include "lib/TAB.h"

int zz(TAB *a);

int main(int argc, char const *argv[]) {
	TAB* a = inserir(61,
		NULL,
		inserir(78, NULL,
			inserir(87, 
				inserir(84, NULL, NULL), 
				NULL 
			)
		)
	);

	printf("\n");
    imprimir(a);
    printf("\n");

// possuem 0 ou 1 filhos
    if (zz(a)) 
    {
        printf("eh zz\n");
    }
        else
    {
        printf("nao eh zz\n");
    }
    
	liberar(a);

	return 0;
}

int zz(TAB *a){
    if(!a) return 0;
    if(a->esq && a->dir) return 0; //tem 2 filhos
    if(!a->esq && a->dir) return 1;
    if(a->esq && !a->dir) return 1;        
    return zz(a->esq) && zz(a->dir);    
}