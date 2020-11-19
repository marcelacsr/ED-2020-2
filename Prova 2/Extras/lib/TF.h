#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

typedef struct fila{
	TLSE *ini;
	TLSE *fim;
}TF;

void TF_insere(TF *f, int elem);
int TF_vazia(TF *f);
void TF_libera(TF *f);
TF *TF_inicializa(void);
int TF_retira(TF *f);
void TF_imprime(TF *f);
