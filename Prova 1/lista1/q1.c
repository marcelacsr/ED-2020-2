#include <stdio.h>
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

int primo(int n)
{
  if (n <= 2)
    return 0;
  int i;
  for (i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      return 0;
    }
    return 1;
  }
}

int imprime_primos(int n)
{
  int i, count = 0;
  printf(GRN"\n Os N primeiros numeros primos existentes ate %d sao: "RESET, n);
  for (i = 2; count < n; i++)
  {
    if (primo(i))
    {
      printf(" %d ", i);
    }
    count++;
  }
}

int main(void)
{
  printf("Exercicio 1\n");
  while (1)
  {
    int n;
    printf("\n Digite um numero: ");
    scanf("%d", &n);
    if (n <= 0)
      return 0;
    imprime_primos(n);
  }
  return 0;
}