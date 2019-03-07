#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arq.h"
#include <time.h>
#include <windows.h>
#define QtdExe 5
#define LimiteTeste 28


void InicializaHash(THash hash[], int tamVet) {

    int i;
    for (i = 0; i < tamVet; i++) {
        Begin(&hash[i]);
    }
}

float GeraValoresHash(THash hash[], int tamVet, int *vetor) {

    int i;
    int h;

    LARGE_INTEGER tf, ti, freq;
    float TempoTotal;

    QueryPerformanceCounter(&ti);

    for (i = 0; i < tamVet; i++) {
        h = vetor[i] % tamVet;
        if (!Search(&hash[h], vetor[i])) {
                Read(&hash[h], vetor[i]);
                //printf("--h: %d --> %d\n", h,hash[h].first->prox->Info);
        }
    }

    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    TempoTotal = (float) (tf.QuadPart - ti.QuadPart) / freq.QuadPart;


    fprintf(arquivo, "Tempo de Mapeamento Hash: %lf segundos\n", TempoTotal);
    return  TempoTotal;
}

float Busca3(THash hash[], int tamVet, int chave) {

    int i = 0;
    int NumSub;
    int h, flag = 0;
    apont Paux;

    LARGE_INTEGER tf, ti, freq;
    float TempoTotal;

    QueryPerformanceCounter(&ti);

    while (i < tamVet) {
        Paux = hash[i].first->prox;
        if (!Check(hash[i])) {
            while (Paux != NULL) {
                NumSub = chave - Paux->Info;
                h = NumSub % tamVet;
                if (!Check(hash[h]) && NumSub>1){
                        if (Search(&hash[h], NumSub)) {
                            fprintf(arquivo, "Valor encontrado =  %d + %d = %d\n", Paux->Info, NumSub, chave);
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


    fprintf(arquivo, "Tempo de Busca Hash: %lf segundos\n", TempoTotal);

    return TempoTotal;
}

void GeraValores(int *vetor, int tamVetor) {

    int i;
    srand (time(NULL));
    for(i=0; i<tamVetor; i++)
    {
        vetor[i]=rand()%10000;

    }
}

float SelectSort (int *vetor,int tamVetor) {

    int i, j, min, aux;
    LARGE_INTEGER tf, ti, freq;
    float tempTotal;

    QueryPerformanceCounter(&ti);


    for (i = 0; i < (tamVetor - 1); i++)
    {
        /* O min é o primeiro número não ordenado até então */
        min = i;
        for (j = i+1; j < tamVetor; j++)
        {
            /* Caso tenha algum numero menor ele faz a troca do min*/
            if (vetor[j] < vetor[min])
            {
                min = j;
            }
        }
        /* Se o min for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
        if (i != min)
        {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;

        }
    }
    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    tempTotal = (float)(tf.QuadPart - ti.QuadPart)/freq.QuadPart;

    fprintf(arquivo,"Tempo de ordenacao: %lf\n",tempTotal);

    return tempTotal;
}

float QuickSort (int *vetor, int tamVetor) {
    int i;
    LARGE_INTEGER tf, ti, freq;
    float tempTotal;

    QueryPerformanceCounter(&ti);
    Ordenacao(vetor, 0, tamVetor-1);//primeira chamada para ordenacao

    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    tempTotal = (float)(tf.QuadPart - ti.QuadPart)/freq.QuadPart;

    fprintf(arquivo,"Tempo de ordenacao: %lf\n",tempTotal);

    return tempTotal;

}

void Particao(int *v, int esq, int dir, int *i, int *j) {

    int pivo;
    int temp;
    *i = esq;
    *j = dir;
    pivo = v[(*i + *j)/2];

    do
    {
        while(pivo > v[*i])
        {

            (*i)++;
        }
        while(pivo < v[*j])
        {

            (*j)--;
        }
        if(*i<=*j)
        {

            temp = v[*i];
            v[*i] = v[*j];
            v[*j] = temp;
            (*i)++;
            (*j)--;

        }

    }

    while(*i<=*j);
}

void Ordenacao(int *v, int esq, int dir) {

    int i, j;
    Particao(v, esq, dir, &i, &j);

    if(esq < j)
    {
        Ordenacao(v, esq, j);
    }
    if(i < dir)
    {
        Ordenacao(v, i, dir);
    }
}

float Busca (int *vetor, int tamVetor, int chave) {
    int inf,sup,meio,i=0;
    inf=0;
    sup=tamVetor-1;
    LARGE_INTEGER tf, ti, freq;
    float tempTotal;

    QueryPerformanceCounter(&ti);

    while (vetor[i] < chave)//desnecessária a comparação com valores maiores que a chave.
    {
        inf = i;
        sup=tamVetor-1;
        while (inf<=sup)
        {
            meio=(inf+sup)/2;
            if (vetor[i] + vetor[meio] == chave){
                fprintf(arquivo,"Valor encontrado =  %d + %d = %d\n",vetor[i],vetor[meio],chave);
                chave = 10000000;
                break;
            }
            else if (vetor[i] + vetor[meio]>chave){
                sup=meio-1;
            }
            else{
                inf=meio+1;
            }
        }
        i++;
    }

    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    tempTotal = (float)(tf.QuadPart - ti.QuadPart)/freq.QuadPart;



    fprintf(arquivo,"Tempo de Busca: %lf segundos\n",tempTotal);

    return tempTotal;
}

float Busca2 (int *vetor, int tamVetor, int chave) {
    int i=0,j;
    int flag=0,numSub;
    LARGE_INTEGER tf, ti, freq;
    float tempTotal;

    QueryPerformanceCounter(&ti);

    while (vetor[i] < chave || i<tamVetor){
        numSub=chave-vetor[i];
        for(j=i;j<tamVetor;j++){
            if(vetor[j]==numSub){
                fprintf(arquivo,"Valor encontrado =  %d + %d = %d\n",vetor[i],numSub,chave);
                flag=1;
                break;
            }
            if(vetor[j]>numSub)
                break;
        }
        if(flag==1){
            break;
        }
        i++;
    }

    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    tempTotal = (float)(tf.QuadPart - ti.QuadPart)/freq.QuadPart;



    fprintf(arquivo,"Tempo de Busca2: %lf segundos\n",tempTotal);

    return tempTotal;
}

void menuCase1(){
    fprintf(arquivo,"+---------------------------------------------------------------------------+\n"
                    "|                     Opção com entrada automatica                          |\n"
                    "+---------------------------------------------------------------------------+\n");

	int *vetor,i;
    THash *Hash;
	int tamVet[LimiteTeste] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000,30000,40000,50000,60000,70000,80000,90000,100000};
	int X,j;
	float tempExec =0.0,tempExecAll=0.0;

	GeraValores(&X,1);//fornece um valor aleatorio para X

	fprintf(arquivo,"Valor de X : %d\n",X);

    for(j=0; j<LimiteTeste; j++)

    {
        printf("Processando N = %d\n",tamVet[j]);
        fprintf(arquivo,"\n------------------------------Método Select Sort Tamanho do vetor aleatorio: %d----------------------------------------------\n",tamVet[j]);
        for (i=0; i<QtdExe; i++)
        {

            Hash=(THash*)malloc(sizeof(THash)*tamVet[j]);
            vetor = (int*)malloc(sizeof(int)*tamVet[j]);
            InicializaHash(Hash,tamVet[j]);
            GeraValores(vetor,tamVet[j]);
            tempExec += SelectSort(vetor,tamVet[j]) + GeraValoresHash(Hash,tamVet[j],vetor) + Busca(vetor,tamVet[j],X)  + Busca2(vetor,tamVet[j],X) + Busca3(Hash,tamVet[j],X);
            free(vetor);
            free(Hash);
            fprintf(arquivo,"Tempo total: %lf\n\n",tempExec);
            tempExecAll+=tempExec;
            tempExec=0.0;
        }
        fprintf(arquivo,"TEMPO MÉDIO TOTAL: %lf\n\n",tempExecAll/QtdExe);
        tempExecAll = 0.0;
        fprintf(arquivo,"\n------------------------------Método Quick Sort Tamanho do vetor aleatorio: %d----------------------------------------------\n",tamVet[j]);
        for (i=0; i<QtdExe; i++)
        {
            Hash=(THash*)malloc(sizeof(THash)*tamVet[j]);
            vetor = (int*)malloc(sizeof(int)* tamVet[j]);
            InicializaHash(Hash,tamVet[j]);
            GeraValores(vetor,tamVet[j]);
            tempExec += QuickSort(vetor,tamVet[j]) +GeraValoresHash(Hash,tamVet[j],vetor) + Busca(vetor,tamVet[j],X)  + Busca2(vetor,tamVet[j],X) + Busca3(Hash,tamVet[j],X);
            free(vetor);
            free(Hash);
            fprintf(arquivo,"Tempo total: %lf\n\n",tempExec);
            tempExecAll+=tempExec;
            tempExec=0.0;
        }
        fprintf(arquivo,"TEMPO MÉDIO TOTAL: %lf\n\n",tempExecAll/QtdExe);
    }

    printf("Arquivo Criado com sucesso!!\n");
}

void menuCase2(){
    fprintf(arquivo,"+---------------------------------------------------------------------------+\n"
                    "|                      Opção com entrada manual                             |\n"
                    "+---------------------------------------------------------------------------+\n");
    int tamEscolha;
    printf("Digite o tamanho desejado a ser testado:");
    scanf("%d",&tamEscolha);

    int *vetor,i;
    THash *Hash;
    int X;
    float tempExec =0.0,tempExecAll=0.0;

    GeraValores(&X,1);//fornece um valor aleatorio para X

    fprintf(arquivo,"Valor de X : %d\n",X);

    fprintf(arquivo,"\n------------------------------Método Select Sort Tamanho do vetor aleatorio: %d----------------------------------------------\n",tamEscolha);
    for (i=0; i<QtdExe; i++)
    {

        Hash=(THash*)malloc(sizeof(THash)*tamEscolha);
        vetor = (int*)malloc(sizeof(int)*tamEscolha);
        InicializaHash(Hash,tamEscolha);
        GeraValores(vetor,tamEscolha);
        tempExec += SelectSort(vetor,tamEscolha) + GeraValoresHash(Hash,tamEscolha,vetor) + Busca(vetor,tamEscolha,X)  + Busca2(vetor,tamEscolha,X) + Busca3(Hash,tamEscolha,X);
        free(vetor);
        free(Hash);
        fprintf(arquivo,"Tempo total: %lf\n\n",tempExec);
        tempExecAll+=tempExec;
        tempExec=0.0;
    }
    fprintf(arquivo,"TEMPO MÉDIO TOTAL: %lf\n\n",tempExecAll/QtdExe);
    tempExecAll = 0.0;
    fprintf(arquivo,"\n------------------------------Método Quick Sort Tamanho do vetor aleatorio: %d----------------------------------------------\n",tamEscolha);

    for (i=0; i<QtdExe; i++)
    {
        Hash=(THash*)malloc(sizeof(THash)*tamEscolha);
        vetor = (int*)malloc(sizeof(int)* tamEscolha);
        InicializaHash(Hash,tamEscolha);
        GeraValores(vetor,tamEscolha);
        tempExec += QuickSort(vetor,tamEscolha) +GeraValoresHash(Hash,tamEscolha,vetor) + Busca(vetor,tamEscolha,X)  + Busca2(vetor,tamEscolha,X) + Busca3(Hash,tamEscolha,X);
        free(vetor);
        free(Hash);
        fprintf(arquivo,"Tempo total: %lf\n\n",tempExec);
        tempExecAll+=tempExec;
        tempExec=0.0;
    }
    fprintf(arquivo,"TEMPO MÉDIO TOTAL: %lf\n\n",tempExecAll/QtdExe);


    printf("Arquivo Criado com sucesso!!\n");
}