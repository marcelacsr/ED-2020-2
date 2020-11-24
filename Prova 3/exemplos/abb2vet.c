#include "lib/TABB.h"

int* abb2vet(TABB *a, int qtde);

int main(void){
  while(1){
    int n;
printf("Insira qtd de elementos: ");
    scanf("%d", &n);
    if(n <= 0) return 0;
    TABB *resp = NULL;
    int aux, i;
printf("Insira os %d elementos: ", n);
    for(i = 0; i < n; i++){
      scanf("%d", &aux);
      resp = TABB_insere(aux, resp);
    }
    TABB_imprime(resp);
    int *vet = abb2vet(resp, n);
    for(i = 0; i < n; i++) printf("%d ", vet[i]);
    printf("\n");
    TABB_libera(resp);
    free(vet);
  }
}

void a2vaux(TABB *a, int *vet, int *pos){
  if(a){
    a2vaux(a->esq, vet, pos);
    vet[(*pos)] = a->info;
    (*pos)++;
    a2vaux(a->dir, vet, pos);    
  }  
}

int* abb2vet(TABB *a, int qtde){
  int *resp = (int *)malloc(sizeof(int) * qtde), pos = 0;
  a2vaux(a, resp, &pos);
  return resp;
}  
