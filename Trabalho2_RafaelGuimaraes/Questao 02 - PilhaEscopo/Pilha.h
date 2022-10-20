#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

//PILHA FLOAT
typedef struct nof *PilhaF;

PilhaF cria_pilhaF();
int pilha_vaziaF(PilhaF p);
int pushF(PilhaF *p, float elem);
int popF(PilhaF *p, float *elem);
int le_topoF(PilhaF *p, float *elem);
int esvazia_pilhaF(PilhaF *p);
int apaga_pilhaF(PilhaF *p);

//=====================================
//PILHA CHAR

typedef struct pilha *PilhaC;

PilhaC cria_pilhaC();
int pilha_vaziaC (PilhaC p);
int pilha_cheiaC (PilhaC p);
int pushC (PilhaC p, char elem);
int popC (PilhaC p, char *elem);
int le_topoC(PilhaC p, char *elem);
int esvazia_pilhaC(PilhaC p);
int apaga_pilhaC(PilhaC *p);


#endif // PILHA_H_INCLUDED
