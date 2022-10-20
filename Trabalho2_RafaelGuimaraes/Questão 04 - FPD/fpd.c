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
    ======== Opera��o cria_fila:

    - Entrada: Nenhuma
    - Pr�-condi��o: Nenhuma
    - Processo: Retorna NULL
    - Sa�da: NULL
    - P�s-condi��o: Nenhuma
*/

Fila cria_fila ()
{
    return NULL;
}

/*
    ======== Opera��o fila_vazia:

    - Entrada: Endere�o da fila
    - Pr�-condi��o: Fila ser v�lida
    - Processo: Verifica se a fila � NULL
    - Sa�da: Retorna 1 se ela for NULL 0 caso n�o
    - P�s-condi��o: Nenhuma
*/

int fila_vazia (Fila f)
{
    if (f == NULL)
        return 1;
    else
        return 0;
}

/*
    ======== Opera��o: insere_ord

    - Entrada: endere�o da fila, vari�vel do tipo Pessoa
    - Pr�-condi��es: fila n�o ser inv�lida
    - Processo: adiciona de forma ordenada na fila
    - Sa�da: 1 caso tenha inserido ou 0 caso o contr�rio
    - P�s-condi��o: fila com mais um elemento
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
    ========Opera��o remove_inicio:

    - Entrada: Endere�o da fila e endere�o de elem
    - Pr�-condi��o: Fila n�o estar vazia
    - Processo: Remove do in�cio da fila
    - Sa�da: Retorna 1 caso tenha dado certo e 0 caso n�o
    - P�s-condi��o: Fila com menos um elemento
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


    ========Opera��o esvazia_fila:

    - Entrada: Endere�o da fila
    - Pr�-condi��o: Nenhuma
    - Processo: processo do apaga_fila(f)
    - Sa�da: retorna apaga_fila(f)
    - P�s-condi��o: Nenhuma
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
    ========Opera��o apaga_fila:

    - Entrada: Endere�o da fila
    - Pr�-condi��o: Fila ser vazia
    - Processo: Apaga a Fila
    - Sa�da: Retorna 1 caso tenha dado certo e 0 caso n�o
    - P�s-condi��o: Fila apagada
*/

int apaga_fila (Fila *f)
{
    if (fila_vazia(*f))
        return 0; //Falha

    while (*f != (*f)->prox)            // Condi��o para enquanto tem mais de um elemento na lista
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
