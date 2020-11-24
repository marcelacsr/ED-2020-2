#include "lib/TAB.h"

TAB *v2abb(int *v, int n){
  if(n <= 0) return NULL;
  return TAB_cria(v[n/2], v2abb(v, n/2), v2abb (&v[n/2 + 1], n - n/2 - 1));
}

int main(void){
  int n;
  do{
    scanf("%d", &n);
  }while(n <= 0);
  
  int vet[n], i = 1, aux;
  scanf("%d", &vet[0]);
  while(i < n){
    scanf("%d", &aux);
    if(aux > vet[i-1]) vet[i++] = aux; 
  }
  for(i = 0; i < n; i++)printf("%d ", vet[i]);
  printf("\n");
  TAB *resp = v2abb(vet, n);
  TAB_imprime(resp);
  TAB_libera(resp);
  return 0;
}

