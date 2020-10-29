#include "TLSEV.c"

TNO *meio(TLSEV *l, int *pos)
{
  int cont = 0, i = l->ini;
  TNO *aux = l->vet[0];
  while (i != -1)
  {
    if (l->vet[i]->info != -1)
    {
      cont++;
    }
    i = l->vet[i]->prox;
  }
  int meio = cont / 2;
  aux = l->vet[meio];
  *pos = meio;
  return aux;
}

int main(void)
{
  int n, x;
  scanf("%d", &n);
  if (n <= 0)
    return 0;
  TLSEV *l = TLSEV_cria(n);
  do
  {
    scanf("%d", &x);
    if (x < 0)
      break;
    TLSEV_insere(l, x);
  } while (1);

  int pos;
  TNO *resp = meio(l, &pos);
  if (resp)
    printf("O elemento do meio da lista (info: %d e prox: %d) esta na pos %d\n", resp->info, resp->prox, pos);

  TLSEV_libera(l);
  return 0;
}
