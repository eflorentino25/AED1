#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct pilha_c
{
int num      ;
int tempo       ;
struct CHILL_PILL *nxt    ;
};
typedef struct pilha_c CHILL_PILL;

struct fpc
{
int tam ;
struct CHILL_PILL *primeiro;
struct CHILL_PILL*ultimo ;
};
typedef struct fpc  f_p_c;


struct pilha_a
{
int numa;
int tempo ;
struct pilha_a *nxt ;
};
struct fpa
{
struct pilha_a *primeiro;
struct pilha_a *ultimo;
};
typedef struct fpa f_p_a;
//-----Funções-------
//---------------------
//Inicialização de pilha
//---------------------

int inic_Ate(f_p_a *Paux)
{

Paux->primeiro = NULL;
Paux->ultimo = NULL;

}
//---------------------
//Inicialização de pilha
//---------------------

int inic_Cli(f_p_c *Paux)
{
Paux->primeiro = NULL;
Paux->ultimo = NULL;
}
//---------------------
//Preenchimento de pilha
//---------------------

void montalistaC(f_p_c *Paux,int num)
{
int val,i=0;
int arre[25];


for (i=0; i<num ; i++)
{
scanf("d",arre[i]);
}

CHILL_PILL *novo = malloc(sizeof(CHILL_PILL)*1);
CHILL_PILL *pro = malloc(sizeof(CHILL_PILL)*1);
CHILL_PILL *thr = malloc(sizeof(CHILL_PILL)*1);

for (i=0; i<num ; i++)
{

if(i==0)
    {
novo->num       = i + 1 ;
novo->tempo     = arre[i]   ;
Paux->primeiro  = novo  ;
novo->nxt     = pro   ;*1
novo = pro              ;
    }
else
    {
novo->num   = i + 1 ;
novo->tempo = arre[i]   ;
novo->nxt = pro   ;
novo = pro          ;
    }
}
Paux->ultimo = novo;
}
//---------------------
//Programa principal
//---------------------

int main ()
{
int i,j,N,C,E,A,num=0,idx=0;
int res;
int tmp_x[25];
char tempos[113];
f_p_a Atendentes;
f_p_c Clientes;

inic_Ate(&Atendentes);
inic_Cli(&Clientes);



scanf("%d %d",&N,&A); //N == clientes; A==atendentes
montalistaC(&Clientes,N);
montalistaA(&Clientes,&Atendentes);

}



