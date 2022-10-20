#include <stdio.h>
#include <stdlib.h>
#include "PilhaInt.h"

int main(){
char resp; // Armazena Char responsavel pela escolha do usu�rio
int valor; // Valor em decimal que usuario digitou
Pilha p; // Pilha

int base ; // Variavel que armazenar� o tipo da opera��o. 2 = Binaria, 8 = Octal ou  16 = Hexa
int resto; // Resto das divis�es
int n;     // A priori armazena o valor, porem, depois � modificado pelas divis�es
int temp; // Receber� o valor armazenado na pilha


do{
    p = cria_pilha() ;  // Logo de cara, vamos criar a pilha
    if(p != NULL){
        printf("\n Falha na alocacao da pilha!!!");
        return -1; //-1 Ser� ERRO
    }
   do{
    setbuf(stdin, NULL); // Limpeza de buffer
    printf("\n------------------- MENU -------------------\n");
    printf("\n [B] Converte o valor de base decimal para base BINARIA");
    printf("\n [O] Converte o valor de base decimal para base OCTAL");
    printf("\n [H] Converte o valor de base decimal para base HEXADECIMAL");
    printf("\n Para encerrar a aplicacao, escolha uma das operacoes acima e depois digite um valor NEGATIVO.");
    printf("\n\n Digite a opcao desejada: \n");
    scanf("%c", &resp); // Armazena o "char" que o usuario digitou
    setbuf(stdin, NULL);

   if((resp != 'B') && (resp != 'b') && (resp != 'O') && (resp != 'o') && (resp != 'H') && (resp != 'h')) // Se ele digitou algo diferente disso, t� errado!
   printf("\n *** Opcao digitada invalida! As opcoes disponiveis sao:\n");

   }while((resp != 'B') && (resp != 'b') && (resp != 'O') && (resp != 'o') && (resp != 'H') && (resp != 'h'));// Repita at� ele digitou algo correto!


    printf("\n Digite o valor em decimal a ser convertido.");
    printf("\n Para encerrar a aplicacao, basta digitar um valor NEGATIVO. -> ");
    scanf("%d", &valor); // Aqui, armazena o valor decimal

    if(valor < 0) break; //Sair do sistema.


    n = valor;

    //Definição da "base".
    if(resp == 'B' || resp == 'b'){
     // Binario
     base = 2;
   }else if(resp == 'O' || resp == 'o'){
    //Octal
    base = 8;
    }else{
    //Hexa
    base = 16;
    }


    // Enquanto o dividendo for maior que a base:
    while(n >= base){
     resto = n % base; // Resto da divisao do valor N pela Base
     push(&p,resto);    // Insere na pilha o resto.
     n = (n / base) ; // Divisao inteira de N pela Base
     }

     //Chegando aqui, nosso N tem o "ultimo resto"
    // Com isso, evitamos +1 insesao desnecessaria na pilha.
     printf("\n O valor [%d] na base decimal eh equivalente ao valor [",valor);

     // (CASO BASE 16)
     if(base == 16){
       if(n == 10){
        printf(" A");
       }else  if(n == 11){
        printf(" B");
       }else  if(n == 12){
        printf(" C");
       }else  if(n == 13){
        printf(" D");
       }else  if(n == 14){
        printf(" E");
       }else  if(n == 15){
        printf(" F");
       } else{
        printf(" %d",n); // Insere N no resultado da conversao
       }
       }else{
    // Base != 16
    printf(" %d",n); //Insere N no resultado da conversao
    }

     while(pilha_vazia(p) != 1){ // Enquanto existir "restos" na pilha:
        // Desempilhamos os "restos"
        pop(&p,&temp);
        // (CASO BASE == 16)
       if(base == 16){
       if(temp == 10){
            printf(" A");

       }else  if(temp == 11){
                    printf(" B");

       }else  if(temp == 12){
                    printf(" C");

       }else  if(temp == 13){
                    printf(" D");

       }else  if(temp == 14){
                    printf(" E");

       }else  if(temp == 15){
                    printf(" F");

        } else{
                printf(" %d",temp); // Caso seja menor que 16, o processo seria o mesmo que pra base Binaria ou Octal
        }
       }else{
      // Base != 16
      printf("%d",temp); //Pronta valor na pilha
     }
     }


     if(base == 2){

     printf(" ] na base binaria. ");
    }else if (base == 8){
            printf(" ] na base octal. ");
    }else{
            printf(" ] na base Hexadecimal. ");
    }

printf("\n");
}while(valor >= 0); // Menu

free(p);

printf("\n\n\t FIM PROGRAMA!");
}
