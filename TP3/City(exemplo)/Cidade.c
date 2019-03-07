
#include "Cidade.h"

int caminhosPossiveis(char *nome)
{
    FILE *arquivo;

    int n, m, iX, iY, fX, fY;
    int x, y;
    char direcao;

    arquivo = fopen(nome, "r");

    if(arquivo == NULL)
    {
        printf("\tErro na leitura do arquivo!\n\n");
        system("PAUSE");
        return 0;
    }

    // Número de linhas e colunas.
    fscanf(arquivo, "%d %d", &n, &m);

    // Coordenadas (x, y) do ponto inicial.
    fscanf(arquivo, "%d %d", &iX, &iY);

    // Coordenadas (x, y) do ponto final.
    fscanf(arquivo, "%d %d", &fX, &fY);

    int obras[30][30] = {};
    long cidade[30][30] = {};

    // Locais onde temos obras.
    while(fscanf(arquivo, "%d %d %c", &x, &y, &direcao)!=EOF)
    {
        switch(direcao)
        {
        case 'S': // Sul
            obras[x][y] = 1;
            break;
        case 'O': // Oeste
            obras[x][y] = 2;
            break;
        case 'N': // Norte
            obras[x][y] = 3;
            break;
        case 'L': // Leste
            obras[x][y] = 4;
            break;
        default:
            break;
        }
    }
    cidade[n][m] = 1;

    int i,j;
    for (i=n; i>=1; i--)
    {
        for (j=m; j>=1; j--)
        {
            if (i<n && (obras[i][j] != 3) )
            {
                cidade[i][j] =  cidade[i][j] + cidade[i+1][j];
            }
            if (j<m && (obras[i][j] != 4))
            {
                cidade[i][j] =  cidade[i][j] + cidade[i][j+1];
            }
        }
    }

    for (i=1; i<=3; i++)
    {
        printf("\n");
        for (j=1; j<=3; j++)
        {
            printf("\t%ld ", cidade[i][j]);
        }
    }

    printf("\n\n\tNúmero de caminhos possíveis: %ld\n", cidade[iX][iY]);

    return 0;
}

