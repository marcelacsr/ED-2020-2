#include <stdlib.h>
#include <stdio.h>

#include "lib/tlse.h"
// 1-A
// (a) Escreva uma função que receba uma lista l e um inteiro x,
// insira o elemento
// x – 1 antes de cada x e o elemento
// x + 1 depois de cada x, respectivamente.
// O prótotipo deste método é o seguinte: void misc(TLista* l, int x).
// Obs.: a sua função não pode criar uma
// lista auxiliar para realizar esta operação,
// isto é, as operações devem ser feitas em l.
void misc(TLSE *l, int x)
{
    TLSE *p = l, *ant = NULL, *nova = NULL;
    if (!p)
        return;
    while (p)
    {
        if (p->info == x)
        {
            nova = NULL;
            int temp = p->info;
            p->info = x - 1;
            nova = insere_ini(nova, x + 1);
            nova = insere_ini(nova, temp);
            TLSE *aux = p->prox;
            p->prox = nova;
            while (nova->prox)
                nova = nova->prox;
            nova->prox = aux;
            p = nova;
        }
        ant = p;
        p = p->prox;
    }
}

// 1-B
// (b) Escreva uma função em C que, dada uma lista,
// retire desta lista todos os elementos
// repetidos. Esta função deve retornar a lista modificada.
// O protótipo da função é o seguinte:
void remove_repetidos(TLSE *l)
{
    TLSE *p = l, *ant = NULL, *t = NULL;
    if (!l)
        return;
    while (p)
    {
        //sempre passa p->prox para que nao remova o primeiro elemento
        // enquanto encontrar o elemento existir (o busca retorna o elemento quando o encontra)
        while (busca(p->prox, p->info)) //verifico se no restante da lista tem o p->info
        {
            //remover retorna a lista sem o elemento p->info
            p->prox = remover(p->prox, p->info); //remove o p->info
        }
        p = p->prox;
    }
}

int main(void)
{
    TLSE *l = inicializa();
    l = insere_ini(l, 2);

    l = insere_ini(l, 2);
    l = insere_ini(l, 2);
    l = insere_ini(l, 777);

    l = insere_ini(l, 711);
    l = insere_ini(l, 137);
    l = insere_ini(l, 177);

    l = insere_ini(l, 197);
    l = insere_ini(l, 2);
    l = insere_ini(l, 217);

    l = insere_ini(l, 227);
    l = insere_ini(l, 237);
    l = insere_ini(l, 247);
    l = insere_ini(l, 2);
    l = insere_ini(l, 2);
    imprime(l);
    misc(l, 2);
    imprime(l);
    remove_repetidos(l);
    imprime(l);
}