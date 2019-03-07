//
// Created by vho20 on 20/09/2018.
//

#ifndef TP1_PAAV1_HASH_H
#define TP1_PAAV1_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

typedef struct lista *apont;
typedef struct lista {
    int Info;
    apont prox;
}TLista;

typedef struct {
    apont first;
    apont last;
}THash;

void Begin(THash *Lista);
void Read(THash *Lista, int num);
int Search (THash *Lista, int num);
int Check(THash Lista);

#endif //TP1_PAAV1_HASH_H
