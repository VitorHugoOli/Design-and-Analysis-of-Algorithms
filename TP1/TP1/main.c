
#include "arq.h"
#include "Hash.h"

#define QtdExe 5
#define LimiteTeste 28


int main()
{
    menu();
    system("pause");
    return 0;
}

void menu()
{
    setlocale(LC_ALL, "Portuguese");
    int *vet,i;
    THash *Hash;
    int TamVet[LimiteTeste] = {250,500,750,1000,1500,2000,2500,3000,4000,5000,6000,7000,8000,9000,10000,10500,11000,15000,20000,30000,40000,50000,60000,70000,80000,90000,100000,125000};
    int X,j;
    float TempoEx =0.0,TempoExAll=0.0;
    int opcao=-1;

    arquivo = fopen("Resultados.txt","w");

    GeraValores(&X,1);//fornece um valor aleatorio para X

    fprintf(arquivo,"Valor de X : %d\n",X);


    while (opcao != 0)
    {
        printf("+---------------------------------------------------------------------------+\n");
        printf("|Bem vindo ao teste comparativo entre método de ordenção. Digite uma opção: |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|1 - Iniciar testes com %d quantidades diferentes de entrada.               |\n",LimiteTeste);
        printf("|0 - Sair                                                                   |\n");
        printf("+---------------------------------------------------------------------------+\n");
        scanf("%d",&opcao);


        switch (opcao)
        {

            case 1:
            for(j=0; j<LimiteTeste; j++)

            {
                printf("Processando N = %d\n",TamVet[j]);
                fprintf(arquivo,"\n------------------------------Método Select Sort Tamanho do vetor aleatorio: %d----------------------------------------------\n",TamVet[j]);
                for (i=0; i<QtdExe; i++)
                {

                    Hash=(THash*)malloc(sizeof(THash)*TamVet[j]);
                    vet = (int*)malloc(sizeof(int)*TamVet[j]);
                    InicializaHash(Hash,TamVet[j]);
                    GeraValores(vet,TamVet[j]);
                    GeraValoresHash(Hash,TamVet[j],vet);
                    TempoEx += SelectSort(vet,TamVet[j]) + Busca(vet,TamVet[j],X)+ Busca2(vet,TamVet[j],X) + Busca3(Hash,TamVet[j],X);
                    free(vet);
                    free(Hash);
                    fprintf(arquivo,"Tempo total: %lf\n\n",TempoEx);
                    TempoExAll+=TempoEx;
                    TempoEx=0.0;
                }
                fprintf(arquivo,"TEMPO MÉDIO TOTAL: %lf\n\n",TempoExAll/QtdExe);
                TempoExAll = 0.0;
                fprintf(arquivo,"\n------------------------------Método Quick Sort Tamanho do vetor aleatorio: %d----------------------------------------------\n",TamVet[j]);
                for (i=0; i<QtdExe; i++)
                {
                    vet = (int*)malloc(sizeof(int)* TamVet[j]);
                    GeraValores(vet,TamVet[j]);
                    TempoEx += QuickSort(vet,TamVet[j]) + Busca(vet,TamVet[j],X) + Busca2(vet,TamVet[j],X);
                    fprintf(arquivo,"Tempo total: %lf\n\n",TempoEx);
                    TempoExAll+=TempoEx;
                    TempoEx=0.0;
                }
                fprintf(arquivo,"TEMPO MÉDIO TOTAL: %lf\n\n",TempoExAll/QtdExe);

            }
            printf("Arquivo Criado com sucesso!!\n");
            break;

            default:
                if (opcao != 0){
                    LimpaTela;
                    printf("Opção inválida! tente novamente\n");
                }

        }
    }
    fclose(arquivo);
    printf("Obrigado por utilizar-me! \n");

    return;
}
