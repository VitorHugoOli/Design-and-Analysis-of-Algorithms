#include <stdio.h>
#include <stdlib.h>
#include "arq.h"
#include "Hash.h"
#include <time.h>
#include <windows.h>

void GeraValores(int *vet, int TamVet) {
    int i;
    //srand(time(NULL));
    for (i = 0; i < TamVet; i++) {
        vet[i] = rand() % 10000;

    }
}

void InicializaHash(THash hash[], int TamVet) {

    int i;
    for (i = 0; i < TamVet; i++) {
        Begin(&hash[i]);
    }
}

void GeraValoresHash(THash hash[], int TamVet, int *vet) {

    int i;
    int h;

    for (i = 0; i < TamVet; i++) {
        h = vet[i] % TamVet;
        if (!Search(&hash[h], vet[i])) {
                Read(&hash[h], vet[i]);
                //printf("--h: %d --> %d\n", h,hash[h].first->prox->Info);
        }
    }
}

float Busca3(THash hash[], int TamVet, int chave) {

    int i = 0;
    int NumSub;
    int h, flag = 0;
    apont Paux;

    LARGE_INTEGER tf, ti, freq;
    float TempoTotal;

    QueryPerformanceCounter(&ti);

    while (i < TamVet) {
        Paux = hash[i].first->prox;
        if (!Check(hash[i])) {
            while (Paux != NULL) {
                NumSub = chave - Paux->Info;
                h = NumSub % TamVet;

                //printf("h:---%d---\n\n", h);
                //printf("Chechk:---%d---\n\n", Check(hash[h]));

                //printf("verf:---%d---\n\n", (hash[h].last==hash[h].first));
                if (!Check(hash[h]) ){
                        //printf("first:---%d---\n\n", hash[h].first);
                        //printf("last:---%d---\n\n", hash[h].last);
                        if (Search(&hash[h], NumSub)) {
                            printf("%d %d\n", NumSub, Paux->Info);
                            fprintf(arquivo, "Valor encontrado! %d + %d = %d!\n", Paux->Info, NumSub, chave);
                            flag = 1;
                            break;
                        }
                }
                Paux = Paux->prox;
            }
        }
        if (flag == 1) {
            break;
        }
        i++;
    }

    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    TempoTotal = (float) (tf.QuadPart - ti.QuadPart) / freq.QuadPart;


    fprintf(arquivo, "3 - tempo de Busca2: %lf segundos\n", TempoTotal);

    return TempoTotal;
}

float SelectSort(int *vetor, int TamVet) {

    int i, j, min, aux;
    LARGE_INTEGER tf, ti, freq;
    float TempoTotal;

    QueryPerformanceCounter(&ti);


    for (i = 0; i < (TamVet - 1); i++) {
        /* O minimo é o primeiro número não ordenado ainda */
        min = i;
        for (j = i + 1; j < TamVet; j++) {
            /* Caso tenha algum numero menor ele faz a troca do minimo*/
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
        if (i != min) {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;

        }
    }
    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    TempoTotal = (float) (tf.QuadPart - ti.QuadPart) / freq.QuadPart;

    fprintf(arquivo, "1 - Tempo de ordenacao: %lf\n", TempoTotal);

    return TempoTotal;
}

/*------------------------------------Metodo Quick-------------------------------------*/
float QuickSort(int *vetor, int TamVet) {
    int i;
    LARGE_INTEGER tf, ti, freq;
    float TempoTotal;

    QueryPerformanceCounter(&ti);
    Ordenacao(vetor, 0, TamVet - 1);//primeira chamada para ordenacao;
    //----------------------------------Vetor ja esta ordenado!-------------------------------------------------

    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    TempoTotal = (float) (tf.QuadPart - ti.QuadPart) / freq.QuadPart;

    fprintf(arquivo, "1 - Tempo de ordenacao: %lf\n", TempoTotal);

    return TempoTotal;

}

void Particao(int *v, int esq, int dir, int *i, int *j)  //utilizada pelo QuickSort
{

    int pivo;
    int temp;
    *i = esq;
    *j = dir;
    pivo = v[(*i + *j) / 2];

    do {
        while (pivo > v[*i]) {

            (*i)++;
        }
        while (pivo < v[*j]) {

            (*j)--;
        }
        if (*i <= *j) {

            temp = v[*i];
            v[*i] = v[*j];
            v[*j] = temp;
            (*i)++;
            (*j)--;

        }

    } while (*i <= *j);
}

void Ordenacao(int *v, int esq, int dir)  //utilizada pelo QuickSort
{

    int i, j;
    Particao(v, esq, dir, &i, &j);

    if (esq < j) {
        Ordenacao(v, esq, j);
    }
    if (i < dir) {
        Ordenacao(v, i, dir);
    }
}

float Busca(int *vet, int TamVet, int chave) {
    int inf, sup, meio, i = 0;
    inf = 0;
    sup = TamVet - 1;
    LARGE_INTEGER tf, ti, freq;
    float TempoTotal;

    QueryPerformanceCounter(&ti);

    while (vet[i] < chave)//desnecessária a comparação com valores maiores que a chave.
    {
        inf = i;
        sup = TamVet - 1;
        while (inf <= sup) {
            meio = (inf + sup) / 2;
            if (vet[i] + vet[meio] == chave) {
                fprintf(arquivo, "Valor encontrado! %d + %d = %d!\n", vet[i], vet[meio], chave);
                chave = 10000000;
                break;
            } else if (vet[i] + vet[meio] > chave) {
                sup = meio - 1;
            } else {
                inf = meio + 1;
            }
        }
        i++;
    }

    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    TempoTotal = (float) (tf.QuadPart - ti.QuadPart) / freq.QuadPart;


    fprintf(arquivo, "2 - tempo de Busca: %lf segundos\n", TempoTotal);

    return TempoTotal;
}

float Busca2(int *vet, int TamVet, int chave) {
    int i = 0, j;
    int Flag = 0, NumSub;
    LARGE_INTEGER tf, ti, freq;
    float TempoTotal;

    QueryPerformanceCounter(&ti);

    while (vet[i] < chave || i < TamVet) {
        NumSub = chave - vet[i];
        for (j = i; j < TamVet; j++) {
            if (vet[j] == NumSub) {
                fprintf(arquivo, "Valor encontrado! %d + %d = %d!\n", vet[i], NumSub, chave);
                Flag = 1;
                break;
            }
            if (vet[j] > NumSub)
                break;
        }
        if (Flag == 1) {
            break;
        }
        i++;
    }

    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    TempoTotal = (float) (tf.QuadPart - ti.QuadPart) / freq.QuadPart;


    fprintf(arquivo, "3 - tempo de Busca2: %lf segundos\n", TempoTotal);

    return TempoTotal;
}




