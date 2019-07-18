#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "fatorial.h"

void main()
{
     FILE *arq1, *arq2;
    int value , i ,read;
    char svalue[10];
char S[100];
    arq1 = fopen("arquivo_dois.txt","a");

    arq2 = fopen("texto.txt","a+");

    if ((arq1==NULL) || (arq2==NULL))
        {
        printf("Erro na criação do arquivo");
        getch();
        return(0);
        }
    else
        {
//                for (i =1 ; i<=1000; i++)
//                {
//                fprintf( arq1,"%d\n", i );
//                }
//        fputs("OIE, Meu nome é Eduardo",arq1);
                for (i =1 ; i<=1000; i++)
                {
                read = fgetc(arq1);
//        fgets(S,100,arq1);
        printf("%d",read);
                }
        fclose(arq1);
        fputs("E escrever arquivos é legal \n",arq2);
        value = Fatorial(10);
        itoa(value,svalue,10);
        fputs(svalue,arq2);
        fclose(arq2);
        }
}
