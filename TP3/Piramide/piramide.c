#include "piramide.h"

void menu()
{
    char nome[10];
    Piramide p;
    int op, arq = 0;
    float TempoTotal=0;
    clock_t Ticks[2];
    float mediaTempoMemmoization=0;
    int resultado;

    do
    {
        printf("\n\t############## Programa Tarefa A ################");
        printf("\n\t# 1) Entrar com o Arquivo                       #");
        printf("\n\t# 2) Imprimir Pirâmide                          #");
        printf("\n\t# 3) Executar Algoritmo Recursivo               #");
        printf("\n\t# 4) Executar Algoritmo com 'Memoization'       #");
        printf("\n\t# 5) Executar Algoritmo 'De Trás para Frente'   #");
        printf("\n\t# 6) Imprimir Rota                              #");
        printf("\n\t#################################################\n");
        printf("\n\t Entre com alguma das opção: ");
        scanf("%d", &op);

        if (op >= 1 && op < 8){

            system("clear");
            switch (op)
            {
            case 1:
                if(arq)
                {
                    apagarPiramide(p); // Apagar dados anteriores
                    arq = 0;
                }

                do
                {
                    printf("\n\tEntre com o nome do arquivo(e a extensão): ");
                    setbuf(stdin, NULL);
                    gets(nome);
                    p = inicializarPiramide(nome);
                    if(p == NULL)
                    {
                        printf("\n\tArquivo não encontrado. Tente novamente!\n");
                    }
                }
                while(p == NULL);

                arq = 1;
                break;

            case 2:
                if(arq)
                {
                    imprimirPiramide(p);
                    printf("\n");
                }
                else
                {
                    printf("\n\tCarregue um arquivo de dados!\n");
                }
                break;

            case 3:
                if(arq)
                {
                    if(DEBUG)
                    {
                        Ticks[0] = clock();
                    }
                    printf("\tAlgoritmo Recursivo");
                    printf("\n\n\tMaior soma: %d\n", recursivoPadrao(0,0,p));

                    if(DEBUG)
                    {
                        Ticks[1] = clock();
                        TempoTotal = (Ticks[1] - Ticks[0]) * 1000.0 / (float)CLOCKS_PER_SEC;
                        printf("\n\tTempo total: %f\n\n", TempoTotal);
                    }
                }
                else
                {
                    printf("\n\tCarregue um arquivo de dados!\n");
                }
                break;

            case 4:
                if(arq)
                {
                    if(DEBUG)
                    {
                        Ticks[0] = clock();
                    }
                    printf("\tAlgoritmo com Memoization");
                    printf("\n\tMaior soma: %d\n", recursivoMemoization(0,0,p));

                    if(DEBUG)
                    {
                        Ticks[1] = clock();
                        TempoTotal = (Ticks[1] - Ticks[0]) * 1000.0 / (float)CLOCKS_PER_SEC;
                        printf("\n\tTempo total: %f\n\n", TempoTotal);
                    }
                }
                else
                {
                    printf("\n\tCarregue um arquivo de dados!\n");
                }
                break;

            case 5:
                if(arq)
                {
                    copiarMatriz(p);
                    if(DEBUG)
                    {
                        Ticks[0] = clock();
                    }

                    deTrazParaFrente(p);
                    printf("\tAlgoritmo de Trás para Frente");
                    printf("\n\tMaior soma: %d\n", p->tabela[0][0]);

                    if(DEBUG)
                    {
                        Ticks[1] = clock();
                        TempoTotal = (Ticks[1] - Ticks[0]) * 1000.0 / (float)CLOCKS_PER_SEC;
                        printf("\n\tTempo total: %f\n\n", TempoTotal);
                    }
                }
                else
                {
                    printf("\n\tCarregue um arquivo de dados!\n");
                }
                break;

            case 6:
                imprimirRota(p);
                break;

            case 7:
               if(arq)
                {
                    int i;
                    printf("\tAlgoritmo com Memoization");
                    for(i=0; i<1000; i++){

                        Ticks[0] = clock();
                        printf("\n\tMaior soma: %d\n", recursivoMemoization(0,0,p));
                        Ticks[1] = clock();
                        //mediaTempoMemmoization[i] = (Ticks[1] - Ticks[0]) * 1000.0 / (float)CLOCKS_PER_SEC;

                    }
                    printf("Media de tempos de 1000 iterações, %s.\n", (mediaTempoMemmoization/1000));

                    if(DEBUG)
                    {
                        Ticks[1] = clock();
                        TempoTotal = (Ticks[1] - Ticks[0]) * 1000.0 / (float)CLOCKS_PER_SEC;
                        printf("\n\tTempo total: %f\n\n", TempoTotal);
                    }
                }
                else
                {
                    printf("\n\tCarregue um arquivo de dados!\n");
                }
                break;

            }

            printf("\n\tDigite ENTER para continuar.");
            setbuf(stdin, NULL);
            getchar();
        }
        system("clear");

    } while(op >= 1 && op < 8);
    return;
}

