#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include <time.h>
#define max_veic 5
#define max_box 3
//Definicao da struct fila
struct fila{
    Carro car[max_veic]; // vetor de Carros
    int ini,fim; // indicadores das posicoes de inicio e fim
};
// Operacao cria fila
Fila cria_fila(){
    //Alocando a fila estatica
    Fila f;
    f = (Fila) malloc(sizeof(struct fila));
    if(f != NULL){ // se alocado com sucesso
    f->ini = 0; // inicializa as posicoes com 0
    f->fim = 0;}
        return f;
}
//Operacao fila vazia
//Verifica se a fila esta em estado vazia
int fila_vazia(Fila f){
    if(f->ini == f->fim) //se posicoes inicio e fim forem iguais, a fila esta vazia
        return 1;
return 0;
}
//Operacao tamanho fila
//Retorna o tamanho de uma fila
int tamanho(Fila f){
return (f->ini +  f->fim)%max_veic; // fazendo a soma entre inicio e fim por incremento circular
}
//Operacao fila cheia
//Verifica se a fila esta em estado vazia
int fila_cheia(Fila f){
    if(f->ini == (f->fim+1%max_veic))
        return 1;
 return 0;
}
//Funcao auxiliar que calcula o preco do estacionamento a partir das horas e minutos
float calculaPreco(int horas,int minutos){
    float preco;
    if(horas < 1 && minutos < 15) {// se a hora for menor que 1 e 15, o cliente paga 5 reais
        preco = 5;}
    else{ // se passar de 1 hora e 15, paga mais 2 a cada hora adicional
    preco = 5 + 2*horas;
    }
    return preco; //retorna o preco
}

//Funcao auxiliar que simula a hora de saida, dada uma hora de entrada
time_t simulaHoraSaida(time_t hora_entrada){ //tipo time_t e dado em segundos,por isso todas as operacoes sao feitas com segundos
    int num1 = rand() % 10; //gera um numero aleatorio entre 0 e 10
    num1 = num1 * 3600; //convertendo para segundos
    int num2 = (rand() % 60) - 1; //gera um numero aleatorio entre 1 e 59
    num2 = num2 * 60; // convertendo para segundos
    time_t hora_saida = hora_entrada + num1 + num2; //adicionando ambos numeros para a hora de saida
    return hora_saida; //retorna hora de saida em segundos
}
//Operacao de insercao no fim da fila
int insere(Fila f,Carro car){
    if(fila_cheia(f) == 1)
        return 0; //fila esta cheia, logo nao e possivel inserir
    //insercao dos elementos no fim
    f->car[f->fim].servico = car.servico;
    strcpy(f->car[f->fim].placa,car.placa);
    f->car[f->fim].hora = car.hora;

    f->fim = f->fim+1%max_veic;//incremento circular no fim da fila
return 1;
}

//Operacao de remocao basica no inicio da fila
int remove_ini(Fila f,Carro *car){ //remove o primeiro elemento da fila
    if(fila_vazia(f) == 1)
        return 0;
     (*car).hora = f->car[f->ini].hora; //recebe as informacoes do elemento a ser removido
     (*car).servico = f->car[f->ini].servico;
     strcpy((*car).placa,f->car[f->ini].placa);
     f->ini = (f->ini+1)%max_veic; //incremento circular no inicio da fila
        return 1;
}

//Operacao de remocao a partir da placa de um carro
int remover(Fila f,Carro car){
    //Verifica se a fila esta vazia
    if(fila_vazia(f))
        return 0;
    int i,g = 0;
    Fila aux = cria_fila(); // Criacao de uma fila auxiliar
    if(aux == NULL) return 0; //Verifica se a criacao deu certo
    for(i = f->ini;i < f->fim;i++){ //For para procurar a placa a ser removida
        if(strcmp(f->car[i].placa,car.placa) != 0){ //comparacao entre placas
        insere(aux,car); //auxiliar recebe o carro a ser removido
        g++;
   }
  else{
    g++;
    i = f->ini;
    while(g--)
    remove_ini(f,&car);
    int j;
    for(j = aux->ini; j < f->ini ;j++,i++){
       insere(f,aux->car[j]);
    }
    free(aux);
    break;
  }
}
if(i == max_veic){
    f = aux;
    return 0; //placa nao encontrada
}
 return 1; //sucesso
}

//Operacao basica que apaga a fila
 int apaga_fila(Fila *f){
    if(f == NULL) return 0; // Ponteiro nao aponta pra fila (Nao eh possivel apagar)
    free(*f);// Limpa a regiao da fila (liberando a memoria para o computador)
    *f = NULL; // apontar pra NULL para nao conseguirem acessar aquela area novamente
    return 1;
}
//Operacao que esvazia a fila
int esvazia_fila(Fila f){
    for(int i; i < f->fim+1%max_box;i++){
        f->car[i].hora = 0;
        f->ini = 0; // zera todos os componentes da fila
        f->fim = 0;
    }
    return 1;
}
//Funcao que printa a fila
    if(fila_vazia(f) == 1)
        printf(" Vazio\n");
    else{
    int i;
    for(i = f->ini; i < f->fim; i++) {
        printf("Placa: [ %s ]\n",f->car[i].placa);}
    }
}




