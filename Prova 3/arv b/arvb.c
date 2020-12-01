#include "TARVB.h"
#include "tlse.h"

TARVB *maior_numero_chaves(TARVB *a)
{
  if (!a)
    return NULL;
  TARVB *resp = a, *aux;
  int i = 0;
  while (i <= a->nchaves)
  {
    aux = maior_numero_chaves(a->filho[i]);
    if ((aux) && (aux->nchaves > resp->nchaves))
      resp = aux;
    i++;
  }
  return resp;
}

TLSE *intervalo(TARVB *a, int n1, int n2)
{
  if (!a)
    return NULL;
  TARVB *resp = a, *aux;
  int i, j;

  for (i = 0; i <= a->nchaves; i++)
  {
    if ((resp->chave[i] == n1) || (resp->chave[i] == n2))
    {
      printf("a: %d, ", resp->chave[i]);
    }
    intervalo(a->filho[i], n1, n2);
  }

  // return resp;
  return NULL;
}

TLSE *mk(TARVB *a, int k)
{
  if (!a)
    return NULL;
  TLSE *resp = inicializa();
  int i = 0, j;

  while ((i < a->nchaves) && (a->chave[i] < k))
    i++;

  for (j = i; j <= a->nchaves; j++) //percore os ponteiros
  {
    TLSE *aux = mk(a->filho[j], k);
    if (j < a->nchaves)
      resp = insere_ini(resp, a->chave[j]); // dependendo para manter ordenado teria que inserir no fim
    resp = junta_listas(resp, aux);
  }
  return resp;
}

TLSE *mx(TARVB *a, int x)
{
  if (!a)
    return NULL;
  TARVB *resp = a;
  TLSE *aux = inicializa();
  int i, j;

  for (i = 0; i <= a->nchaves; i++)
  {
    if (resp->chave[i] < x)
    {
      printf("a: %d\n", resp->chave[i]);
      aux = insere_ini(aux, resp->chave[i]);
    }
    mx(a->filho[i], x);
  }
  return aux;
}
//ultimo elemento da arvore
int maior_chave(TARVB *a)
{
  if (!a)
    return -1;
  TARVB *resp = a;
  int i, j, aux;
  for (i = 0; i <= resp->nchaves; i++)
  {
    if ((resp->folha) && (resp->chave[i] != 0))
    {
      // printf("a: %d\n", resp->chave[i]);
      aux = resp->chave[i];
    }
    maior_chave(resp->filho[i]);
  }
  // printf("aux: %d\n", aux);
  return aux;
}

int menor_chave(TARVB *a)
{
}
//1
int conta_nos(TARVB *a)
{
  if (!a)
    return 0;
  if (a->folha == 1)
    return 1;
  int i, cont = 0;
  for (i = 0; i <= a->nchaves; i++)
    cont = cont + conta_nos(a->filho[i]);
  return cont + 1;
}
//2
int conta_chaves(TARVB *a)
{
  if (!a)
    return 0;
  int i, resp = a->nchaves;
  for (i = 0; i <= a->nchaves; i++)
    resp = resp + conta_chaves(a->filho[i]);
  return resp;
}
//3
int altura(TARVB *a)
{
  if (!a)
    return 0;
  if (a->folha == 1)
    return 1;
  return 1 + altura(a->filho[0]);
}
//4
int soma_chaves(TARVB *a)
{
  if (!a)
    return 0;
  int i, soma = 0;
  for (i = 0; i < a->nchaves; i++)
  {
    soma = soma + a->chave[i];
  }
  if (a->folha == 1)
    return soma;
  for (i = 0; i < a->nchaves; i++)
  {
    soma = soma + soma_chaves(a->filho[i]);
  }
  return soma;
}
//5
int pares(TARVB *a)
{
  if (!a)
    return 0;
  int i, cont = 0, ret = 0;
  for (i = 0; i < a->nchaves; i++)
  {
    if (a->chave[i] % 2 == 0)
      cont++;
  }
  if (a->folha == 1)
    return cont;
  for (i = 0; i < a->nchaves; i++)
  {
    ret = ret + pares(a->filho[i]);
  }
  return ret + cont;
}
//8
int qtd_chaves_maiores(TARVB *a, int x)
{
  if (!a)
    return 0;
  int i, cont = 0;
  for (i = 0; i < a->nchaves; i++)
    if (a->folha == 1)
      return cont;
  for (i = 0; i < a->nchaves; i++)
    if (a->chave[i] > x)
      cont += qtd_chaves_maiores(a->filho[i], x);
  cont += qtd_chaves_maiores(a->filho[i], x);
  return cont;
}
//9
int predecessor(TARVB *a, int x)
{
  if (!a)
    return x;
  int i, pred, comp;
  if (menor_chave(a) >= x)
    return x;
  for (i = 0; i < a->nchaves; i++)
    if (a->chave[i] < x)
      pred = a->chave[i];
  if (a->folha == 0)
  {
    for (i = 0; i < a->nchaves; i++)
      comp = predecessor(a->filho[i], x);
    if (comp > pred)
      pred = comp;
  }
  return pred;
}

