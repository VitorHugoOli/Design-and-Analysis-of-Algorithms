#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int comparacao(int, int, char[][80]);
int tricomparacao(int, int , char[][80]);

int main() {
    //adicionando acento ao compiler
    setlocale(LC_ALL, "Portuguese");

    //seed para gerar valorea aletorios apartir do tempo
    srand(time(NULL));

    //Variaveis
    char matriz[20][80];
    int i, j, opc, quantidade;
    int linha, coluna;
    char *endptr;
    int random;
    int flag=0;
    int menu=0;


    //Nome do progama
    printf("\nPROGAMA GERADOR DE OBRA DE ARTE\n"
           "-------------------------------\n");

    while(menu!=3) {
        //Escolha do simbolos
        printf("\n1 - simples: * \n"
               "\n"
               "2 - soma: * \n"
               "         ***\n"
               "          * \n"
               "\n"
               "3 - X: *   *\n"
               "         *  \n"
               "       *   *\n"
               "4 - Figuras aleatorias\n\n"
               "5 - TriForce:  * \n"
               "              ***\n"
               "             *   *\n"
               "            *** ***\n"
               "Digite o tipo de figura desejada: ");

        scanf("%d", &opc);//leitura da opçao de figura
        while (opc < 1 || opc > 5) {
            printf("Opçao não valida, entre novamente com as propostas!!!\n");
            scanf("%d", &opc);
        }


        //Escolha da quantidade
        printf("Digete qual será a quantidade a desenhar (entre 1 e 100): ");
        scanf("%d", &quantidade);//leitura da quantidade de figura
        if (quantidade < 1)
            quantidade = rand() % 100;
        else if (quantidade > 100)
            quantidade = 100;

        //quadrado
        //gerando quadro e suas bordas
        if(menu!=2) {//Caso menu==2, havera a criaçao de uma figura apartir de uma já criada
            for (i = 0; i < 20; i++) {
                for (j = 0; j < 80; j++) {
                    if (i == 0)
                        matriz[i][j] = '-';
                    else if (j == 0 && i != 19)
                        matriz[i][j] = '|';
                    else if (j == 79 && i != 19)
                        matriz[i][j] = '|';
                    else if (i == 19)
                        matriz[i][j] = '-';
                    else
                        matriz[i][j] = ' ';
                }
            }
        }

        //Gerando as figuras dentro do quadrado;
        //opçao 1
        if (opc == 1) {
            for (i = 0; i < quantidade; i++)
                matriz[(rand() % 18) + 1][(rand() % 78) + 1] = '*';
            //opçao 2
        } else if (opc == 2) {
            for (i = 0; i < quantidade; i++) {
                linha = (rand() % 16) + 2;
                coluna = (rand() % 76) + 2;
                flag = 0;
                while (comparacao(linha, coluna, matriz)) {
                    linha = (rand() % 16) + 2;
                    coluna = (rand() % 76) + 2;
                    flag++;
                    if (flag == 1501)//19*98=1501 o total de pontos dentro do quadrado
                        break;
                }
                if (flag == 1501)//19*98=1501 o total de pontos dentro do quadrado
                    break;
                matriz[linha][coluna] = '*';
                matriz[linha - 1][coluna] = '*';
                matriz[linha][coluna - 1] = '*';
                matriz[linha][coluna + 1] = '*';
                matriz[linha + 1][coluna] = '*';
            }
            //opçao 3
        } else if (opc == 3) {
            for (i = 0; i < quantidade; i++) {
                linha = (rand() % 16) + 2;
                coluna = (rand() % 76) + 2;
                flag = 0;
                while (comparacao(linha, coluna, matriz)) {
                    linha = (rand() % 16) + 2;
                    coluna = (rand() % 76) + 2;
                    flag++;
                    if (flag == 1501)//19*98=1501 o total de pontos dentro do quadrado
                        break;
                }
                if (flag == 1501)//19*98=1501 o total de pontos dentro do quadrado
                    break;
                matriz[linha][coluna] = '*';
                matriz[linha - 1][coluna - 1] = '*';
                matriz[linha - 1][coluna + 1] = '*';
                matriz[linha + 1][coluna + 1] = '*';
                matriz[linha + 1][coluna - 1] = '*';
            }
            //opçao 4
        } else if (opc == 4) {
            for (i = 0; i < quantidade; i++) {
                random = (rand() % 3) + 1;

                if (random == 1) {

                    linha = (rand() % 18) + 1;
                    coluna = (rand() % 78) + 1;
                    flag = 0;

                    while (comparacao(linha, coluna, matriz)) {
                        linha = (rand() % 18) + 1;
                        coluna = (rand() % 78) + 1;
                        flag++;
                        if (flag == 1501)//19*98=1501 o total de pontos dentro do quadrado
                            break;
                    }
                    if (flag == 1501)//19*98=1501 o total de pontos dentro do quadrado
                        break;
                    matriz[linha][coluna] = '*';
                } else if (random == 2 || random == 3) {

                    linha = (rand() % 16) + 2;
                    coluna = (rand() % 76) + 2;
                    flag = 0;

                    while (comparacao(linha, coluna, matriz)) {
                        linha = (rand() % 16) + 2;
                        coluna = (rand() % 76) + 2;
                        flag++;
                        if (flag == 1501)//19*98=1501 o total de pontos dentro do quadrado
                            break;
                    }
                    if (flag == 1501)//19*98=1501 o total de pontos dentro do quadrado
                        break;
                    if (random == 2) {
                        matriz[linha][coluna] = '*';
                        matriz[linha - 1][coluna] = '*';
                        matriz[linha][coluna - 1] = '*';
                        matriz[linha][coluna + 1] = '*';
                        matriz[linha + 1][coluna] = '*';
                    } else {
                        matriz[linha][coluna] = '*';
                        matriz[linha - 1][coluna - 1] = '*';
                        matriz[linha - 1][coluna + 1] = '*';
                        matriz[linha + 1][coluna + 1] = '*';
                        matriz[linha + 1][coluna - 1] = '*';
                    }

                }


            }
            //opçao 5
        } else if(opc==5){
            for (i = 0; i < quantidade; i++) {
                linha = (rand() % 15) + 3;
                coluna = (rand() % 71)+ 5;
                flag=0;
                while (tricomparacao(linha,coluna,matriz)){
                    linha = (rand() % 15) + 3;
                    coluna = (rand() % 71) + 5;
                    flag++;
                    if (flag == 1501)//19*98=1501 o total de pontos dentro do quadrado
                        break;
                }
                if (flag == 1501)//19*98=1501 o total de pontos dentro do quadrado
                    break;
                matriz[linha-2][coluna]='*';
                matriz[linha-1][coluna-1]='*';
                matriz[linha-1][coluna]='*';
                matriz[linha-1][coluna+1]='*';
                matriz[linha][coluna-2]='*';
                matriz[linha][coluna+2]='*';
                matriz[linha+1][coluna-3]='*';
                matriz[linha+1][coluna-2]='*';
                matriz[linha+1][coluna-1]='*';
                matriz[linha+1][coluna+1]='*';
                matriz[linha+1][coluna+2]='*';
                matriz[linha+1][coluna+3]='*';

            }
        }

        //Exibindo a matri para o usuario
        for (i = 0; i < 20; i++) {
            for (j = 0; j < 80; j++) {
                printf("%c", matriz[i][j]);
            }
            printf("\n");
        }
        system("Pause");
        system("CLS");
        printf("1 - Criar nova figura.\n"
               "2 - Criar nova figura, apartir desta.\n"
               "3 - Sair do progama.\n");
        printf("Digite a opçao escolhida: ");
        scanf("%d",&menu);
        system("CLS");
    }

    return 0;
}

