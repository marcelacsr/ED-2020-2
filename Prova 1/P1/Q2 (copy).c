#include "TLSEV.c"

TNO *meio(TLSEV *l, int *pos)
{
  TLSEV *p = l;
  int tam_total = l->tam;
  int meio = tam_total / 2;
  TNO *elem;
  int i;
  for (i = 0; i <= meio; i++)
  {
    elem = l->vet[i];
  }
  *pos = i;
  return elem;
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
