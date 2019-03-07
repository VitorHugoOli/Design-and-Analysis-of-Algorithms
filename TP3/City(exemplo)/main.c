#include "Cidade.h"
#include <time.h>

int menu();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    menu();
    return 0;
}

int menu()
{
    char *nome;
    nome = (char*)malloc(sizeof(20));
    int opcao;
    time_t start, end;



    do
    {
        printf("\n\t|---------------- TAREFA B ----------------|");
        printf("\n\t|1) Carregar um arquivo                    |");
        printf("\n\t|2) Imprimir caminhos possíveis            |");
        printf("\n\t|------------------------------------------|\n");
        printf("\n\tSelecione uma opção: ");

        scanf("%d", &opcao);

        if (opcao>=1 && opcao<4)
        {
            system("clear");
            switch(opcao)
            {
            case 1:
                printf("\n");
                printf("\tDigite o nome do arquivo: ");
                scanf("%s", nome);
                setbuf(stdin, NULL);
                break;

            case 2:
                    if(DEBUG)
                    {
                        time(&start);
                    }
                    caminhosPossiveis(nome);

                    if(DEBUG)
                    {
                        time(&end);
                        printf("\n\t[DEBUG]:\n\n\tTempo total: %lf\n\n", difftime(end, start));
                    }
                break;

            case 3:
                break;
            }
            printf("\n\tPressione ENTER para continuar...");
            setbuf(stdin, NULL);
            getchar();
        }
        system("clear");
    }
    while (opcao>=1 && opcao<8);
    return 0;
}
