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
  int maior, menor;
  if (n1 > n2)
  {
    maior = n1;
    menor = n2;
  }
  else
  {
    menor = n1;
    maior = n2;
  }
  TLSE *resp = inicializa();
  int i = 0, j;
  for (j = 0; j <= a->nchaves; j++) //percore os ponteiros
  {
    TLSE *aux = intervalo(a->filho[j], n1, n2);
    if ((j < a->nchaves) && (a->chave[j] != 0) && (a->chave[j] >= menor) && (a->chave[j] <= maior))
    {
      resp = insere_ini(resp, a->chave[j]);
    }
    resp = junta_listas(resp, aux);
  }
  return resp;
}

//maiores
TLSE *mk(TARVB *a, int k)
{
  if (!a)
    return NULL;
  TLSE *resp = inicializa();
  int i = 0, j;
  while ((i < a->nchaves) && (a->chave[i] < k)) //IMP para percorrer a arvore a partir de determinado elemento
    i++;
  for (j = i; j <= a->nchaves; j++) //percore os ponteiros
  {
    // printf("i: %d, j: %d\n", i, j);
    TLSE *aux = mk(a->filho[j], k);
    if ((j < a->nchaves) && (a->chave[j] != 0))
    {
      // printf("CHAVE: %d\n", a->chave[j]);
      resp = insere_ini(resp, a->chave[j]);
    }
    resp = junta_listas(resp, aux);
  }
  return resp;
}

//menores
TLSE *mx(TARVB *a, int k)
{
  if (!a)
    return NULL;
  TLSE *resp = inicializa();
  int i = 0, j;
  for (j = 0; j <= a->nchaves; j++) //percore os ponteiros
  {
    // printf("i: %d, j: %d\n", i, j);
    TLSE *aux = mx(a->filho[j], k);
    if ((j < a->nchaves) && (a->chave[j] != 0) && (a->chave[j] < k))
    {
      // printf("CHAVE: %d\n", a->chave[j]);
      resp = insere_ini(resp, a->chave[j]);
    }
    resp = junta_listas(resp, aux);
  }
  return resp;
}

//ultimo elemento da arvore
int maior_chave(TARVB *a)
{
  if (!a)
    return -1;
  TARVB *resp = a;
  int i = 0, j, aux;
  while ((resp->chave[i] != 0) && (i <= resp->nchaves))
  {
    aux = resp->chave[i];
    i++;
  }
  if (!resp->folha)
    aux = maior_chave(resp->filho[i]);
  return aux;
}

int menor_chave(TARVB *a)
{
  if (!a)
    return 0;
  if (a->folha)
    return a->chave[0];
  return menor_chave(a->filho[0]);
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
  if (a->folha)
    return 1;
  return 1 + altura(a->filho[0]);
}
//4
int soma_chaves(TARVB *a)
{
  if (!a)
    return 0;
  int i, soma = 0;
  for (i = 0; i <= a->nchaves; i++)
  {
    if (a->chave[i] != 0)
      soma = soma + a->chave[i];
  }
  if (a->folha)
    return soma;
  for (i = 0; i <= a->nchaves; i++)
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
  int i, cont = 0;
  for (i = 0; i <= a->nchaves; i++)
  {
    if ((a->chave[i] % 2) == 0 && a->chave[i] != 0)
      cont++;
  }
  if (a->folha)
    return cont;
  for (i = 0; i <= a->nchaves; i++)
  {
    cont = cont + pares(a->filho[i]);
  }
  return cont;
}
//8
int qtd_chaves_maiores(TARVB *a, int x)
{
  if (!a)
    return 0;
  int i, cont = 0;
  for (i = 0; i <= a->nchaves; i++)
  {
    if (a->chave[i] > x)
      cont++;
  }
  if (a->folha)
    return cont;

  for (i = 0; i <= a->nchaves; i++)
    cont += qtd_chaves_maiores(a->filho[i], x);
  return cont;
}
//9
// int pred_aux(TARVB *a, int ch)
// {
//   if (!a)
//     return 0;
//   int i = 0;
//   while ((i < a->nchaves) && ch >= a->chave[i])
//     i++;
//   if ((a->folha) && (i < a->nchaves)&&(a->chave[i]!=0))
//     return a->chave[i];
//   if ((a->folha) && (i == a->nchaves) && (a->chave[i - 1] <= ch)&&(a->chave[i]!=0))
//     return a->chave[i];
//   if ((i == a->nchaves) && (a->chave[i - 1] <= ch))
//     return pred_aux(a->filho[i], ch);
//   return pred_aux(a->filho[i], ch);
// }
int predecessor(TARVB *a, int ch) // NOTOK
{
  int i, pred, comp;
  if ((!a) || (ch == menor_chave(a)))
    return ch;
  for (i = 0; i < a->nchaves; i++)
  {
    if (a->chave[i] < ch)
    {
      // printf("pred: %d\n", a->chave[i]);
      pred = a->chave[i];
    }
  }
  if (!a->folha)
  {
    for (i = 0; i <= a->nchaves; i++)
    {
      comp = predecessor(a->filho[i], ch);
      // printf("\ncomp: %d \n", comp);
      if (comp > pred)
      {
        // printf("\ncomp: %d > pred: %d\n", comp, pred);
        pred = comp;
      }
    }
  }
  return pred;
}