int comparacao(int linha, int coluna, char matriz[][80]){// Faz comparaçao para não haver sobreposiçao nas opçoes 2,3 e 4
    return (matriz[linha][coluna] == '*' || matriz[linha - 1][coluna + 1] == '*' ||
            matriz[linha + 1][coluna - 1] == '*' || matriz[linha - 1][coluna - 1] == '*' ||
            matriz[linha + 1][coluna + 1] == '*' || matriz[linha - 1][coluna] == '*' ||
            matriz[linha][coluna - 1] == '*' || matriz[linha][coluna + 1] == '*' ||
            matriz[linha + 1][coluna] == '*');
 }

 int tricomparacao(int linha, int coluna, char matriz[][80]) {// Faz comparaçao para não haver sobreposiçao na opçao 5
     return (
             matriz[linha - 2][coluna - 3] == '*' || matriz[linha - 2][coluna - 2] == '*' ||
             matriz[linha - 2][coluna - 1] == '*' || matriz[linha - 2][coluna] == '*' ||
             matriz[linha - 2][coluna + 1] == '*' || matriz[linha - 2][coluna + 2] == '*' ||
             matriz[linha - 2][coluna + 3] == '*' ||

             matriz[linha - 1][coluna - 3] == '*' || matriz[linha - 1][coluna - 2] == '*' ||
             matriz[linha - 1][coluna - 1] == '*' || matriz[linha - 1][coluna] == '*' ||
             matriz[linha - 1][coluna + 1] == '*' || matriz[linha - 1][coluna + 2] == '*' ||
             matriz[linha - 1][coluna + 3] == '*' ||

             matriz[linha][coluna - 3] == '*' || matriz[linha][coluna - 2] == '*' || matriz[linha][coluna - 1] == '*' ||
             matriz[linha][coluna] == '*' || matriz[linha][coluna + 1] == '*' || matriz[linha][coluna + 2] == '*' ||
             matriz[linha][coluna + 3] == '*' ||

             matriz[linha + 1][coluna - 3] == '*' || matriz[linha + 1][coluna - 2] == '*' ||
             matriz[linha + 1][coluna - 1] == '*' || matriz[linha + 1][coluna] == '*' ||
             matriz[linha + 1][coluna + 1] == '*' || matriz[linha + 1][coluna + 2] == '*' ||
             matriz[linha + 1][coluna + 3] == '*');
 }