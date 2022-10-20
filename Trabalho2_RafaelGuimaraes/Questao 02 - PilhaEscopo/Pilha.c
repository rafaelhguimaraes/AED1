#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#define MAX 20 //Tamanho da express�o

//OBS: Todas as fun��es de Pilha foram implementados caso aja uso necessario, mesmo n�o as utilizando de fato.

//Defini��o da Struct nof - Dinamic/Encadeada - Floats
struct nof{
    float info;
    struct nof *prox;

};

//Defini��o da Struct pilha - Estatic/Seq - Char
struct pilha {
    int info[MAX];
    int topo; //pode indicar a ultima posi��o ocupada
};
/*
� Retorna uma pilha no estado de vazia
� Topo igual a NULL
� Retorna o endere�o do topo (NULL)
*/
PilhaF cria_pilhaF(){

    return NULL;
}

/*
� Verifica se a pilha est� no estado de vazia
- Ponteiro da Pilha igual a NULL
*/
int pilha_vaziaF(PilhaF p){
if(p == NULL)
    return 1; //Vazia
else
    return 0; // N�o vazia
}
/*
� Aloca um novo n�
� Preenche os campos do novo n�
� Campo info recebe o valor do elemento
� Campo prox recebe o endere�o do topo da pilha
� Faz a pilha apontar para o novo n�
*/

int pushF(PilhaF *p, float elem){ // empilhar

    PilhaF N;
    N = (PilhaF)malloc(sizeof(struct nof)); // aloca��o novo no
    if(N==NULL) // Se a aloca��o do Novo no
        return 0;

    N->info = elem; //info recebe o valor do numero real
    N->prox = *p;         // N prox aponta para o no que a pilha aponta
    *p = N;                 // Pilha aponta pra N

    return 1; //Sucesso
}

/*
� Remove o elemento que est� no topo da Pilha
� Pilha passa a apontar para o sucessor do topo
� Libera mem�ria alocada pelo antigo topo
� Retorna o valor do elemento removido
� Valor � armazenado na vari�vel de retorno
*/

int popF(PilhaF *p, float *elem){

    if((*p)== NULL || pilha_vaziaF(*p) == 1) // Pilha existe ou Pilha vazia
        return 0;

    PilhaF aux = *p;

    *elem = (*p)->info;
    *p = aux->prox;
    free(aux);

    return 1;
}

/*
� Simplifica��o do c�digo da opera��o pop()
- Retorna o elemento sem remov�-lo
*/

int le_topoF(PilhaF *p, float *elem){

    if(pilha_vaziaF(*p) == 1) //Ponteiro nulo ou pilha vazia
        return 0;

    *elem = (*p)->info;

    return 1;
}

int esvazia_pilhaF(PilhaF *p){
    while(*p != NULL){
        PilhaF aux = *p;
        *p = (*p)->prox;
        free(aux);
    }
 return 1;
}

int apaga_pilhaF(PilhaF *p){
    if(p != NULL){
        free(*p);
        *p = NULL;
    }
    return 1;
}

//====================================================
// TRATAMENTO DA PILHA CHAR ESTATICA/SEQUENCIAL


/*
Opera��o Cria_Pilha:
� Entrada: nenhuma
� Pr�-condi��o: nenhuma
� Processo: cria uma pilha e a coloca no estado
de pilha vazia
� Sa�da: endere�o da pilha criada
� P�s-condi��o: nenhuma
*/

PilhaC cria_pilhaC()
{
    PilhaC p;
    p = (PilhaC) malloc (sizeof (struct pilha));

    if (p != NULL)
        p->topo = -1; //Estado de vazia

    return p; //Retorna o endere�o da pilha alocada
}


/*
Opera��o Pilha_Vazia:
� Entrada: endere�o da pilha
� Pr�-condi��o: nenhuma
� Processo: verifica se a pilha est� vazia
� Sa�da: retorna 1 se pilha vazia ou 0 caso
contr�rio
� P�s-condi��o: nenhuma
*/
//Pilha Vazia:
// � TOPO aponta para uma posi��o inv�lida topo == -1
//� Verifica se a pilha est� na condi��o de vazia

int pilha_vaziaC (PilhaC p)
{
    if (p->topo == -1)
        return 1; //Pilha esta vazia

    else
        return 0; //Pilha n�o vazia
}

/*
Opera��o Pilha_Cheia:
� Entrada: endere�o da pilha
� Pr�-condi��o: nenhuma
� Processo: verifica se a pilha est� cheia
� Sa�da: retorna 1 se pilha cheia ou 0 caso
contr�rio
� P�s-condi��o: nenhuma
*/

//� Verifica se a pilha est� na condi��o de cheia

int pilha_cheiaC (PilhaC p)
{
    if (p->topo == MAX-1) //De 0 a Max-1
        return 1; //Pilha cheia

    else
        return 0; //
}

/*
Opera��o Empilha (push):
� Entrada: endere�o da pilha e o elemento a ser
inserido
� Pr�-condi��o: pilha n�o estar cheia
� Processo: inserir o elemento informado no topo
da pilha
� Sa�da: retorna 1 se a opera��o foi bem
sucedida ou 0 caso contr�rio
� P�s-condi��o: a pilha de entrada com um
elemento a mais
*/

//� Incrementa o indicador de topo
//� Insere o elemento no topo da pilha

int pushC (PilhaC p, char elem)
{
    if (p == NULL || pilha_cheiaC(p) == 1) //Verifica se ela foi alocada (Se a Pilha existe)
        return 0;                         // Se a Pilha est� cheia n�o pode inserir


// Insere o elemento no topo
    p->topo++;
    p->info[p->topo] = elem;

    return 1;
}


/*
Opera��o Desempilha (pop):
� Entrada: endere�o da pilha e o endere�o de
retorno do elemento do topo da pilha
� Pr�-condi��o: pilha n�o estar vazia
� Processo: remover o elemento que est� no
topo da pilha e retorn�-lo
� Sa�da: retorna 1 se a opera��o foi bem
sucedida ou 0 caso contr�rio
� P�s-condi��o: a pilha de entrada com um
elemento a menos e a vari�vel de retorno com o
elemento removido
*/

//� Remove o elemento do topo da pilha
//- Decrementa o indicador de topo
//� Retorna o valor do elemento (por refer�ncia)

int popC (PilhaC p, char *elem)
{
    if (p == NULL || pilha_vaziaC(p) == 1){ //Verifica se ela foi alocada (Se a Pilha existe) ou vazia n�o tem o que remover
        return 0; //Falha na inser��o
    }

        *elem = p->info[p->topo]; // Retorna o elemento
        p->topo--; // Remove o elemento do topo

        return 1;

}


//Faz a captura do elemento ques t� no topo da pilha sem removelo
/*
Entrada:Endere�o de um pilha e uma variavel de retorno
Pre-Condi��o: Pilha n�o estar vazia
Processo: Faz a captura do elemento ques t� no topo da pilha sem removelo
Sa�da: 1 - Sucesso
       0 - Falha
P�s-Condi��o: Nenhuma

*/

int le_topoC(PilhaC p, char *elem){

    if(pilha_vaziaC(p) == 1) //Ponteiro nulo ou pilha vazia
        return 0;

    *elem = p->info[p->topo];

    return 1;
}

int esvazia_pilhaC(PilhaC p){
    PilhaC aux = p->topo;
    while(p->topo != -1){


        p->topo--;
        free(aux);
    }
 return 1;
}

int apaga_pilhaC(PilhaC *p){
    if(p != NULL){
        free(*p);
        *p = NULL;
    }
    return 1;
}