/* selecionar maior valor*/
int maximo(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

/* Aloca espaço na memória  */
int** alocarMatriz(int linhas){
    int i;
    int **m = (int**) malloc(linhas*sizeof(int*));

    if(m == NULL)
    {
        printf("\n\tErro!\n");
        return NULL;
    }
    for(i = 0; i < linhas; i++)
    {
        m[i] = (int*) malloc(linhas*sizeof(int));
    }
    return m;
}

/* Inicializa a matriz com 0s. */
void inicializarMatriz(Piramide p){
    int i,j;

    for(i=0; i < p->tamanho; i++)
        for(j=0; j <  p->tamanho; j++)
        {
            p->matriz[i][j] = 0;
            p->tabela[i][j] = 0;
        }
}

/* Inicializa a pirâmide */
Piramide inicializarPiramide(char *nomeArq){
    int linhasArq, i, j;
    Piramide p = (Piramide) malloc(sizeof(struct piramide));

    FILE *arquivo = fopen(nomeArq, "r");

    if(arquivo == NULL)
    {
        printf("\n\tErro!!!\n");
        return NULL;
    }
    fclose(arquivo);


    linhasArq = contarLinhas(nomeArq); // Conta o numero de linhas
    p->tamanho = linhasArq; // Tamanho da piramide


    p->matriz = alocarMatriz(linhasArq); // Aloca matriz.
    p->tabela = alocarMatriz(linhasArq);

    inicializarMatriz(p);

    arquivo = fopen(nomeArq, "r");

    for(i=0; i < linhasArq; i++)
    {
        for(j=0; j <= i ; j++)
        {
            fscanf(arquivo,"%d", &(p->matriz[i][j]));
        }
    }
    return p;
}

/* Imprime a pirâmide. */
void imprimirPiramide(Piramide p){
    int i, j;

    printf("\n");
    for(i=0; i < p->tamanho; i++)
    {
        printf("\t");
        for(j=0; j <= i; j++)
        {
            printf("[%d] ", p->matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Inicializa a tabela */
void imprimirTabela(Piramide p){
    int i, j;

    printf("\n");
    for (i=0; i < p->tamanho; i++)
    {
        printf("\t");
        for(j=0; j <= i; j++)
        {
            printf("[%02d] ", p->tabela[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Conta numero linhas do arquivo */
int contarLinhas(char *nomeArq){
    FILE *arquivo = fopen(nomeArq, "r");
    int num = 0;
    char ch;

    while((ch = fgetc(arquivo)) != EOF)
    {
         if(ch == '\n')
         {
           num++;
         }
    }
    fclose(arquivo);
    num++;

    return num;
}

/* Método "de trás para frente" (Programação Dinâmica) */

void deTrazParaFrente(Piramide p){// analisa a penultima com as ultimas posiçoes;
    int i,j;

    for(i=p->tamanho - 2; i >= 0; i--)
    {
        for(j=0; j <= i; j++)
        {
            p->tabela[i][j] = p->tabela[i][j] + maximo(p->tabela[i + 1][j], p->tabela[i + 1][j + 1]); // Atualiza com a solução dos subproblemas.
        }
    }
}

/* Método Recursivo Padrão */
int recursivoPadrao(int i, int j, Piramide p){// Empilha os valores para achar o maior;
    if(i == p->tamanho-1)
    {
        return p->matriz[i][j];
    }
    else
    {
        return (p->matriz[i][j] + maximo(recursivoPadrao(i+1, j, p), recursivoPadrao(i+1, j+1, p)));
    }
}

/* Libera espaço na memória, apagando a pirâmide. */
void apagarPiramide(Piramide p){
    int i;
    for (i=0; i < p->tamanho; i++)
    {
        free(p->matriz[i]);
        free(p->tabela[i]);
    }
    free(p->matriz);
    free(p->tabela);
}

/* Método Recursivo com "Memoization" */

int recursivoMemoization(int i, int j, Piramide p){//Guarda os valores em uma tabela, ultima caso base
    int x;
    if (i == p->tamanho-1 )
    {
        return p->matriz[i][j];
    }
    else
    {
        x = (p->matriz[i][j] + maximo(recursivoMemoization(i+1, j, p), recursivoMemoization(i+1, j+1, p)));
        p->tabela[i][j] = x;
        return x;
    }
}

/* Imprime rota com a maior soma. */
int imprimirRota(Piramide p){
    if(p->tabela[0][0] != 0)
    {
        int i, j = 0;

        printf("\n\tSequencia para maior soma:\n\n");
        for(i=0; i < p->tamanho; i++)
        {
            if(p->tabela[i][j] >= p->tabela[i][j+1])
                printf("\t[%d][%d] = %d ", i, j, p->matriz[i][j]);
            else
            {
                printf("\t[%d][%d] = %d ", i, j+1, p->matriz[i][j+1]);
                j++;
            }
            if(i<p->tamanho-1)
            {
                printf("\n");
            }
        }
        printf("\n\n\n");

    }
    else
    {
        printf("\n\tConstrua a tabela!\n\n");
    }
    return 0;
}

/* Copia valores da matriz para atualização. */
void copiarMatriz(Piramide p){
    int i,j;
    for(i=0; i<p->tamanho; i++)
    {
        for(j=0; j <= i; j++)
        {
            p->tabela[i][j] = p->matriz[i][j];
        }
    }

}

