#include <stdlib.h>
#include "PilhaInt.h"

/*
Estrutura no
campo info para inteiros
campo prox do tipo struct
*/

struct no{
int info;
struct no *prox;
};

/*
Opera��o cria_pilha:
Entrada: Nenhuma
Pr�- Condi��o: Nenhuma
Processo:Cria uma pilha e a coloca em estado de pilha vazia
Sa�da: Endere�o da pilha criada
P�s- Condi��o: Nenhuma
*/

Pilha cria_pilha(){

    return NULL;
}

/*
Opera��o pilha_vazia:
Entrada: Endere�o da pilha
Pr�-Condi��o: Nenhuma
Pocesso: Verifica se a pilha est� vazia
Sa�da: Retorna 1 se a pilha esta vazia ou 0 caso n�o vazia
P�s- Condi��o: Nenhuma
*/

int pilha_vazia (Pilha p) {

    if (p == NULL)
        return 1; //Pilha vazia

    else
        return 0; //Falha, Pilha n�o vazia
}


/*
Opera��o pilha_cheia:
� N�o existe pilha cheia na implementa��o
din�mica/encadeada

� Tamanho da pilha � limitada pelo espa�o de
mem�ria
*/

/*
Opera��o Apaga_Pilha
Entrada: Endere�o da pilha
Pr�-Condi��o: Pilha existir
Processo: Passa a pilha para o estado de vazia
Sa�da: Retorna 1 se a oper��o foi bem sucessida ou 0 caso falha
P�s-Condi��o: A pilha apagada

Saida: p == NULL
*/
int apaga_pilha(Pilha *p) //Passagem por referencia (Vamos alterar ela)
{

    Pilha aux;

    while(*p != NULL ){ //Enquanto existir n�
    aux = *p; //No do topo
    *p = aux->prox; //Anda pela pilha

    free(aux); //Libera o no apontado por aux
    }
    free(p);

    return 1; //Sucesso
}

/*
Opera��o Esvazia_Pilha
Entrada: Endere�o da pilha
Pr�-Condi��o: Pilha existir
Processo: Passa a pilha para o estado de vazia
Sa�da: Retorna 1 se a oper��o foi bem sucessida ou 0 caso falha
P�s-Condi��o: A pilha de entrada sem os elementos
*/

int esvazia_pilha(Pilha *p) //Passagem por referencia (Vamos alterar ela)
{

    Pilha aux;

    while(*p != NULL ){ //Enquanto existir n�
    aux = *p; //No do topo
    *p = aux->prox; //Anda pela pilha

    free(aux); //Libera o no apontado por aux
    }

    return 1; //Sucesso
}


/*
Opera��o empilha (push):
Entrada: Endere�o da pilha e o elemento a ser inserido
Pr�-Condi��o: Pilha n�o estar cheia
Processo: Inserir o elemento no topo da pilha
Sa�da: Retorna 1 se sucesso 0 se falha
P�s-Condi��o: a pilha com um elemento a mais

� Aloca um novo n�
� Preenche os campos do novo n�
� Campo info recebe o valor do elemento
� Campo prox recebe o endere�o do topo da pilha
� Faz a pilha apontar para o novo n�
� SIMILAR � opera��o insere_elem() da lista

OBS: Ambas inserem o elemento no INICIO da
estrutura (1� n� = topo da pilha)
*/

int push (Pilha *p, int elem) {

    Pilha N = (Pilha) malloc(sizeof(struct no));

    if (N == NULL) //Verifica se Novo n� foi alocado corretamente
        return 0; //Falha

    N->info = elem; //Campo info recebe o elemento a ser inserido
    N->prox = *p; // Campo prox do novo n� recebe a posi��o do elemento no topo da Pilha

    *p = N; //Pilha aponta para o ultimo novo n� da inserido na Pilha (Novo topo)

    return 1; //Sucesso
}


/*
Opera��o desempilha (pop):
Entrada: Endere�o da pilha e o endere�o de retorno do elemento do topo da pilha
Pr�-Condi��o: Pilha n�o existir e n�o estar vazia
Processo: Remove o elemento que est� no topo da pilha e retorna-lo
Sa�da: Retorna 1 se Sucesso e 0 se Falha
P�s-Condi��o: Pilha de entrada sem um elemento e o retorno do valor removido

� Remove o elemento que est� no topo da Pilha
� Pilha passa a apontar para o sucessor do topo
� Libera mem�ria alocada pelo antigo topo

OBS: � Retorna o valor do elemento removido
� Valor � armazenado na vari�vel de retorno
*/

int pop (Pilha *p, int *elem) {

    if (pilha_vazia(*p) == 1)
        return 0;

    Pilha aux = *p; //Aux recebe o primeiro n� da Pilha

    *elem = aux->info; //Elem recebe o elemento que est� no topo
    *p = aux->prox; //Pilha passa (Topo) passa apontar para o n� abaixo

    free(aux); //Libera n� auxiliar

    return 1; //Sucesso
}

/*
Opera��o le_topo:
Entrada: Endere�o da pilha
Pr�-Condi��o: Pilha existir
Processo: Le o valor no topo da pilha e retorna o seu valor sem remove-lo
Sa�da: Valor do elemento no topo
P�s-Condi��o: Nenhum

� Simplifica��o do c�digo da opera��o pop()
� Retorna o elemento sem remov�-lo
*/

int le_topo (Pilha p, int *elem) {

    if (pilha_vazia(p) == 1)
        return 0;

    *elem = (p)->info; //Acessa o n� a�pontado por p (topo) e pega o conteudo do campo info para retorno por referencia

    return 1; //Sucesso
}

