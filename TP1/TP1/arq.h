#include "Hash.h"

#define LimpaTela system("cls")
FILE *arquivo;


//--------------------------funcoes----------------------------------------------------
void GeraValores(int *vet,int tam);
void GeraValoresHash(THash hash[],int TamVet,int *vet);
void InicializaHash(THash hash[],int TamVet);
float SelectSort (int *vetor,int TamVet);
float QuickSort (int *vetor, int TamVet);
void Particao(int *v, int esq, int dir, int *i, int *j);
void Ordenacao(int *v, int esq, int dir);
float Busca (int *vet, int TamVet, int chave);
float Busca2 (int *vet, int TamVet, int chave);
float Busca3 (THash hash[], int TamVet, int chave);