TARVB *suc_aux(TARVB *a, int ch, TARVB *suc)
{
  if (!a)
    return NULL;
  int i = 0;
  while ((i < a->nchaves) && ch >= a->chave[i])
    i++;
  if ((a->folha) && (i < a->nchaves))
    return a;
  if ((a->folha) && (i == a->nchaves) && (a->chave[i - 1] <= ch))
    return suc;
  if ((i == a->nchaves) && (a->chave[i - 1] <= ch))
    return suc_aux(a->filho[i], ch, suc);
  return suc_aux(a->filho[i], ch, a);
}

TARVB *sucessor(TARVB *a, int ch)
{
  if ((!a) || (ch >= maior_chave(a)))
    return NULL;
  return suc_aux(a, ch, a);
}

int eh_mult(int x, int n)
{
  if (x % n == 0)
    return 1;
  else
    return 0;
}

void remove_multiplos(TARVB *a, int ch, int t)
{
  if (!a)
    return;
  int i, cont = 0;
  for (i = 0; i <= a->nchaves; i++)
  {
    if ((i < a->nchaves) && (eh_mult(a->chave[i], ch)) && (a->chave[i] != 0))
    {
      a = TARVB_Retira(a, a->chave[i], t);
    }
  }
  if (a->folha)
    return;
  for (i = 0; i <= a->nchaves; i++)
    remove_multiplos(a->filho[i], ch, t);
  return;
}

//funcao da calculadora

int main(int argc, char *argv[])
{
  TARVB *arvore = TARVB_Inicializa();
  int t = 2;
  printf(" t = %d\n", t);
  if (t < 2)
    t = 2;
  int num = 0, from, to;

  // arvore = TARVB_Insere(arvore, 1, t);
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
  arvore = TARVB_Insere(arvore, 96, t);
  // arvore = TARVB_Insere(arvore, 97, t);

  TARVB_Imprime(arvore);

  printf("\n----- Retorna TARVB ----- \n");
  printf("Maior_numero_chaves\n");
  TARVB_Imprime(maior_numero_chaves(arvore));

  //Retorna lista
  printf("\n----- Retorna lista ----- \n");

  int n1 = 70;
  int n2 = 34;
  printf("Intervalo N1 = %d e N2 = %d\n", n1, n2);
  TLSE *l = intervalo(arvore, n1, n2);
  imprime(l);
  libera(l);
  printf("\n");

  int k = 58;
  printf("Elementos maiores que k = %d\n", k);
  TLSE *l2 = mk(arvore, k);
  imprime(l2);
  libera(l2);
  printf("\n");

  int x = 50;
  printf("Elementos menores que x = %d\n", x);
  TLSE *l3 = mx(arvore, x);
  imprime(l3);
  libera(l3);

  // Retorna inteiro
  printf("\n----- Retorna inteiro ----- \n");

  printf("Maior chave"); //ok
  int maior = maior_chave(arvore);
  printf("= %d\n", maior);

  printf("Menor chave"); //ok
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

  printf("soma_chaves"); //ok!
  int sum = soma_chaves(arvore);
  printf("= %d \n", sum);

  printf("pares"); //ok
  int par = pares(arvore);
  printf("= %d \n", par);

  printf("qtd_chaves_maiores"); //ok
  int ch_maior = qtd_chaves_maiores(arvore, 64);
  printf("= %d \n", ch_maior);

  printf("Predecessor"); //notOk
  int pred = predecessor(arvore, 95);
  printf("= %d \n", pred);

  printf("Sucessor\n"); //Ok
  TARVB_Imprime(sucessor(arvore, 16));

  TARVB_Imprime(arvore);
  int m = 2;
  printf("remove_multiplos de x = %d\n", m);
  remove_multiplos(arvore, m, t); //ok
  TARVB_Imprime(arvore);

  TARVB_Libera(arvore);
}