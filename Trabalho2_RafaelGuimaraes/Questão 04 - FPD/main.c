#include <stdio.h>
#include <stdlib.h>
#include "fpd.h"

void imprime_fila(Fila, Pessoa);

int main(){

    Fila f = NULL;
    Pessoa elem;
    int n, confere = 0;
    int ativo = 1;

    while(ativo == 1){

        printf("\t============================================\n");
        printf("\t=Fila de Prioridade Ascendente de Pacientes=\n");
        printf("\n\t[1] - Criar Fila.\n");
        printf("\t[2] - Cadastrar paciente na Fila.\n");
        printf("\t[3] - Remover cadastro de paciente da Fila.\n");
        printf("\t[4] - Imprimir a Fila.\n");
        printf("\t[5] - Limpar a Fila.\n");
        printf("\t[6] - Apagar a Fila.\n");
        printf("\t[7] - Sair\n");
        printf("\t============================================\n");
        scanf("%d", &n);
        setbuf(stdin, NULL);

        if (n == 1 && confere == 0)
        {
            f = cria_fila();
         confere = 1;
            printf("A fila foi criada com sucesso\n");
        }

        else if (confere == 1)
        {
            if(n == 1)
            {
                printf("\nA fila ja foi criada\n");
            }
            else if(n == 2)
            {

                printf("Digite o nome do paciente: ");
                scanf("%[^\n]", elem.nome);

                printf("Digite a sua idade: ");
                scanf("%d", &elem.idade);

                printf("Digite o seu peso: ");
                scanf("%f", &elem.peso);

                printf("Digite a altura: ");
                scanf("%f", &elem.altura);

                printf("Insira a doenca(C cardiaca, N neurologica, S  sanguinea  ou R  respiratoria) : ");
                getchar();
                scanf("%c", &elem.doenca);

                printf("Digite a gravidade (De 1 a 5): ");
                scanf("%d", &elem.gravidade);

                printf ("\n");

                if(insere_ord(&f, elem) == 0)
                    printf("Ocorreu um ==ERRO== ao adicionar.\n");
                else
                    printf("Incluido com sucesso.\n");

            }
            else if(n == 3)
            {
                if(remove_maior(&f, &elem) == 0)
                    printf("Lista vazia.\n");

                else{

                    printf("O paciente:\n\n");
                    printf("Nome: %s\n", elem.nome);
                    printf("Idade: %d\n", elem.idade);
                    printf("Peso: %.2f\n", elem.peso);
                    printf("Altura: %.2f\n", elem.altura);
                    printf("Doenca: %c\n", elem.doenca);
                    printf("Gravidade: %d\n\n", elem.gravidade);
                    printf("Foi removido\n");
                }

            }
            else if(n == 4)
            {
               if(f != NULL)
                    imprime_fila(f, elem);
                else
                    printf("\nNao foi possivel imprimir a fila.\n");

            }
            else if(n == 5)
            {

              if(esvazia_fila(&f) == 0)
                    printf("Nao existe nenhuma fila.\n");
                else
                    printf("Fila esvaziada.\n");

            }
            else if(n == 6)
            {
                apaga_fila(&f);
                printf("Fila apagada.\n");

            }
            else if(n == 7)
            {
                return 0;
            }
            else
            {
                printf("Opcao invalida ou inexistente.");
                return 0;
            }

            printf("\n\n");
        }
        else
        {
            printf("\nFila ainda nao criada!\n\n");
        }
    }

    return 0;
}

void imprime_fila(Fila f, Pessoa elem)
{
    if(fila_vazia(f) == 1){

        printf("\n --Fila Vazia--\n");
        return;
    }
    printf("\nFila:\n\n");

    Fila aux = cria_fila();
    printf("\t===FILA DE PACIENTES===\n");
    while (fila_vazia(f) == 0)
    {
        remove_ini (&f, &elem);

        printf("\tNome: %s\n", elem.nome);
        printf("\tIdade: %d\n", elem.idade);
        printf("\tPeso: %.2f\n", elem.peso);
        printf("\tAltura: %.2f\n", elem.altura);
        printf("\tDoenca: %c\n", elem.doenca);
        printf("\tGravidade: %d", elem.gravidade);

        insere_ord(&aux, elem);
        printf ("\n\n");
    }
     while(fila_vazia(aux)==0)
    {
        remove_ini(&aux, &elem);
        insere_ord(&f, elem);
    }

}

