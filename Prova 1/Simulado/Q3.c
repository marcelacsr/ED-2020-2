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
        resp->vet[i] = NULL;
    resp->tam = tam;
    resp->ult_pos_ocup = -1;
    return resp;
}

void imprime(TEI *resp)
{
    int i;
    for (i = 0; i <= resp->ult_pos_ocup; i++)
        printf("%d: %d %s\n", resp->vet[i]->p_user, resp->vet[i]->id, resp->vet[i]->narq);
}

void retira(TEI *resp)
{
    if (resp->ult_pos_ocup == -1)
        return;
    TP *temp = resp->vet[0];
    int i;
    for (i = 0; i < resp->ult_pos_ocup; i++)
        resp->vet[i] = resp->vet[i + 1];
    resp->ult_pos_ocup--;
    free(temp);
}

// (a) aloca espaço para esse novo elemento
// (b) esse novo elemento de impressão será inserido
// depois do último elemento com p_user igual ao seu.
// Isto quer dizer que, em alguns casos, você terá que remanejar elementos.
void insere(TEI *resp, int p_user, int id, char *narq)
{
    if (resp->ult_pos_ocup == (resp->tam - 1))
        return;
    TP *novo = (TP *)malloc(sizeof(TP));
    novo->id = id;
    novo->p_user = p_user;
    strcpy(novo->narq, narq); //verificar se da pra fazer de outra forma
    int i;
    for (i = 0; i <= resp->ult_pos_ocup; i++)
    {
        if (p_user > resp->vet[i]->p_user)
        {
            break;
        }
    }
    resp->ult_pos_ocup = resp->ult_pos_ocup + 1;
    int j;
    for (j = resp->ult_pos_ocup; j > i; j--)
    {
        resp->vet[j] = resp->vet[j - 1];
    }
    resp->vet[i] = novo;
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
