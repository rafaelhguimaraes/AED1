#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "Pilha.h"


#define MAX 20


int main(){

int x, y, status;
float x1,x2, num;
char expressao[MAX], pos[MAX], comp;
PilhaC p;
PilhaF f;

// Criar a pilha
p = cria_pilhaC();

do{
    do{
        esvazia_pilhaC(p); // Esvaziar a pilha para "iniciar" o programa
        setbuf(stdin, NULL);// Limpeza na "entrada"
        printf("\n\n __________________________________________________\n");
        printf("\n Insira a expressao matematica desejada com os Operandos em letras maiusculas: ");
        gets(expressao); //Obtemos a "string" expressao


        // Saida do programa
        if(strcmp(expressao, "FIM") == 0) return 0; // Sair do programa


        // 01- Validação de Escopo:

        status = 0; x = 0;

        while(expressao[x] != '\0'){ // Enquanto não acabar a string


            // Chegou a hora de verificar cada letra que o usuario digitou e se isso será permitido.

            if(expressao[x]!='+' && expressao[x]!='-' && expressao[x]!='/' && expressao[x]!='*' && expressao[x]!='^' && expressao[x]!='(' && expressao[x]!=')' && expressao[x]!='[' && expressao[x]!=']' &&expressao[x]!='{' && expressao[x]!='}' &&(expressao[x]<'A' || expressao[x]>'F') ){
                printf("\n Existem variaveis literais, operadores ou delimitadores invalidos! ");
                status = 1; // Estado de erro
                break;
            }

            comp = 0;

            // Aberturas

            // Se for ABRE parenteses, colchete ou chaves
            if(expressao[x]=='(' || expressao[x]=='[' || expressao[x]=='{'){
                le_topoC(p,&comp); // ultimo inserido

                // Se a pilha nao estiver vazia e a expressao for abre Colchetes, podemos apresentar erro de PRECEDENCIA
                if(expressao[x]=='{' && pilha_vaziaC(p)==0){

                    printf("Erro de precedencia de escopos!\n");
                    status = 1;
                    break;
                }


                if((expressao[x]=='[' && comp=='(') || (expressao[x]=='[' && comp=='[')){
                    printf("Erro de precedencia de escopos!\n");
                    status = 1;
                    break;
                }
                //estaria abrindo ( dentro de ( - inválido
                if((expressao[x]=='(' && comp=='{') || (expressao[x]=='(' && comp=='(')){
                    printf("Erro de precedencia de escopos!\n");
                    status = 1;
                    break;
                }

                // É empilhado a abertura de escopo (,[,{
                pushC(p,expressao[x]);
            }

            // Fechamentos
            // Se for FECHA parenteses, colchete ou chaves
            if(expressao[x]==')' || expressao[x]==']' || expressao[x]=='}'){
                // Se existir um FECHA, mas a pilha estiver vazio, é pq temos mais fechamentos que aberturas
                if(popC(p,&comp) == 0){ // Falhar ao remover da pilha (VAZIA)
                printf("\n ERRO! Fechamentos e Aberturas de escopo estao desbalanceadas tendo mais fechamentos que aberturas");
                status = 1;
                break;
                }
                // Se o fechamento for DIFERENTE da abertura
                if((expressao[x]==')' && comp!='(') || (expressao[x]==']' && comp!='[') || (expressao[x]=='}' && comp!='{')){
                    printf("\n ERRO! Ordem de fechamentos eh diferente das aberturas! ");
                    status = 1;
                    break;
                }
            }
            x++; // Avança o indice
        }

        if(status == 0){ // Se ate agora não tivermos erros
            if(pilha_vaziaC(p) == 0){ // Existe elementos dentro da pilha ainda
            // ERRO, nessa altura a pilha deveria estar vazia!
            printf("\n ERRO! Existem escopos abertos, mas nao foram fechados! ");
            status = 1;
            }else
            printf("\n SIM! O ESCOPO EH VALIDO! (Validado com sucesso!) ");
            printf("\n __________________________________________________\n");
        }

    }while(status == 1);

    // 02- Converte para PÓS-FIXO:
    x= 0; y = 0;
    while(expressao[x] != '\0'){// Enquanto não acabar a string
        // Verificar a letra
        if(expressao[x]>='A' && expressao[x]<='F'){ // Se estiver entre A e F
            pos[y] = expressao[x]; // Jogamos a "letra" no vetor pos
            y++; // Incrementa
        }
        // Se for ABERTURA, vamos empilhar
        if(expressao[x]=='(' || expressao[x]=='[' || expressao[x]=='{'){
            pushC(p,expressao[x]);
        }

            // Se for FECHAMENTO:
            if(expressao[x]==')' || expressao[x]==']' || expressao[x]=='}'){
                do{
                    popC(p,&comp); // Desempilhar até achar a abertura
                    if(comp!='(' && comp!='[' && comp!='{'){ // Se ao desempilhar, acharmos algo diferente disso
                        pos[y] = comp;
                        y++;
                    }
                }while(comp!='(' && comp!='[' && comp!='{');
            }

            // Soma e subtração tem mesma prioridade, vamos desempilhar e jogar pra expressao TUDO com prioridade menor igual que + e -
            if(expressao[x]=='+' || expressao[x]=='-'){
                le_topoC(p,&comp);

                while(pilha_vaziaC(p)==0 && (comp=='+' || comp=='-' || comp=='*' || comp=='/' || comp=='^')){ // ordem de prioridade{
                    popC(p,&comp);
                    pos[y] = comp;
                    y++;
                    comp = 0;
                    le_topoC(p, &comp);
                }
                // empilhar o operador lido
                pushC(p,expressao[x]);
            }

            // Multiplicação e divisão têm mesma prioridade, vamos desempilhar e jogar pra expressao TUDO com prioridade maior igual a * ou /
            if(expressao[x]=='*' || expressao[x]=='/'){
                le_topoC(p,&comp);

                while(pilha_vaziaC(p)==0 && (comp=='*' || comp=='/' || comp=='^')){
                    popC(p,&comp);
                    pos[y] = comp;
                    y++;
                    comp = 0;
                le_topoC(p,&comp);
                }
                // empilhar o operador lido
                pushC(p,expressao[x]);
            }

            if(expressao[x]=='^'){// maior prioridade.

                le_topoC(p,&comp);
                while(pilha_vaziaC(p)==0 && comp=='^'){
                    popC(p,&comp);
                    pos[y] = comp;
                    y++;
                    le_topoC(p,&comp);
                }
                // empilhar o operador lido
                pushC(p,expressao[x]);
            }

            x++;
    }

    // FIM DA EXPRESSÃO - O que restou na pilha é jogado para a expressao

    while(pilha_vaziaC(p) == 0){
        popC(p,&comp);
        pos[y] = comp;
        y++;
    }
    pos[y] = '\0';
    printf("\n __________________________________________________\n");
    printf("\n A Expressao em Pos-fixo sera: %s \n ",pos);
    printf("\n __________________________________________________\n");

    // 03 -  Avaliar expressao
    x=0;
    f = cria_pilhaF(); // Cria a pilha
    while(pos[x] != '\0'){// Enquanto não acabar a string


        if(pos[x]>='A' && pos[x]<='F'){ // Se for operando, pedimos pro usuario digitar o valor
            printf("\n __________________________________________________\n");
            printf("\n Digite o valor de %c: ",pos[x]);
            scanf("%f", &num); // Salva o valor em num
            setbuf(stdin,NULL);
            if(pushF(&f,num)); // Empilha

        }
        printf("\n __________________________________________________\n");
        // Se for operando, a gente desempilha os dois ultimos pra fazer o calculo
        // Apos isso, jogamos o resultado na pilha novamente

        if(pos[x]=='+' || pos[x]=='-' || pos[x]=='/' || pos[x]=='*' || pos[x]=='^'){


            if(popF(&f, &x2)==0){ // Ultimo valor (segundo termo)
                printf("\n O numero de operandos nao esta correto");
                status = 1;
                break;
            }

            if(popF(&f, &x1)==0){ // Primeiro valor
                printf("\n O numero de operandos nao esta correto");
                status = 1;
                break;
            }

            // Operações:
            if(pos[x] == '+')
            x1 = x1+x2;

            if(pos[x] == '-')
            x1 = x1-x2;

            if(pos[x] == '*')
            x1 = x1*x2;

            if(pos[x] == '/')
            x1 = x1/x2;

            if(pos[x] == '^')
            x1 = pow(x1,x2);

            pushF(&f,x1); // Insere na pilha o resultado da operação
         }
        x++;

    }

    popF(&f, &x1); // Retirar o ultimo elemento (resultado) e apresentar
    printf("\n\n -----------------------------------------------------\n");
    if(status == 0 ){ //Avaliação obteve sucesso
        if(pilha_vaziaF(f) == 1) // Não tem elementos na pilha, deu certo
            printf("\n O resultado da expressao eh %.2f \n",x1);
        else{ // Se sobrou alguma coisa, é que o numero de operadores tá errado
            printf("\n o numero de operadores esta errado! ");
            status = 1;
        }
    }
    printf("\n -----------------------------------------------------\n");

}while(strcmp(expressao,"FIM") != 0); // Repetição (expressao != Fim)
return 0;
}
