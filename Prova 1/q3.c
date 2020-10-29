#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prior
{
    int p_user, id;
    char narq[31];
} TP;

typedef struct ei
{
    int tam, ult_pos_ocup;
    TP **vet;
} TEI;

TEI *inicializa(int tam)
{
    TEI *resp = (TEI *)malloc(sizeof(TEI));
    resp->vet = (TP **)malloc(sizeof(TP *) * tam);
    int i;
    for (i = 0; i < tam; i++)
    {
        resp->vet[i] = NULL;
    }
    resp->tam = tam;
    resp->ult_pos_ocup = -1;
    return resp;
}

void imprime(TEI *resp)
{
    int i;
    printf("\n[p_user, id, arq]\n");
    for (i = 0; i <= resp->ult_pos_ocup; i++)
        printf("[%d,  %d,  %s]\n", resp->vet[i]->p_user, resp->vet[i]->id,
               resp->vet[i]->narq);
}

void retira(TEI *resp)
{
    if (resp->ult_pos_ocup == -1)
        return;
    TP *temp = resp->vet[0]; // remove o primeiro
    int i;
    for (i = 0; i < resp->ult_pos_ocup; i++)
        resp->vet[i] = resp->vet[i + 1]; //realoca os elementos
    resp->ult_pos_ocup--;                // decrementa a flag
    free(temp);                          // remove o primeiro
}

// (a) aloca espaço para esse novo elemento
// (b) esse novo elemento de impressão será inserido depois do
//     último elemento com p_user igual ao seu.
// Isto quer dizer que, em alguns casos, você terá que remanejar elementos.
void insere(TEI *resp, int p_user, int id, char *narq)
{
    TP *novo = (TP *)malloc(sizeof(TP));
    novo->id = id;
    novo->p_user = p_user;
    strcpy(novo->narq, narq);
    int indice = resp->ult_pos_ocup; //guarda a ultima posicao no indice
    for (int i = 0; i < resp->ult_pos_ocup; i++) //percorre todo vetor
    {
        if (resp->vet[i]->p_user = p_user)
            indice = i; // retorna indice do elemento igual
    }
    resp->ult_pos_ocup++; //incrementa toda vez que for inserir
    for (int i = resp->ult_pos_ocup; i > indice; i--) //percorre o vetor de prior do maior pro menor
    {
        resp->vet[i] = resp->vet[i - 1]; // ultima pos recebe a antepenultima ate o indice
    }
    resp->vet[indice + 1] = novo; // a posicao vazia recebe o novo valor, caso nao entre no if, o indice sera o ultimo elemento do vetor
}

int main(void)
{
    int tam;
    scanf("%d", &tam);
    if (tam <= 0)
        return 0;
    TEI *fila = inicializa(tam);
    int i, n;
    do
    {
        scanf("%d", &n);
    } while ((n <= 0) || (n > tam));
    for (i = 0; i < n; i++)
    {
        TP aux;
        printf("p_user, id, arq\n");
        scanf("%d%d", &aux.p_user, &aux.id);
        scanf(" %30[^\n]", aux.narq);
        insere(fila, aux.p_user, aux.id, aux.narq);
    }
    imprime(fila);
    for (i = 0; i < n; i++)
        retira(fila);
    free(fila);
    return 0;
}
