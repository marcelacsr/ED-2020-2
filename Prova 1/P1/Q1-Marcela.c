#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcula(float x, float y, char op)
{
  if ('+' == op)
    return x + y;
  if ('-' == op)
    return x - y;
  if ('*' == op)
    return x * y;
  if ('/' == op)
    return x / y;
}

int aval(char *str)
{
  // andar na string ateh encontrar um ) e dai executar a expressao
  // dps tudo...
  int qtd = strlen(str);
  printf("%d\n", qtd);
  int i;
  for (i = 0; i < qtd; i++)
  {
    if (str[i]!="("){//chegou num numero
      char valor1[10];

    
    if (str[i]==")"){//calcular


    }
    }
  }
}

int main(void)
{
  while (1)
  {
    char str[1001];
    scanf(" %1000[^\n]", str);
    if (!strcmp(str, "FIM"))
      return 0;
    int resp = aval(str);
    printf("%s = %d\n", str, resp);
  }
}
