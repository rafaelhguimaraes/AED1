#ifndef FPD_H_INCLUDED
#define FPD_H_INCLUDED
#define max 25

typedef struct no * Fila;

struct pessoa{
      char nome[max];
      int idade;
      float peso;
      float altura;
      char doenca;
      int gravidade;
};

typedef struct pessoa Pessoa;

Fila cria_fila ();
int fila_vazia (Fila);
int insere_ord (Fila *, Pessoa);
int remove_ini (Fila *, Pessoa *);
int esvazia_fila (Fila *);
int apaga_fila (Fila *);
int remove_maior(Fila *, Pessoa *);

#endif // FPD_H_INCLUDED