void remove_multiplos(TARVB *arvore, int x)
{
}

int main(int argc, char *argv[])
{
  TARVB *arvore = TARVB_Inicializa();
  int t = 2;
  printf(" t = %d\n", t);
  if (t < 2)
    t = 2;
  int num = 0, from, to;

  arvore = TARVB_Insere(arvore, 1, t);
  arvore = TARVB_Insere(arvore, 64, t);
  arvore = TARVB_Insere(arvore, 12, t);
  arvore = TARVB_Insere(arvore, 18, t);
  arvore = TARVB_Insere(arvore, 66, t);
  arvore = TARVB_Insere(arvore, 38, t);
  arvore = TARVB_Insere(arvore, 95, t);
  arvore = TARVB_Insere(arvore, 58, t);
  arvore = TARVB_Insere(arvore, 59, t);
  arvore = TARVB_Insere(arvore, 70, t);
  arvore = TARVB_Insere(arvore, 68, t);
  arvore = TARVB_Insere(arvore, 39, t);
  arvore = TARVB_Insere(arvore, 62, t);
  arvore = TARVB_Insere(arvore, 7, t);
  arvore = TARVB_Insere(arvore, 55, t);
  arvore = TARVB_Insere(arvore, 43, t);
  arvore = TARVB_Insere(arvore, 16, t);
  arvore = TARVB_Insere(arvore, 67, t);
  arvore = TARVB_Insere(arvore, 34, t);
  arvore = TARVB_Insere(arvore, 35, t);

  TARVB_Imprime(arvore);

  printf("\n----- Retorna TARVB ----- \n"); 
  printf("Maior_numero_chaves\n");
  TARVB_Imprime(maior_numero_chaves(arvore));

//Retorna lista
  printf("\n----- Retorna lista ----- \n"); 

  int n1 = 70;
  int n2 = 34;
  printf("Intervalo N1 = %d e N2 = %d\n", n1, n2);
  // TLSE *l = intervalo(arvore, n1, n2);
  // imprime(l);
  // libera(l);
  printf("\n");

  int k = 58;
  printf("Elementos maiores que k = %d\n", k);
  // TLSE *l2 = mk(arvore, k);
  // imprime(l2);
  // libera(l2);
  printf("\n");

  int x = 34;
  printf("Elementos menores que x = %d\n", x);
  // TLSE *l3 = mx(arvore, x);
  // imprime(l3);
  // libera(l3);

// Retorna inteiro
  printf("\n----- Retorna inteiro ----- \n"); 

  printf("Maior chave"); //Not ok
  int maior = maior_chave(arvore);
  printf("= %d\n", maior);

  printf("Menor chave"); // Not ok
  int menor = menor_chave(arvore);
  printf("= %d\n", menor);

  printf("conta_nos"); //Ok!
  int cont_nos = conta_nos(arvore);
  printf("= %d \n", cont_nos);

  printf("conta_chaves"); //Ok!
  int cont_ch = conta_chaves(arvore);
  printf("= %d \n", cont_ch);

  printf("altura"); //Ok!
  int alt = altura(arvore);
  printf("= %d \n", alt);

  printf("soma_chaves"); //Not ok
  int sum = soma_chaves(arvore);
  printf("= %d \n", sum);

  printf("pares"); //Not ok
  int par = pares(arvore);
  printf("= %d \n", par);

  printf("qtd_chaves_maiores"); //Not ok
  int ch_maior = qtd_chaves_maiores(arvore, 15);
  printf("= %d \n", ch_maior);

  printf("Predecessor"); //Not Ok
  int pred = predecessor(arvore, 7);
  printf("= %d \n", pred);

  // TARVB_Imprime(arvore);
  int m = 3;
  printf("remove_multiplos de x = %d\n", m);
  remove_multiplos(arvore, m); //Not ok
  // TARVB_Imprime(arvore);

  TARVB_Libera(arvore);
}