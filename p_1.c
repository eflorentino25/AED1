#include <stdio.h>
#include <stdlib.h>

typedef struct{

int cpf,rg;
char nome[50];

}dados;

void main(){

int i;
dados *reg;
reg= (dados*)malloc(10*sizeof(dados));

FILE *f;

f=fopen("teste.txt","w+");
for(i=0;i<3;i++){
printf("Entre com o nome %d: ",i);
scanf("%s",reg[i].nome);
printf("Entre com o cpf %d: ",i);
scanf("%d",&reg[i].cpf);
printf("Entre com o rg %d: ",i);
scanf("%d",&reg[i].rg);
fprintf(f,"\nNome %d: %s\nCPF: %d \nRG: %d\n",i,reg[i].nome,reg[i].cpf,reg[i].rg);
}
fclose(f);
return 0;

}
