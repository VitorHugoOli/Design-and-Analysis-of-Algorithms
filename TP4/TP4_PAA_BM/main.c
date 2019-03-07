#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "BM.h"
#define MAX 200
#define  apagarTela system("clear")
#define DEBUG 1


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


    if(opcao == 1)
    {
        printf("\n\tALGORITMO BMHS:\n\n");

    }
    else{
        printf("\n\tALGORITMO BMH:\n\n");
    }


    if(DEBUG)
    {
        Ticks[0] = clock();
    }

    int linha = 1;
    while((fgets(text, MAX, arquivo)) != NULL)
    {

        if(opcao == 1)
        {
            BMHS(text, padrao, linha);
        }
        else if(opcao == 2)
        {
            BMH (text, padrao, linha);
        }
        linha++;
    }

    if(DEBUG)
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

    printf("\t+=====================+\n");
    printf("\t|        MENU         |\n");
    printf("\t|---------------------|\n");
    printf("\t|1 - Algoritmo BMHS   |\n");
    printf("\t|2 - Algoritmo BMH    |\n");
    printf("\t+=====================+\n");
    printf("\topcao: ");
    scanf("%d", &opcao);

    if(opcao != 1 && opcao != 2)
    {
        printf("Erro!");
        return -1;
    }

    apagarTela;
    return opcao;
}
