#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int teste(int n)
{  
  // transformar em string pegar os 2 primeiros e 2 ultimos
  // usar atoi para fazer a soma e elevar ao quadrado
  char buf[10];
  // inteiro para string até 10
  sprintf(buf, "%i", n);
  int qtd = strlen(buf);
  if (qtd < 4) return 0;
  // string para inteiro
  char primeira[3];
  strncpy(primeira, buf, 2);
  primeira[2] = '\0';
  char segunda[3];
  // int qtd = strlen(buf); //testar com a f_len(s)
  strncpy(segunda, buf + qtd - 2, 2);
  segunda[2] = '\0';
  int soma = atoi(primeira) + atoi(segunda);
  char total[4];
  sprintf(total, "%s%s", primeira, segunda);
  // printf("\nsoma: %s\n", total);
  int quad;
  quad = soma * soma;
  // sprintf(quad, "%i", soma * soma);
  // printf("\nsoma: %s\n", quad);
  return (atoi(total) == quad);
}

int main(void)
{
  while (1)
  {
    int n;
    scanf("%d", &n);
    if (n < 0)
      return 0;
    printf("%d\n", teste(n));
  }
}


1 2 3 4 5 6
