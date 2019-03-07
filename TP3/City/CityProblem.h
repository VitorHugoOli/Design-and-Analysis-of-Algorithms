//
// Created by vho20 on 17/11/2018.
//

#ifndef TP3_CITYPROBLEM_H
#define TP3_CITYPROBLEM_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>


typedef struct {
    char **ruas;
    int x,y;
    int xi,yi;
    int xf,yf;
}Quadriculado;

int LerArq(Quadriculado *city);
void ShowCity(Quadriculado city);
void CityProblem(Quadriculado *city, int debug);
void Main(int debug);
void Obra(Quadriculado *city);
int Caminho(Quadriculado city, double count[][city.y+1],char clone[][city.y+1],int i,int j);


#endif //TP3_CITYPROBLEM_H
