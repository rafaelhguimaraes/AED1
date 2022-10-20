#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fpd.h"

struct no
{
    Pessoa paciente;
    struct no *prox;
};

/*
    ======== Operação cria_fila:

    - Entrada: Nenhuma
    - Pré-condição: Nenhuma
    - Processo: Retorna NULL
    - Saída: NULL
    - Pós-condição: Nenhuma
*/

Fila cria_fila ()
{
    return NULL;
}

/*
    ======== Operação fila_vazia:

    - Entrada: Endereço da fila
    - Pré-condição: Fila ser válida
    - Processo: Verifica se a fila é NULL
    - Saída: Retorna 1 se ela for NULL 0 caso não
    - Pós-condição: Nenhuma
*/

int fila_vazia (Fila f)
{
    if (f == NULL)
        return 1;
    else
        return 0;
}

/*
    ======== Operação: insere_ord

    - Entrada: endereço da fila, variável do tipo Pessoa
    - Pré-condições: fila não ser inválida
    - Processo: adiciona de forma ordenada na fila
    - Saída: 1 caso tenha inserido ou 0 caso o contrário
    - Pós-condição: fila com mais um elemento
*/

int insere_ord (Fila *f, Pessoa elem)
{

    Fila N = (Fila)malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N -> paciente = elem;

    if (fila_vazia(*f))
    {
        N -> prox = N;
        *f = N;
    }
    else
    {
        Fila aux = *f;
        while (aux->prox != *f)
            aux = aux->prox;


        if (aux->prox == *f)
        {
            aux = aux->prox;
            N->prox = aux->prox;
            aux->prox = N;
            *f = N;
        }
        else
        {
            N->prox = aux->prox;
            aux->prox = N;
        }
    }


    return 1;
}

/*
    ========Operação remove_inicio:

    - Entrada: Endereço da fila e endereço de elem
    - Pré-condição: Fila não estar vazia
    - Processo: Remove do início da fila
    - Saída: Retorna 1 caso tenha dado certo e 0 caso não
    - Pós-condição: Fila com menos um elemento
*/
/*
int remove_ini (Fila *f, Pessoa *elem)
{
    if (fila_vazia(*f))
        return 0;

    Fila aux = (*f) -> prox;
    while (aux->prox != *f && aux->prox->paciente.gravidade > elem->gravidade)
        *elem = aux -> paciente;

    if (*f ==  (*f) -> prox )
        *f = NULL;
    else {
        if(aux->prox->paciente.gravidade > elem->gravidade)
        (*f) -> prox = aux -> prox;
    }
    free (aux);

    return 1;
}

int remove_ini(Fila *fila, Pessoa* elem){
    if(fila_vazia(*fila)) return 0;

    Pessoa maior = (*fila)->paciente;
    Fila tmp = (*fila)->prox, tmp2 = *fila;
    while(tmp != NULL){
        if(tmp->paciente.gravidade > maior.gravidade){
            tmp2 = tmp; // ate aqui tmp2 eh o maior
            maior = tmp->paciente;
        }
        tmp = tmp->prox;
    }

    // tmp2 vai ser deletado
    if(*fila == tmp2) *fila = tmp2->prox;
    *elem = tmp2->paciente;

    free(tmp2);
    return 1;
}


    ========Operação esvazia_fila:

    - Entrada: Endereço da fila
    - Pré-condição: Nenhuma
    - Processo: processo do apaga_fila(f)
    - Saída: retorna apaga_fila(f)
    - Pós-condição: Nenhuma
*/
int remove_ini (Fila *f, Pessoa *elem)
{
    if (fila_vazia(*f))
        return 0;

    Fila aux = (*f) -> prox;
    *elem = aux -> paciente;

    if (*f ==  (*f) -> prox)
        *f = NULL;
    else
        (*f) -> prox = aux -> prox;

    free (aux);

    return 1;
}
/*
int remove_maior(Fila *fila, Pessoa *elem)
{

    if(fila==NULL)
        return 0;
    if(fila_vazia(*fila)==1)
        return 0;
    if(*fila==(*fila)->prox)
    {
        *elem = (*fila)->paciente;
        free(*fila);
        *fila=NULL;
        return 1;
    }

    Fila aux= *fila;
    Fila aux2= aux->prox;
    int grav = 0;
    int grav2 = 0;
    grav = (*fila)->paciente.gravidade;
    grav2 = aux->paciente.gravidade;
    printf("\n\n\ngravidade 1: %d \n\n\n\n", grav);
    printf("\n\n\ngravidade 2: %d \n\n\n\n", grav2);
    while( aux->prox != *fila)
    {
        grav = aux->paciente.gravidade;
        //printf("gravidade: %d ", &grav);
        if(aux2->prox->paciente.gravidade > aux->paciente.gravidade){
            aux2 = aux; ///AUX2 = MAIOR
            printf("\n\n\n\t\tEEEEEEEEENTROUUUUUUUUUUUUUU\n\n\n");
        }

        printf("SAIU DO IF");
        aux2 = aux2->prox;
        aux =  aux -> prox;

    }

    if(*fila==(*fila)->prox)
    {
        *elem = (*fila)->paciente;
        free(*fila);
        *fila=NULL;
        printf("\n==FILA VAZIA==");
        return 1;
    }
    if(aux2->prox == *fila){
        *fila = aux2;

    }

    *elem = aux2->prox-> paciente;
    aux = aux2->prox;
    aux2->prox = aux->prox;
    free(aux);
    return 1;
}
*/
int remove_maior(Fila *fila, Pessoa *elem){

    if(fila==NULL)
        return 0;
    if(fila_vazia(*fila)==1)
        return 0;
    if(*fila==(*fila)->prox)
    {
        *elem = (*fila)->paciente;
        free(*fila);
        *fila=NULL;
        return 1;
    }

    Fila aux = (*fila)->prox;
    Fila aux2 = *fila;
    Fila maior = aux;
    while(aux->prox != (*fila)->prox){
        if(aux->prox->paciente.gravidade > maior->paciente.gravidade){
            maior = aux->prox;
            aux2 = aux;
        }
        aux = aux->prox;
    }

    *elem = maior->paciente;
    aux2->prox = maior->prox;
    if(maior == *fila)
        *fila = aux2;
    free(maior);
    return 1;

}

int esvazia_fila (Fila *f)
{
    return apaga_fila(f);
}

/*
    ========Operação apaga_fila:

    - Entrada: Endereço da fila
    - Pré-condição: Fila ser vazia
    - Processo: Apaga a Fila
    - Saída: Retorna 1 caso tenha dado certo e 0 caso não
    - Pós-condição: Fila apagada
*/

int apaga_fila (Fila *f)
{
    if (fila_vazia(*f))
        return 0; //Falha

    while (*f != (*f)->prox)            // Condição para enquanto tem mais de um elemento na lista
    {
        Fila aux = (*f)->prox;
        (*f)->prox = aux->prox;
        free(aux);

    }
    Fila aux = *f;
    *f = NULL;
    free(aux);

    return 1;
}
/*
Pessoa maior_elemento(Fila lista)
{
    Fila aux=lista;

    Pessoa maior= aux->paciente;
    while(aux->prox !=(lista))
    {
        aux=aux->prox;
        if(aux->paciente.gravidade >maior)
        {
            maior=aux->info;
        }
    }
    return maior;
}
*/
