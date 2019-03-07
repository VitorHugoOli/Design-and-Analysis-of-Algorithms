//
// Created by vho20 on 25/10/2018.
//

#ifndef TP2_CACAPALAVRAS_H
#define TP2_CACAPALAVRAS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char **palavraCruzadas;
    char **final;
    int  comparacoes;
    int linha,coluna;
}Matriz;


void menuCruzadas(int analise);
void LerArq(FILE **file);
void GeraMatriz(FILE *file,Matriz *letras);
int backtracking(Matriz *letras, char *palavra, int analise);
int backtrackingOp(Matriz *letras,char *palavra,int i,int j,char direcao, int *contrecusi,int *ocorrencia);
void mostraMatriz(Matriz letras);
void mostraMatrizFinal(Matriz letras);
#endif //TP2_CACAPALAVRAS_H
