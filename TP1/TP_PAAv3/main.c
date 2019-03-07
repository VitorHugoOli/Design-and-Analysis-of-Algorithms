#include "arq.h"
#define LimiteTeste 28



int main()
{
    setlocale(LC_ALL, "Portuguese");
    arquivo = fopen("Resultados.txt","w");
    menuPrincipal();
    system("pause");
    return 0;
}

void menuPrincipal()
{

    int opcao=-1;

    while (opcao != 0)
    {
        printf("+---------------------------------------------------------------------------+\n");
        printf("|Bem vindo ao teste comparativo entre m?todo de ordena??o. Digite uma op??o:|\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|1 - Iniciar testes com %d quantidades diferentes de entrada.               |\n",LimiteTeste);
        printf("|2 - Iniciar testes com entrada manual.                                     |\n");
        printf("|0 - Sair                                                                   |\n");
        printf("+---------------------------------------------------------------------------+\n");
        scanf("%d",&opcao);

        switch (opcao)
        {
            case 1:
                menuCase1();
                break;

            case 2:
                menuCase2();
                break;

            default:
                if (opcao != 0){
                    LimpaTela;
                    printf("Op??o inv?lida! tente novamente\n");
                }
        }
    }
    fclose(arquivo);
    printf("Que a for?a Hash esteja com voc?, Fim !!!\n");

    return;
}
