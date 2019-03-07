#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

void KMPMatcher(char *pattern, int M, int *pi);

void KMP(char *pattern, char *txt,int linha)
{
    int M = strlen(pattern);
    int N = strlen(txt);

    // Cria pi[] que armazenará o maior prefixo para o padrao.
    int *pi = (int *)malloc(sizeof(int)*M);
    int j  = 0; // Indice para o pattern[]

    KMPMatcher(pattern, M, pi);

    int i = 0;  //indice para o TXT[]

	while(i < N)
    {
        if(pattern[j] == txt[i])
        {
            j++;
            i++;
        }

        if(j == M)
        {
            printf("\tCasamento padrao na posicao: %d, na linha %d\n", i-j,linha);
            j = pi[j-1];
        }

        // Conflito depois de ocorrer j correspondencias
        else if(pattern[j] != txt[i])
        {
            if(j != 0)
                j = pi[j-1];
            else
                i = i+1;
        }
    }
    free(pi);
}

void KMPMatcher(char *pattern, int M, int *pi)
{
    int q = 0; // q número de caracteres do prefixo.
    int i;

    pi[0] = 0;
    i = 1;

	// Calcula pi[i] para i = 1 até o tamanho do padrão (M-1).
    while(i < M)
    {
        if(pattern[i] == pattern[q])
        {
            q++;
            pi[i] = q;
            i++;
        }
        else
        {
            if(q != 0)
            {
				// O vetor pi que armazena o maior prefixo nao reduzido encontrado.
                q = pi[q-1];
            }
            else
            {
                pi[i] = 0;
                i++;
            }
        }
    }
}

