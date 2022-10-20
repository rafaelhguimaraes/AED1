#include <time.h>

typedef struct fila *Fila;
struct carro{
    char placa[10];
    time_t hora;
    char servico;
};
typedef struct carro Carro;
Fila cria_fila();
int fila_vazia(Fila f);
int tamanho(Fila f);
int fila_cheia(Fila f);
int insere(Fila f, Carro car);
int remover(Fila f, Carro car);
int remove_ini(Fila f,Carro *car);
void visualizar(Fila f);
time_t simulaHoraSaida(time_t hora_entrada);
float calculaPreco(int horas,int minutos);
int apaga_fila(Fila *f);
int esvazia_fila(Fila f);
