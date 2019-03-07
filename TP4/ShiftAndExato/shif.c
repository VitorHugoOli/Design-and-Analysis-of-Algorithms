//
// Created by vho20 on 28/11/2018.
//

#include "shif.h"
void Main(int debug){
    TipoTexto T;
    TipoPadrao P;
    int opc=0;
    lerarq(T);
    while (opc!=3){
        printf("1 - Digite novo texto;\n");
        printf("2 - Padrão a ser buscado;\n");
        printf("3 - Sair;\n");
        printf("Digite sua escolha: ");
        scanf("%d",&opc);
        if(opc==1) lerarq(T);
        else if(opc==2) Busca(P,T,debug);
        else printf("Opção invalida;\n");
    }
    system("Pause");
}

/*
 * Algoritimo retirado do pdf 05 da Aulda de PAA;
 */
void ShiftAndAproximado(TipoTexto T, long n, TipoPadrao P, long m, int debug) {
    LARGE_INTEGER tf, ti, freq;
    float TempoTotal;

    QueryPerformanceCounter(&ti);



     long Masc[MAxCHAR], i, R = 0;
     long words=0;
        for (i = 0; i < MAxCHAR; i++)
            Masc[i] = 0;
        for (i = 1; i <= m; i++)
            Masc[P[i-1] + 127] |= 1 << (m - i);
        for (i = 0; i < n; i++)
        { R = ((((unsigned long)R) >> 1) |
               (1 << (m - 1))) & Masc[T[i] + 127];
            if ((R & 1) != 0) {
                words++;
                printf(" Casamento na posicao %3ld\n", i - m + 2);
            }
        }


    printf("Houveram %ld ocorrências da plavra \"%s\"\n",words,P);
    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    TempoTotal = (float) (tf.QuadPart - ti.QuadPart) / freq.QuadPart;
    if(debug==1)
        printf("O tempo total gasto para achar as ocorrências foi de: %f segundos \n\n",TempoTotal);
    system("Pause");
    system("CLS");
}
void lerarq(TipoTexto T){
    FILE *arq;
    char nomearq[30];
    printf("Digite o nome do texto a ser inserido: ");
    scanf("%s",nomearq);
    while ((arq=fopen(nomearq,"r")) == NULL){
        printf("--ERRO--\nDigite novamente o nome do texto a ser inserido: ");
        scanf("%s",nomearq);
    }
    int i=0;
    int palavras=0;
    while (fscanf(arq,"%c",&T[i])!=EOF){
            if(T[i]==' '){
                palavras++;
            }
        i++;
    }
    printf("Há %d palavras nesse texto\n\n",palavras);
    T[i++]='\0';
}
void Busca(TipoPadrao P,TipoTexto T,int debug){
    printf("Digite o padrão a ser pesquisado: ");
    scanf("%s",P);
    printf("\n\n");
    ShiftAndAproximado(T,(long)strlen(T),P,(long)strlen(P),debug);
}
