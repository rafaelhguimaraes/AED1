#include "deque.h"
#include <stdlib.h>
#include <string.h>

#define MAX_ELEM 10
#define MAX_STR 20

struct deque {
    char no[MAX_ELEM][MAX_STR];
    int ini;
    int cont;
};

/*
Opera��o: cria_deque
    -Entrada: nenhuma
    -Pr�-condi��o: nenhuma
    -Processo: cria um deque e o coloca no estado de vazio
    -Sa�da: endere�o do deque criado
    -P�s-condi��o: nenhuma
*/
Deque cria_deque() {
    Deque d;
    d = (Deque) malloc(sizeof(struct deque));
    if (d != NULL) {
        d->ini = 0;
        d->cont = 0;
    }
    return d;
}

/*
Opera��o: deque_vazio
    -Entrada: endere�o do deque
    -Pr�-condi��o: nenhuma
    -Processo: verifica se o deque est� vazio
    -Sa�da: 1 se o deque estiver vazio ou 0 caso contr�rio
    -P�s-condi��o: nenhuma
*/
int deque_vazio(Deque d) {
    if (d == NULL)
        return 0;
    if (d->cont==0)
        return 1;
    else
        return 0;
}

/*
Opera��o: deque_cheio
    -Entrada: endere�o do deque
    -Pr�-condi��o: nenhuma
    -Processo: verifica se o deque est� cheio
    -Sa�da: 1 se o deque estiver cheio ou 0 caso contr�rio
    -P�s-condi��o: nenhuma
*/
int deque_cheio(Deque d) {
    if (d == NULL)
        return 0;
    if (d->cont == MAX_ELEM)
        return 1;
    else
        return 0;
}

/*
Opera��o: insere_final
    -Entrada: endere�o do deque e o elemento a ser inserido
    -Pr�-condi��o: deque n�o estar cheio
    -Processo: inserir o elemento informado no final do deque
    -Sa�da: 1 - sucesso ou 0 - falha
    -P�s-condi��o: o deque de entrada com um elemento a mais
*/
int insere_final(Deque d, char elem[]) {
    if (d == NULL || deque_cheio(d) == 1)
        return 0;

    int fim = (d->ini + d->cont)%MAX_ELEM; // Calculo da posicao FINAL
    //d->fim = (d->fim+1)%MAX_ELEM;
    //d->no[d->fim] = elem;
    strcpy(d->no[fim], elem);
    d->cont++;

    return 1;
}

/*
Opera��o: insere_inicio
    -Entrada: endere�o do deque e o elemento a ser inserido
    -Pr�-condi��o: deque n�o estar cheio
    -Processo: inserir o elemento informado no inicio do deque
    -Sa�da: 1 - sucesso ou 0 - falha
    -P�s-condi��o: o deque de entrada com um elemento a mais
*/
int insere_inicio(Deque d, char elem[]) {
    if (d == NULL || deque_cheio(d) == 1)
        return 0;

    d->ini = (d->ini-1)%MAX_ELEM;
    strcpy(d->no[d->ini], elem);
    d->cont++;
    //d->no[d->ini] = elem);


    return 1;
}

/*
Opera��o: remove_inicio
    -Entrada: endere�o do deque e o endere�o de retorno do elemento removido
    -Pr�-condi��o: deque n�o estar vazio
    -Processo: remover o elemento que est� no in�cio do deque e retornar seu valor
    -Sa�da: 1 - sucesso ou 0 - falha
    -P�s-condi��o: o deque de entrada com um elemento a menos
*/
int remove_inicio(Deque d, char *elem[]) {
    if (d == NULL || deque_vazio(d) == 1)
        return 0;

    strcpy(elem, d->no[d->ini]);
    d->ini = (d->ini+1)%MAX_ELEM; // increment de ini
    d->cont--;

    //elem =  d->no[d->ini];

    return 1;
}

/*
Opera��o: remove_final
    -Entrada: endere�o do deque e o endere�o de retorno do elemento removido
    -Pr�-condi��o: deque n�o estar vazio
    -Processo: remover o elemento que est� no final do deque e retornar seu valor
    -Sa�da: 1 - sucesso ou 0 - falha
    -P�s-condi��o: o deque de entrada com um elemento a menos
*/
int remove_final(Deque d, char *elem[]) {
    if (d == NULL || deque_vazio(d) == 1)
        return 0;

    int fim = (d->ini + d->cont-1)%MAX_ELEM;
    strcpy(elem, d->no[fim]);
    //elem =  d->no[d->fim];
    //d->fim = (d->fim-1)%MAX_ELEM;
    d->cont--;


    return 1;
}

/*
Opera��o: apaga_deque
    -Entrada: endere�o do endere�o do deque
    -Pr�-condi��o: deque ser v�lido
    -Processo: libera o espa�o de mem�ria ocupado pelo deque e faz ele apontar para NULL
    -Sa�da: 1 - sucesso ou 0 - falha
    -P�s-condi��o: deque apagado
*/
int apaga_deque(Deque *d) {
    if (*d == NULL)
        return 0;

    free(*d);
    *d = NULL;
    return 1;
}

/*
Opera��o: esvazia_deque
    -Entrada: endere�o do deque
    -Pr�-condi��o: deque n�o estar vazio
    -Processo: reinicializa o in�cio e o final, tornando o deque vazio
    -Sa�da: 1 - sucesso ou 0 - falha
    -P�s-condi��o: deque vazio
*/
int esvazia_deque(Deque d) {
    if (d == NULL || deque_vazio(d) == 1)
        return 0;

    d->ini = 0;
    d->cont = 0;
    return 1;
}

/*
Opera��o: tamanho_deque
    -Entrada: endere�o do deque
    -Pr�-condi��o: deque ser v�lido
    -Processo: retorna o tamanho do deque
    -Sa�da: o tamanho do deque ou -1 caso o deque for inv�lido
    -P�s-condi��o: nenhuma
*/
int tamanho_deque(Deque d) {
    if (d == NULL)
        return -1;
    if (deque_vazio(d) == 1)
        return 0;

    return d->cont;
}
