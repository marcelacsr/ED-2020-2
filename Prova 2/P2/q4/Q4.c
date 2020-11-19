#include "TLC.c"

TLC *meio(TLC *l, int *pos)
{
  int meio=0, idx = 1;
  TLC *aux = NULL;
  if (l)
  {
    meio = 1;
    aux = l;
    TLC *p = l->prox;
    
    if (!(p)) {
      // só tem 1 elemento na lista
      (*pos) = meio;
      return aux;
    }
    
    while (p != l)
    {     
      if (idx % 2 == 0) {
        aux = aux->prox;
        meio++;
      }
      p = p->prox;
      idx++;
    }
  }
  (*pos) = meio;
  return aux;
}



// TLC *meio(TLC *l, int *pos)
// {
//   int resp = 0;
//   TLC *meio = NULL;
//   if (l)
//   {
//     TLC *aux = l->prox;
//     TLC *p = l->prox;
//     if (p = l)
//     { //tem 1 elem
//       (*pos) = 1;
//       return p;
//     }
//     while (p != l)
//     {
//       if ((p->prox != l) && (aux->prox->prox != l))
//       {
//         printf("\n oi\n");
//         aux = aux->prox->prox;
//         p = p->prox;
//         meio = p;
//         resp++;
//       }
//     }
//     printf("\n");
//   }
//   (*pos) = resp;
//   return meio;
// }

int main(void)
{
  TLC *l = NULL;
  int n;
  // do{
  //   scanf("%d", &n);
  //   if(n < 0) break;
  //   l = TLC_insere(l, n);
  // }while(1);

  l = TLC_insere(l, 5);
  // l = TLC_insere(l, 4);
  // l = TLC_insere(l, 3);
  // l = TLC_insere(l, 2);
  // l = TLC_insere(l, 1);
  TLC_imprime(l);
  int pos;
  TLC *resp = meio(l, &pos);
  if (resp)
    printf("O elemento do meio da lista (info: %d) esta na pos %d\n", resp->info, pos);

  TLC_libera(l);
  return 0;
}
