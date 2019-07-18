#include<stdio.h>
#include<stdlib.h>

struct pilha
{
char conteudo[50];
int topo;
};
typedef struct pilha P;

void  push( P *pilha , char c)
{
//printf("%c", c);
pilha->topo++;
pilha->conteudo[pilha->topo] = c;
printf("%c",pilha->conteudo[pilha->topo]);

}

void printp( P *pilha )
{
int i;
for(i = 0; i <= pilha->topo ; i++)
{
printf("\n%c , %d",pilha->conteudo[i],i);
}
printf("\n%c",pilha->conteudo);
}

int main ()
{
P pil;
char X,Z,Y;
int i;
pil.topo = -1;
for (i = 0; i <  50; i++)
{
pil.conteudo[i] = 'O';
}
printf("%s\n",pil.conteudo);
printf("%d\n",pil.topo);
//
//for (i = 0 ; i <  3; i++)
//{
//scanf("%c", &X);
//push(&pil , X);
//}
scanf("%c", &X);
push(&pil , X);
scanf("%c", &Y);
push(&pil , Y);
scanf("%c", &Z);
push(&pil , Z);
push(&pil , '\0' );
printp(&pil);
}
