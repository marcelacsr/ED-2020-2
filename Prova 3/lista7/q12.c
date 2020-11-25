#include "lib/TAB.h"

int mesmos_nos(TAB *a1, TAB *a2);

int main(int argc, char const *argv[]) {
	TAB* a1 = inserir(61,
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

TAB* a2 = inserir(61,
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
				//inserir(80, NULL, NULL) 
                NULL
			)
		)
	);

	printf("\n");
    imprimir(a1);
    printf("\n");
	printf("\n");
    imprimir(a2);
    printf("\n");

    if (mesmos_nos(a1, a2)) 
    {
        printf("tem os mesmos nos\n");
    }
        else
    {
        printf("nao tem os mesmos nos\n");
    }
    
	liberar(a1);
    liberar(a2);

	return 0;
}

int mesmos_nos(TAB *a1, TAB *a2){
	if(!a1 && !a2) return 1;
	if((!a1 && a2) || (a1 && !a2)) return 0;
    return mesmos_nos(a1->esq, a2->esq) && mesmos_nos(a1->dir, a2->dir);
}