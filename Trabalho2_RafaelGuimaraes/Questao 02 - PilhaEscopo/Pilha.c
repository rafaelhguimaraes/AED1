#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#define MAX 20 //Tamanho da expressão

//OBS: Todas as funções de Pilha foram implementados caso aja uso necessario, mesmo não as utilizando de fato.

//Definição da Struct nof - Dinamic/Encadeada - Floats
struct nof{
    float info;
    struct nof *prox;

};

//Definição da Struct pilha - Estatic/Seq - Char
struct pilha {
    int info[MAX];
    int topo; //pode indicar a ultima posição ocupada
};
/*
– Retorna uma pilha no estado de vazia
• Topo igual a NULL
– Retorna o endereço do topo (NULL)
*/
PilhaF cria_pilhaF(){

    return NULL;
}

/*
– Verifica se a pilha está no estado de vazia
- Ponteiro da Pilha igual a NULL
*/
int pilha_vaziaF(PilhaF p){
if(p == NULL)
    return 1; //Vazia
else
    return 0; // Não vazia
}
/*
– Aloca um novo nó
– Preenche os campos do novo nó
• Campo info recebe o valor do elemento
• Campo prox recebe o endereço do topo da pilha
– Faz a pilha apontar para o novo nó
*/

int pushF(PilhaF *p, float elem){ // empilhar

    PilhaF N;
    N = (PilhaF)malloc(sizeof(struct nof)); // alocação novo no
    if(N==NULL) // Se a alocação do Novo no
        return 0;

    N->info = elem; //info recebe o valor do numero real
    N->prox = *p;         // N prox aponta para o no que a pilha aponta
    *p = N;                 // Pilha aponta pra N

    return 1; //Sucesso
}

/*
– Remove o elemento que está no topo da Pilha
• Pilha passa a apontar para o sucessor do topo
• Libera memória alocada pelo antigo topo
– Retorna o valor do elemento removido
• Valor é armazenado na variável de retorno
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
– Simplificação do código da operação pop()
- Retorna o elemento sem removê-lo
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
Operação Cria_Pilha:
– Entrada: nenhuma
– Pré-condição: nenhuma
– Processo: cria uma pilha e a coloca no estado
de pilha vazia
– Saída: endereço da pilha criada
– Pós-condição: nenhuma
*/

PilhaC cria_pilhaC()
{
    PilhaC p;
    p = (PilhaC) malloc (sizeof (struct pilha));

    if (p != NULL)
        p->topo = -1; //Estado de vazia

    return p; //Retorna o endereço da pilha alocada
}


/*
Operação Pilha_Vazia:
– Entrada: endereço da pilha
– Pré-condição: nenhuma
– Processo: verifica se a pilha está vazia
– Saída: retorna 1 se pilha vazia ou 0 caso
contrário
– Pós-condição: nenhuma
*/
//Pilha Vazia:
// – TOPO aponta para uma posição inválida topo == -1
//– Verifica se a pilha está na condição de vazia

int pilha_vaziaC (PilhaC p)
{
    if (p->topo == -1)
        return 1; //Pilha esta vazia

    else
        return 0; //Pilha não vazia
}

/*
Operação Pilha_Cheia:
– Entrada: endereço da pilha
– Pré-condição: nenhuma
– Processo: verifica se a pilha está cheia
– Saída: retorna 1 se pilha cheia ou 0 caso
contrário
– Pós-condição: nenhuma
*/

//– Verifica se a pilha está na condição de cheia

int pilha_cheiaC (PilhaC p)
{
    if (p->topo == MAX-1) //De 0 a Max-1
        return 1; //Pilha cheia

    else
        return 0; //
}

/*
Operação Empilha (push):
– Entrada: endereço da pilha e o elemento a ser
inserido
– Pré-condição: pilha não estar cheia
– Processo: inserir o elemento informado no topo
da pilha
– Saída: retorna 1 se a operação foi bem
sucedida ou 0 caso contrário
– Pós-condição: a pilha de entrada com um
elemento a mais
*/

//– Incrementa o indicador de topo
//– Insere o elemento no topo da pilha

int pushC (PilhaC p, char elem)
{
    if (p == NULL || pilha_cheiaC(p) == 1) //Verifica se ela foi alocada (Se a Pilha existe)
        return 0;                         // Se a Pilha está cheia não pode inserir


// Insere o elemento no topo
    p->topo++;
    p->info[p->topo] = elem;

    return 1;
}


/*
Operação Desempilha (pop):
– Entrada: endereço da pilha e o endereço de
retorno do elemento do topo da pilha
– Pré-condição: pilha não estar vazia
– Processo: remover o elemento que está no
topo da pilha e retorná-lo
– Saída: retorna 1 se a operação foi bem
sucedida ou 0 caso contrário
– Pós-condição: a pilha de entrada com um
elemento a menos e a variável de retorno com o
elemento removido
*/

//– Remove o elemento do topo da pilha
//- Decrementa o indicador de topo
//– Retorna o valor do elemento (por referência)

int popC (PilhaC p, char *elem)
{
    if (p == NULL || pilha_vaziaC(p) == 1){ //Verifica se ela foi alocada (Se a Pilha existe) ou vazia não tem o que remover
        return 0; //Falha na inserção
    }

        *elem = p->info[p->topo]; // Retorna o elemento
        p->topo--; // Remove o elemento do topo

        return 1;

}


//Faz a captura do elemento ques tá no topo da pilha sem removelo
/*
Entrada:Endereço de um pilha e uma variavel de retorno
Pre-Condição: Pilha não estar vazia
Processo: Faz a captura do elemento ques tá no topo da pilha sem removelo
Saída: 1 - Sucesso
       0 - Falha
Pós-Condição: Nenhuma

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
