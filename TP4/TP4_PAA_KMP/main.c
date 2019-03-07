#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "KMP.h"
#define MAX 200
#define  apagarTela system("clear")
#define DEBUG 1 // ativo em 1 ou nao ativo em 0


int menu();
int lerArquivo(int);

int main()
{

    int op1 = 1, op2=0;

    do{
        apagarTela;
        op2 = menu();
        if( op2 ==-1) return 0;
        lerArquivo(op2);
        printf("\nDeseja sair: 0-sim 1-nao\n");
        scanf("%d", &op1);

        if(op2 == -1) {
            printf("\nErro!!!!\n");
            return 0;
        }
    }while(op1 != 0);

    return 0;
}

int lerArquivo(int opcao)
{
    FILE *arquivo;
    char *nome;
    clock_t Ticks[2];
    nome = (char*)malloc(sizeof(20));
    char text[MAX];
    char padrao[30];

    printf("\n\tEntre com o nome do arquivo: ");
    scanf("%s", nome);
    setbuf(stdin, NULL);

    arquivo = fopen(nome, "r");

    if(arquivo == NULL)
    {
        printf("\n\tErro na leitura do arquivo!\n");
        return 0;
    }

    printf("\n\tEntre com o padrao: ");
    fflush(stdin);
    scanf("%s", padrao);

    printf("\n\tALGORITMO KMP:\n\n");

    if(DEBUG)
    {
        Ticks[0] = clock();
    }

    int linha = 1;
    while((fgets(text, MAX, arquivo)) != NULL)
    {

        KMP(padrao, text, linha);

        linha++;
    }

    if(DEBUG) // Realiza o cálculo do tempo de execução do algoritmo.
    {
        Ticks[1] = clock();
        double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("\n\tModo DEBUG: Tempo gasto: %g ms.\n\n", Tempo);

    }

    fclose(arquivo);
    return 0;
}

int menu()
{
    fflush(stdin);
    int opcao = 0;

    printf("\t+--------------------+\n");
    printf("\t|        MENU        |\n");
    printf("\t+--------------------+\n");
    printf("\t|1 - Algoritmo KMP   |\n");
    printf("\t+--------------------+\n");
    printf("\tDigite 1 para continuar:");
    scanf("%d", &opcao);

    if(opcao != 1)
    {
        apagarTela;
        printf("Erro!");
        return -1;
    }

    apagarTela;
    return opcao;
}
