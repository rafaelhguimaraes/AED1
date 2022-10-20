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
Operação cria_pilha:
Entrada: Nenhuma
Pré- Condição: Nenhuma
Processo:Cria uma pilha e a coloca em estado de pilha vazia
Saída: Endereço da pilha criada
Pós- Condição: Nenhuma
*/

Pilha cria_pilha(){

    return NULL;
}

/*
Operação pilha_vazia:
Entrada: Endereço da pilha
Pré-Condição: Nenhuma
Pocesso: Verifica se a pilha está vazia
Saída: Retorna 1 se a pilha esta vazia ou 0 caso não vazia
Pós- Condição: Nenhuma
*/

int pilha_vazia (Pilha p) {

    if (p == NULL)
        return 1; //Pilha vazia

    else
        return 0; //Falha, Pilha não vazia
}


/*
Operação pilha_cheia:
– Não existe pilha cheia na implementação
dinâmica/encadeada

– Tamanho da pilha é limitada pelo espaço de
memória
*/

/*
Operação Apaga_Pilha
Entrada: Endereço da pilha
Pré-Condição: Pilha existir
Processo: Passa a pilha para o estado de vazia
Saída: Retorna 1 se a operção foi bem sucessida ou 0 caso falha
Pós-Condição: A pilha apagada

Saida: p == NULL
*/
int apaga_pilha(Pilha *p) //Passagem por referencia (Vamos alterar ela)
{

    Pilha aux;

    while(*p != NULL ){ //Enquanto existir nó
    aux = *p; //No do topo
    *p = aux->prox; //Anda pela pilha

    free(aux); //Libera o no apontado por aux
    }
    free(p);

    return 1; //Sucesso
}

/*
Operação Esvazia_Pilha
Entrada: Endereço da pilha
Pré-Condição: Pilha existir
Processo: Passa a pilha para o estado de vazia
Saída: Retorna 1 se a operção foi bem sucessida ou 0 caso falha
Pós-Condição: A pilha de entrada sem os elementos
*/

int esvazia_pilha(Pilha *p) //Passagem por referencia (Vamos alterar ela)
{

    Pilha aux;

    while(*p != NULL ){ //Enquanto existir nó
    aux = *p; //No do topo
    *p = aux->prox; //Anda pela pilha

    free(aux); //Libera o no apontado por aux
    }

    return 1; //Sucesso
}


/*
Operação empilha (push):
Entrada: Endereço da pilha e o elemento a ser inserido
Pré-Condição: Pilha não estar cheia
Processo: Inserir o elemento no topo da pilha
Saída: Retorna 1 se sucesso 0 se falha
Pós-Condição: a pilha com um elemento a mais

– Aloca um novo nó
– Preenche os campos do novo nó
• Campo info recebe o valor do elemento
• Campo prox recebe o endereço do topo da pilha
– Faz a pilha apontar para o novo nó
• SIMILAR à operação insere_elem() da lista

OBS: Ambas inserem o elemento no INICIO da
estrutura (1º nó = topo da pilha)
*/

int push (Pilha *p, int elem) {

    Pilha N = (Pilha) malloc(sizeof(struct no));

    if (N == NULL) //Verifica se Novo nó foi alocado corretamente
        return 0; //Falha

    N->info = elem; //Campo info recebe o elemento a ser inserido
    N->prox = *p; // Campo prox do novo nó recebe a posição do elemento no topo da Pilha

    *p = N; //Pilha aponta para o ultimo novo nó da inserido na Pilha (Novo topo)

    return 1; //Sucesso
}


/*
Operação desempilha (pop):
Entrada: Endereço da pilha e o endereço de retorno do elemento do topo da pilha
Pré-Condição: Pilha não existir e não estar vazia
Processo: Remove o elemento que está no topo da pilha e retorna-lo
Saída: Retorna 1 se Sucesso e 0 se Falha
Pós-Condição: Pilha de entrada sem um elemento e o retorno do valor removido

– Remove o elemento que está no topo da Pilha
• Pilha passa a apontar para o sucessor do topo
• Libera memória alocada pelo antigo topo

OBS: – Retorna o valor do elemento removido
• Valor é armazenado na variável de retorno
*/

int pop (Pilha *p, int *elem) {

    if (pilha_vazia(*p) == 1)
        return 0;

    Pilha aux = *p; //Aux recebe o primeiro nó da Pilha

    *elem = aux->info; //Elem recebe o elemento que está no topo
    *p = aux->prox; //Pilha passa (Topo) passa apontar para o nó abaixo

    free(aux); //Libera nó auxiliar

    return 1; //Sucesso
}

/*
Operação le_topo:
Entrada: Endereço da pilha
Pré-Condição: Pilha existir
Processo: Le o valor no topo da pilha e retorna o seu valor sem remove-lo
Saída: Valor do elemento no topo
Pós-Condição: Nenhum

– Simplificação do código da operação pop()
• Retorna o elemento sem removê-lo
*/

int le_topo (Pilha p, int *elem) {

    if (pilha_vazia(p) == 1)
        return 0;

    *elem = (p)->info; //Acessa o nó a´pontado por p (topo) e pega o conteudo do campo info para retorno por referencia

    return 1; //Sucesso
}

