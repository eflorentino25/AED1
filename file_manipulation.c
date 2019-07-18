#include<stdio.h>
#include<stdlib.h>

int main()
{
char arq[30] = "arquivoTeste.txt";
FILE *fp;
int i;
fp = fopen(arq,'w');

if(fp == NULL)
{
printf("Erro");
}
for (i = 1000; i <= 2000;i++)
{
fprintf(fp,"%d",i);
}
printf("Acabou processo");
}
