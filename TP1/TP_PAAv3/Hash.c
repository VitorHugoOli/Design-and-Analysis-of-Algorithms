
//
// Created by vho20 on 20/09/2018.
//
#include "Hash.h"

void Begin(THash *Lista){
    Lista->first=(apont)malloc(sizeof(TLista));
    Lista->last=Lista->first;
    Lista->last->prox=NULL;
}
int Check(THash Lista){
    return (Lista.last==Lista.first);
}
void Read(THash *Lista, int num){
    Lista->last->prox=(apont)malloc(sizeof(TLista));
    Lista->last=Lista->last->prox;
    Lista->last->Info=num;
    Lista->last->prox=NULL;
}
int Search (THash *Lista, int num){
    apont Paux;
   if(!Check(*Lista)){
        Paux=Lista->first->prox;
        while(Paux!=NULL){
            if(Paux->Info==num)
                return 1;
            Paux=Paux->prox;
        }
    }
    return 0;
}


