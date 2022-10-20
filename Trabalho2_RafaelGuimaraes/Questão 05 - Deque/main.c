#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"
#define STR 30

void imprime_Deque(Deque f, char elem[]);

int main()
{
    Deque f;
    int ativo = 0;

    int x;
    char elem[STR];
    while(ativo != 1)
    {

        printf("\t---------------------------------------------------------------\n");
        printf("\t========Deque Estatica Sequencial com uso do Contador==========\n");
        printf("\n\t[1] Criar Deque\n");
        printf("\t[2] Inserir string no inicio do deque\n");
        printf("\t[3] Inserir string no final do deque\n");
        printf("\t[4] Remover string do inicio da Deque\n");
        printf("\t[5] Remover string do final da Deque\n");
        printf("\t[6] Imprimir Deque\n");
        printf("\t[7] Limpar Deque\n");
        printf("\t[8] Apagar Deque\n");
        printf("\t[9] Tamanho da Deque\n");
        printf("\t[10] Sair\n");
        printf("\t---------------------------------------------------------------\n");
        printf("\tDigite o valor desejado: ");

        scanf("%d", &x);
        setbuf(stdin, NULL);

        switch(x)
        {

            case 1:

                f = cria_deque();
                if(f == NULL)
                    printf("\tO Deque nao foi criado\n");
                else
                    printf("\tO Deque nao foi criado com sucesso\n");

                break;

            case 2:

                printf("\tDigite o elemento: ");
                scanf("%s", elem);

                if(insere_inicio(f, elem) == 0)
                    printf("Nao foi possivel adicionar.\n");

                else{
                    printf("\tO elemento %s foi incluido.\n", elem);
                        printf("\n Fila atualizada:\n");
                        if(f != NULL)
                            imprime_Deque(f, elem);
                }
                        printf("\n");
                break;

            case 3:
                printf("\tDigite o elemento: ");
                scanf("%s", elem);

                if(insere_final(f, elem) == 0)
                    printf("Nao foi possivel adicionar.\n");

                else{
                    printf("\tO elemento %s foi incluido.\n", elem);
                        printf("\n Fila atualizada:\n");
                        if(f != NULL)
                            imprime_Deque(f, elem);
                }
                        printf("\n");

                break;

             case 4:
                if(remove_inicio(f, elem) == 0)
                    printf("\tErro ao remover elemento %s .\n", elem);
                else
                    printf("\tO elemento %s foi removido .\n", elem);

                break;

             case 5:
                if(remove_final(f, elem) == 0)
                    printf("\tErro ao remover elemento %s .\n", elem);
                else
                    printf("\tO elemento %s foi removido.\n", elem);

                break;

            case 6:

                printf("\n");
                if(f != NULL)
                    imprime_Deque(f, elem);
                else
                    printf("\tNao foi possivel imprimir.\n");

                break;

            case 7:

                if(esvazia_deque(f) == 0)
                    printf("\tNao existe nenhuma Deque.\n");
                else
                    printf("\tDeque esvaziado (Vazio) .\n");

                break;

            case 8:

                apaga_deque(&f);
                printf("\tDeque apagada.\n");

                break;

            case 9:
                if (tamanho_deque(f) >= 0)
                    printf("\tO Deque tem tamanho igual a %d\n", tamanho_deque(f));
                else
                    printf("\tDeque invalido\n");

                break;

            case 10:

                ativo = 1;
                break;

            default:
                printf("\tA Opcao nao existe.\n");
        }

    }

    return 0;
}

void imprime_Deque(Deque f, char elem[])
{

    if(deque_vazio(f) == 1)
    {
        printf("\n\t ===== O Deque esta Vazio=====\n");
        return;
    }
    int i=0;
    Deque g = cria_deque();
    while(deque_vazio(f)==0)
    {
        remove_inicio(f, elem);
        printf("\tElemento %d: %s",i+1,elem);
        i++;
        insere_inicio(g, elem);
        printf("\n");
    }

    while(deque_vazio(g)==0)
    {
        remove_inicio(g, elem);
        insere_inicio(f, elem);
    }
}
