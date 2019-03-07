//
// Created by vho20 on 25/10/2018.
//
#include "CacaPalavras.h"
#include "string.h"


void menuCruzadas(int modoanalise) {
    FILE *file;
    Matriz letras;
    char Palavra[30];
    int opc;
    LerArq(&file);
    system("CLS");
    GeraMatriz(file, &letras);
    printf("Deseja verificar a matriz lida ?\n"
           "1- Sim 2- Não\n");
    scanf("%d",&opc);
    if(opc==1)
        mostraMatriz(letras);
    system("PAUSE");
    system("CLS");
    printf("Digite a palavra a ser pesquisada: ");
    scanf("%s", Palavra);
    system("CLS");
    backtracking(&letras, Palavra,modoanalise);
    mostraMatrizFinal(letras);
    system("PAUSE");
}

void LerArq(FILE **file) {
    char nomearquivo[30];
    printf("Digite o nome do arquivo com o caça palavras a ser inserido: ");

    scanf("%s", &nomearquivo);
    int coluna, linha;

    *file = fopen(nomearquivo, "r");
    while (*file == NULL) {
        printf("Erro, arquivo invalido\n");
        printf("Tente novamente\n");
        scanf("%s", nomearquivo);
        *file = fopen(nomearquivo, "r");
    }
}

void GeraMatriz(FILE *file, Matriz *letras) {
    int coluna, linha;

    int i, j;
    char c;
    int flag;


    fscanf(file, "%d %d", &letras->linha, &letras->coluna);
    letras->palavraCruzadas = (char **) malloc(letras->linha * sizeof(char *));
    letras->final = (char **) malloc(letras->linha * sizeof(char *));
    for (i = 0; i < letras->linha; i++) {
        letras->palavraCruzadas[i] = (char *) malloc(letras->coluna * sizeof(char));
        letras->final[i] = (char *) malloc(letras->coluna * sizeof(char));
        for (j = 0; j < letras->coluna; j++) {
            flag = 1;
            fscanf(file, "%c", &c);
            if (c > 67 && c < 122) {
                letras->palavraCruzadas[i][j] = c;
                flag = 0;
            }
            if (flag == 1) j--;
        }
    }
}


int backtracking(Matriz *letras, char *palavra,int analise) {
    int i, j;
    int contrecusi=0;
    int ocorrencia=0;
    for (i = 0; i < letras->linha; i++) {
        for (j = 0; j < letras->coluna; j++) {
            if (letras->palavraCruzadas[i][j] == palavra[0])
                if (j > 0) {// Presupõem que a leitura veio da esquerda para direita e o proximo movimento e para baixo;
                    contrecusi++;
                    backtrackingOp(letras, palavra, i, j, 'b',&contrecusi,&ocorrencia);
                } else {// Presupõem que acabou de começar e o proximo movimento e pode ser baixo ou direita;
                    contrecusi=contrecusi+2;
                    backtrackingOp(letras, palavra, i, j, 'b',&contrecusi,&ocorrencia);
                    backtrackingOp(letras, palavra, i, j, 'd',&contrecusi,&ocorrencia);
                }
        }
    }
    printf("Foram achadas %d ocorrencias\n",ocorrencia);
    if(analise)
     printf("Foram feitas %d chamadas recusivas\n",contrecusi);
}

int backtrackingOp(Matriz *letras, char *palavra, int i, int j, char direcao,int *contrecusi,int *ocorrencia) {
    if (letras->palavraCruzadas[i][j] == palavra[0]) letras->final[i][j] = '*';
    if(letras->palavraCruzadas[i][j] != palavra[0]) return 0;
    palavra++; //pula para proxima letra;
    if (direcao == 'b') {
        i++;//pula proxima letra da linha
        if (letras->palavraCruzadas[i][j] == palavra[0] && palavra[1] == '\0') {// compara se há ultima posiçao da palavra foi achada na matriz e já retorna a recussividade
            (*ocorrencia)++;
            letras->final[i][j] = '*';//preenche a matriz final nas posicoes onde a ocorencia das letras da palavra
            return 1;
        } else {
            if (j < letras->coluna) {
                (*contrecusi)++;
                backtrackingOp(letras, palavra, i, j, 'd',contrecusi,ocorrencia);//chama a leitura para direita
            }
            if (j > 0) {
                (*contrecusi)++;
                backtrackingOp(letras, palavra, i, j, 'e',contrecusi,ocorrencia);//chama a leitura para esquerda
            }
        }
    } else if (direcao == 'e' || direcao == 'd') {
        if (direcao == 'e') j--;//volta uma letra da coluna caso a leitura for para esquerda
        else j++;//pula proxima letra da coluna caso a leitura for para direita
        if (letras->palavraCruzadas[i][j] == palavra[0] && palavra[1] == '\0') {// compara se há ultima posiçao da palavra foi achada na matriz e já retorna a recussividade
            (*ocorrencia)++;
            letras->final[i][j] = '*';//preenche a matriz final nas posicoes onde a ocorencia das letras da palavra
            return 1;
        } else {
            if (i < letras->linha) {
                (*contrecusi)++;
                backtrackingOp(letras, palavra, i, j, 'b', contrecusi,ocorrencia);//chama a leitura para baixo
            }
        }
    }
}

void mostraMatriz(Matriz letras) {
    int i, j;
    for (i = 0; i < letras.linha; i++) {
        printf("\n");
        for (j = 0; j < letras.coluna; j++) {
            printf("%c ", letras.palavraCruzadas[i][j]);
        }
    }
    printf("\n\n");
}

void mostraMatrizFinal(Matriz letras) {
    int i, j;
    for (i = 0; i < letras.linha; i++) {
        printf("\n");
        for (j = 0; j < letras.coluna; j++) {
            if (letras.final[i][j] == '*')
                printf("%c ", letras.palavraCruzadas[i][j]);
            else
                printf("* ");
        }
    }
    printf("\n");
}




