
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdint.h>
#define DEBUG 1

struct piramide{
    int **tabela;
    int **matriz; // Matriz para guardar as soluções momentanias
    int tamanho;
};

typedef struct piramide *Piramide;
int  maximo(int a, int b);
int** alocarMatriz(int linhas);
void inicializarMatriz(Piramide p);
Piramide inicializarPiramide(char *nomeArq);
void imprimirPiramide(Piramide p);
void imprimirTabela(Piramide p);
int contarLinhas(char *nomeArq);
void deTrazParaFrente(Piramide p);
int recursivoPadrao(int i, int j, Piramide p);
void apagarPiramide(Piramide p);
int recursivoMemoization(int i, int j, Piramide p);
int imprimirRota(Piramide p);
void copiarMatriz(Piramide p);
void menu();



