#include <stdio.h>

int main() {
    char matriz[20][80];
    int i,j;
    for (i=0;i<20;i++){
        for (j= 0; j < 80;j++) {
            if(i==0)
                matriz[i][j]='-' ;
            else if(j==0 &&  i!=19)
                matriz[i][j]='|';
            else if(j==79 && i!=19)
                matriz[i][j]='|';
            else if(i==19)
                matriz[i][j]='-';
            else
                matriz[i][j]=' ';
        }
    }
    for (i=0;i<20;i++){
        for (j= 0; j < 80;j++) {
            if(i==0)
                matriz[i][j]='-' ;
            else if(j==0 &&  i!=19)
                matriz[i][j]='|';
            else if(j==79 && i!=19)
                matriz[i][j]='|';
            else if(i==19)
                matriz[i][j]='-';
            else
                matriz[i][j]=' ';
        }
    }
    for (i=0;i<20;i++){
        for (j= 0; j < 80;j++) {
            printf("%c",matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}