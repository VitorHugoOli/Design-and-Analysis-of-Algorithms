
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 150


void BMH(char T[], char P[],int linha)
{
    int n = strlen (T);
    int m = strlen (P);
    long i, j, k, d[MAX + 1];

    // Preprocessamento para obter a tabela de deslocamento
    for(j=0; j<=MAX; j++)
    {
        d[j] = m;
    }
    for(j=1; j<m; j++)
    {
        d[P[j-1]] = m - j;
        i = m;
    }

    while(i<=n)
    {
        k = i;
        j = m;
        // Profura por um sufixo do texto que casa com um sufixo do padrão
        while(T[k-1] == P[j-1] && j > 0)
        {
            k--;
            j--;
        }

        if(j==0)
        {
            printf("\tCasamento na posicao: %3ld, na linha %d\n", k, linha);
        }
        // Deslocamento da janela de acordo com o valor da tabela de deslocamento relativo ao caractere que esta
        // na i-esima -1 posicaodo texto,ou seja, a posicao do ultimo caractere do padra p.
        i = i + d[T[i-1]];
    }
}

void BMHS(char T[], char P[],int linha)
{
    int n = strlen (T);
    int m = strlen (P);
    long i, j, k, d[MAX + 1];

    // Preprocessamento para obter a tabela de deslocamento
    for(j=0; j<=MAX; j++)
    {
        d[j] = m + 1;
    }
    for(j=1; j<m; j++)
    {
        d[P[j-1]] = m - j + 1;
        i = m;
    }

    while(i<=n)
    {
        k = i;
        j = m;
        // Profura por um sufixo do texto que casa com um sufixo do padrão
        while(T[k-1] == P[ j-1] && j > 0)
        {
            k--;
            j--;
        }

        if(j==0)
        {
            printf("\tCasamento na posicao: %3ld, na linha %d\n", k, linha);
        }
        // Deslocamento da janela de acordo com o valor da tabela de deslocamento relativo ao caractere que esta
        // na i-esima -1 posicaodo texto,ou seja, a posicao do ultimo caractere do padra p.
        i = i + d[T[i]];
    }
}
