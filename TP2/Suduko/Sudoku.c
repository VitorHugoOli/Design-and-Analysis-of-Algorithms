#include "Sudoku.h"

void menuSudoku(){
    int arq = 1, opc;
    char nomeArquivo[30];
    Sudoku sudoku;

    while (arq) {


        printf("Digite o nome do arquivo: ");
        scanf("%s", nomeArquivo);
        getchar();
        if (preencheSudoku(&sudoku, nomeArquivo)) {

            printf("1- Resolver Sudoku \n2- Resolver Sudoku em modo análise\n");
            scanf("%d", &opc);

            while (opc < 1 || opc > 2) {
                printf("1- Resolver Sudoku \n2- Resolver Sudoku em modo análise\n");
                scanf("%d", &opc);
            }

            switch (opc) {
                case 1:
                    case1(sudoku);
                    break;
                case 2:
                    case2(sudoku);
                    break;
                default:
                    printf("Opção inexistente !\n");
                    break;
            }

            printf("Deseja continuar ?\n0- Nao | 1- Sim\n");
            scanf("%d", &arq);

            if (arq == 1) {
                limpaSudoku(&sudoku);
                getchar();
            }
        } else {
            printf("Descupe ocorreu algum erro !\n");
        }
    }
}

void case1(Sudoku sudoku){

    printf("Sudoku Inicial:\n");
    imprimeSudoku(sudoku);

    if (resolveSudoku(&sudoku)) {
        printf("Solução final encontrada.\n");
        imprimeSudoku(sudoku);
    } else
        printf("Não possui solucao !\n");

}

void case2(Sudoku sudoku){

    printf("Sudoku Inicial:\n");
    imprimeSudoku(sudoku);

    if (resolveSudoku(&sudoku)) {
        printf("Solução final encontrada.\n");
        imprimeSudoku(sudoku);
        printf("\nTotal tentativas %d \n\n", sudoku.tentativas);
    } else
        printf("Não possui solucao !\n");

}

int preencheSudoku(Sudoku *sudoku, char *nomeArquivo) 
{
    int i = 0;
    int j = 0;
    int n;
    FILE *arquivo;

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo) {
        (*sudoku).tentativas = 0;
        while (!feof(arquivo)) {

            fscanf(arquivo, "%d ", &n);

            (*sudoku).tabuleiro[i][j] = n;

            if (j >= 0 && j < 8) 
                j++;
            else if (j == 8) {
                i++;
                j = 0;
            }

        }

        return 1;

    } else {
        printf("Não foi possivel encontrar o arquivo\n");
        return 0;
    }
}

void limpaSudoku(Sudoku *sudoku) {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            (*sudoku).tabuleiro[i][j] = 0;
        }
    }
}

void imprimeSudoku(Sudoku sudoku) {
    int i, j, k;

    for (i = 0; i < 9; i++) {

        if (i % 3 == 0) {
            for (k = 0; k < 8; k++)
                printf("---");
        }
        printf("\n");

        for (j = 0; j < 9; j++) {

            if (j == 0 || j % 3 == 0)
                printf("%s", "| ");

            printf("%d ", sudoku.tabuleiro[i][j]);

            if (j == 8)
                printf("%s", "| ");
        }
        printf("\n");

        if (i == 8) {
            for (k = 0; k < 8; k++) {
                printf("---");
            }
            printf("\n");
        }
    }
}

int posicaoVaziaSudoku(Sudoku sudoku, int *linha, int *coluna) {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (sudoku.tabuleiro[i][j] == 0) {
                *coluna = j;
                *linha = i;
                return 1;
            }
        }
    }

    return 0;
}

int posicaoSeguraSudoku(Sudoku *sudoku, int linha, int coluna, int numero) {

    int i, j;
    int posicaoLinhaGrid, posicaoColunaGrid;

    for (i = 0; i < 9; i++) { //verifica se a linha ja contem o numero
        if ((*sudoku).tabuleiro[linha][i] == numero)
            return 0;
    }

    for (i = 0; i < 9; i++) { //verifica se a coluna ja contem o numero
        if ((*sudoku).tabuleiro[i][coluna] == numero)
            return 0;
    }

    posicaoLinhaGrid = (linha - (linha % 3)); //calcula a linha inicial do grid 
    posicaoColunaGrid = (coluna - (coluna % 3)); //calcula a coluna inicial do grid

    for (i = 0; i < 3; i++) { //verifica se o numero esta contido neste grid
        for (j = 0; j < 3; j++) {
            if ((*sudoku).tabuleiro[i + posicaoLinhaGrid][j + posicaoColunaGrid] == numero)
                return 0;
        }
    }

    return 1;
}

int resolveSudoku(Sudoku *sudoku) {

    int i;
    int linhaVazia, colunaVazia;

    if (posicaoVaziaSudoku(*sudoku, &linhaVazia, &colunaVazia) == 0) //Caso não haja posicoes vasias o sudoku estara resolvido
        return 1;

    for (i = 1; i <= 9; i++) {
        if (posicaoSeguraSudoku(sudoku, linhaVazia, colunaVazia, i)) {
            (*sudoku).tentativas++;
            (*sudoku).tabuleiro[linhaVazia][colunaVazia] = i;

            if (resolveSudoku(sudoku))
                return 1;

            (*sudoku).tabuleiro[linhaVazia][colunaVazia] = 0;
        }
    }
    return 0;
}

