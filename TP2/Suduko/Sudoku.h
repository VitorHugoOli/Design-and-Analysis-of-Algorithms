#include <stdlib.h>
#include <stdio.h>


typedef struct {
    int tabuleiro[9][9];
    int tentativas;
} Sudoku;

int posicaoVaziaSudoku(Sudoku sudoku, int *linha, int *coluna) ;
int preencheSudoku(Sudoku *sudoku, char *nomeArquivo);
void imprimeSudoku(Sudoku sudoku);
void limpaSudoku(Sudoku *sudoku);
int resolveSudoku(Sudoku *sudoku);
void menuSudoku();
void case1(Sudoku sudoku);
void case2(Sudoku sudoku);

