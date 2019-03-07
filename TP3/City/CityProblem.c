//
// Created by vho20 on 17/11/2018.
//
#include "CityProblem.h"


int LerArq(Quadriculado *city){
    setlocale(LC_ALL, "Portuguese");
    char nomeArq[30];
    int x,y;
    int i,j;
    char p;
    FILE *arq;
    printf("Digite o nome do arquivo desejado:\n");
    scanf("%s",nomeArq);
    while((arq=fopen(nomeArq,"r"))==NULL || strcmp(nomeArq,"e")==0) {
        printf("Algo de errado não esta muito certo!!!\n");
        printf("Tente novamente\n");
        printf("Digite o nome do arquivo desejado:\n");
        scanf("%s",nomeArq);
    }
    fscanf(arq,"%d %d",&city->x,&city->y);
    city->ruas = (char**)malloc((city->x+1) * sizeof(char*));
    for(i=1;i<=city->x;i++){
        city->ruas[i] = (char*)malloc((city->y+1)* sizeof(char));
        for(j=1;j<=city->y;j++){
            city->ruas[i][j]='X';
        }
    }

    fscanf(arq,"%d %d",&city->xi,&city->yi);
    fscanf(arq,"%d %d",&city->xf,&city->yf);

    while (fscanf(arq,"%d %d %c",&x,&y,&p)!=EOF){
        city->ruas[x][y]=p;
    }
}
void ShowCity(Quadriculado city){
    int i,j;
    for(i=1;i<=city.x;i++){
        for(j=1;j<=city.y;j++){
            printf("%c ",city.ruas[i][j]);
        }
        printf("\n");
    }
}
void CityProblem(Quadriculado *city, int debug){
    LARGE_INTEGER tf, ti, freq;
    float TempoTotal;

    QueryPerformanceCounter(&ti);


    setlocale(LC_ALL, "Portuguese");
    double count[city->x+1][city->y+1];
    char clone[city->x+1][city->y+1];
    int i,j;

    for(i=1;i<=city->x;i++){
        for(j=1;j<=city->y;j++){
            count[i][j]=0;
        }
    }

    count[city->xf][city->yf]=1;
    for(i=city->xf;i>=city->xi;i--){
        for(j=city->yf;j>=city->yi;j--){
            if(i<city->x && city->ruas[i][j]!='N')
                count[i][j]=count[i][j]+count[i+1][j];
            if(j<city->y && city->ruas[i][j]!='L')
                count[i][j]=count[i][j]+count[i][j+1];
        }
    }

    printf("§ A solução é:\n");
    for(i=1;i<=city->x;i++){
        for(j=1;j<=city->y;j++){
            printf("%.0lf ",count[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("§ Foram achados %.0lf caminhos vivaveis\n\n",count[city->xi][city->yi]);

    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    TempoTotal = (float) (tf.QuadPart - ti.QuadPart) / freq.QuadPart;
    printf("\nO Tempo parcial para rodar um problema de tamanho %dx%d, sem um caminho possivel foi : %lf segundos\n\n",city->x,city->y,TempoTotal);

    printf("§ Um dos caminhos possiveis a ser feitos é:\n");

    for(i=1;i<=city->x;i++){
        for(j=1;j<=city->y;j++){
            clone[i][j]='O';
        }
    }

    Caminho(*city,count,clone,city->xf,city->yf);
    clone[city->xf][city->yf]='X';

    for(i=1;i<=city->x;i++){
        for(j=1;j<=city->y;j++){
            printf("%c ",clone[i][j]);
        }
        printf("\n");
    }

    QueryPerformanceCounter(&tf);
    QueryPerformanceFrequency(&freq);
    TempoTotal = (float) (tf.QuadPart - ti.QuadPart) / freq.QuadPart;
    if(debug==1)
        printf("\nO Tempo total gasto para rodar um problema de tamanho %dx%d foi : %lf segundos\n",city->x,city->y,TempoTotal);
}
int Caminho(Quadriculado city,double count[][city.y+1],char clone[][city.y+1],int i,int j){
    setlocale(LC_ALL, "Portuguese");
    if(i<1 || j<1) return 0;
    if(i==city.xi && j==city.yi) {
        clone[i][j] = '-';
        return 1;
    }
    if(count[i][j]!=0){
        if(Caminho(city,count,clone,i-1,j) && city.ruas[i][j]!='N') {
            clone[i][j] = '-';
            return 1;
        }
        else if(Caminho(city,count,clone,i,j-1) && city.ruas[i][j]!='L') {
            clone[i][j] = '-';
            return 1;
        }
        else return 0;
    }
    return 0;
}
void Obra(Quadriculado *city){
    setlocale(LC_ALL, "Portuguese");
    int i,j;
    char c;
    printf("Digite os pontos e a direção(N|L) da nova obra:\n");
    scanf("%d %d %c",&i,&j,&c);
    if((c=='N'||c=='L') && city->x>=i && city->y>=j)
        city->ruas[i][j]=c;
    else
        printf("Não foi possivel adicionar a cidade\n");
}
void Main(int debug){
    setlocale(LC_ALL, "Portuguese");
    Quadriculado city;
    int opc;
    printf("---Seja Bem vindo ao problema da cidades---\n");
    printf("1 - Entrar com arquivo;\n");
    printf("---Bloqueado até a leitura do arquivo---\n");
    printf("2 - Resolver problema;\n");
    printf("3 - Denunciar nova Obra;\n");
    printf("4 - Visulaizar a cidade;\n");
    printf("5 - Sair do progama;\n");
    printf("----------------------------------------\n");
    printf("Digite alguma opção desejada:\n");
    scanf("%d",&opc);
    while (opc!=1) {
        printf("Opção Bloqueada!!!!\n");
        printf("Digite outra valida:\n");
        scanf("%d",&opc);
    }
    while(opc!=5){
        if(opc==1) {
            LerArq(&city);
        }
        if(opc==2){
            CityProblem(&city,debug);
        }
        if(opc==3){
            Obra(&city);
        }
        if (opc==4) {
            ShowCity(city);
        }
        system("Pause");
        system("CLS");
        printf("1 - Entrar com uma nova ciadade(novo arquivo);\n");
        printf("2 - Resolver problema;\n");
        printf("3 - Denunciar nova Obra;\n");
        printf("4 - Visulaizar a cidade;\n");
        printf("5 - Sair do progama;\n");
        printf("Digite alguma opção desejada:\n");
        scanf("%d",&opc);
    }
}


