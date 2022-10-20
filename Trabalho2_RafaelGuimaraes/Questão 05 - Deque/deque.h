#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

typedef struct deque * Deque;

Deque cria_deque();
int deque_vazio(Deque);
int deque_cheio(Deque);
int insere_final(Deque, char[]);
int insere_inicio(Deque d, char elem[]);
int remove_inicio(Deque d, char *elem[]);
int remove_final(Deque d, char *elem[]);
int apaga_deque(Deque *d);
int esvazia_deque(Deque d);
int tamanho_deque(Deque d);

#endif // DEQUE_H_INCLUDED
