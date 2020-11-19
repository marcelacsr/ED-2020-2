#include <stdlib.h>
#include <stdio.h>

#include "lib/TP.h"

//p12019.2 q1
void remove_antes_depois_x(TP *p, int x)
{
  TP *p2 = TP_inicializa();
  int valor_aux;
  while (!TP_vazia(p))
  {
    int valor = TP_pop(p);
    if (valor == x)
    {
      if (TP_pop(p2) == x)
        TP_push(p2, x);

      while (valor == x)
      {
        TP_push(p2, valor);
        valor = TP_pop(p);
      }
    }
    else
    {
      TP_push(p2, valor);
    }
  }
  while (!TP_vazia(p2))
    TP_push(p, TP_pop(p2));
}

int main(void)
{
  TP *l = TP_inicializa();
  TP_push(l, 1);
  TP_push(l, 2);
  TP_push(l, 7);

  TP_push(l, 11);
  TP_push(l, 13);
  TP_push(l, 17);

  TP_push(l, 19);
  TP_push(l, 2);
  TP_push(l, 21);
  TP_push(l, 2);
  TP_push(l, 2);
  TP_push(l, 24);

  TP_push(l, 25);
  TP_push(l, 26);
  TP_imprime(l);
  printf("Removendo..\n");
  remove_antes_depois_x(l, 2);
  TP_imprime(l);
}