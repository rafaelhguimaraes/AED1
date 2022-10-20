#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#define max_veic 5
#define max_box 3

//Programa de controle de estacionamento
int main()
{
    Fila f[max_box];
    Carro car;
    char placa[10],op;
    int i,tam,box;

    for(i = 0;i < max_box;i++){
        f[i] = cria_fila();
        if(f[i] == NULL){
            printf("Erro ao alocar as filas\n");
            return 0;
        }
    }

    printf("1-Entrada de veiculo \n");
    printf("2-Saida de veiculo \n");
    printf("3-Visualizar estacionamento \n");
    printf("4- Sair \n");

    while(1){
        printf("\nEscolha uma opcao valida:");
        setbuf(stdin,NULL);
        op = getchar();
        switch(op){
        // Insercao de um novo carro no estacionamento
         case '1':
             printf("Qual placa deseja inserir?\n");
             setbuf(stdin,NULL);
             gets(car.placa);
             printf("Qual e o tipo de servico [a] avulso [m] mensal: ");
             scanf("%c",&car.servico);
             car.hora = time(NULL); // Captura o tempo de entrada


             //Calcula qual box esta mais vazio para inserir o carro
             box = 0;
             tam = tamanho(f[0]);
             for(i = 1;i < max_box; i++){
                 if(tam > tamanho(f[i])){
                     tam = tamanho(f[i]);
                     box = i;
             }
            }
            if(insere(f[box],car)){
                printf("Inserido com sucesso no Box [%d]",box + 1);
            }
            break;

         case '2':
            printf("Em qual box deseja retirar seu veiculo?\n");
            scanf("%d",&box);
            printf("Qual placa deseja remover?\n");
            setbuf(stdin,NULL);
            gets(car.placa);
            car.hora = time(NULL);
            time_t hora_saida = simulaHoraSaida(car.hora);
            time_t tempo = hora_saida - car.hora;
            int horas = tempo / 3600;
            int resto = tempo % 3600;
            int minutos = resto / 60;
            if(remover(f[box - 1],car)){
                printf("Foi removido com sucesso\n");
                printf("O veiculo ficou no estacionamento por %d horas, %d minutos. \n",horas,minutos);
                printf("O preco do estacionamento e R$%2.f.",calculaPreco(horas,minutos));
            }else{
                printf("Falha ao remover\n");}
            break;

         case '3':
            for(i = 0; i < max_box;i++){
              tam = tamanho(f[i]);
              printf("Box [%d]:\n",i + 1);
              visualizar(f[i]);
             }
            break;

         case '4':
            printf("Saindo");
            return 0;

        }
       }
    return 0;
}

