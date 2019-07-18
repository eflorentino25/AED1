#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


struct    caixas
{
int id_cx     ;
int tempo   ;
int  id_c[1024] ;
struct  ty_caixas *nxt;
};
typedef struct caixas ty_caixas;

struct f_caixas
{
struct  ty_caixas *fst;
struct  ty_caixas *lst;
};
typedef struct f_caixas ty_fcaixas;

void initCx(ty_fcaixas *Fila_Cx)
{
Fila_Cx->fst = NULL;
Fila_Cx->lst = NULL;
}
void startcx(ty_fcaixas *F_cx, int id)
{
int i,j;
ty_caixas *aux = (ty_caixas*) malloc( sizeof(ty_caixas));
ty_caixas *aux2 = (ty_caixas*) malloc( sizeof(ty_caixas));

if (id == 1)
{
aux->id_cx = id;
aux->tempo = 0;
aux->nxt = NULL;
for (j=0;j<=1024;j++)
{
aux->id_c[j] = 0;
}

F_cx->fst = aux;
F_cx->lst =aux;

}
else
{
aux2 = F_cx->lst;
aux2->nxt = aux;
aux->id_cx = id;
aux->tempo = 0;
aux->nxt = NULL;
F_cx->lst = aux;
for (j=0;j<=1024;j++)
{
aux->id_c[j] = 0;
}
}
}
void printar(ty_fcaixas *F_cx)
{
int i =0;
ty_caixas *aux = (ty_caixas*) malloc( sizeof(ty_caixas)*1);
aux = F_cx->fst;
printf("INICIO FUNC PRINT\n", aux->id_cx,aux->tempo);
while(aux->nxt != NULL)
{
printf("\n%d : ", aux->id_cx );
while(aux->id_c[i]!=0)
{
printf("%d",aux->id_c[i]);
i++;
}
i =0;
aux = aux->nxt;
}
}

void cxcx(ty_fcaixas *F_cx, int tempo, int id_c)
{
int i;
ty_caixas *looper   = (ty_caixas*) malloc( sizeof(ty_caixas)*1);
ty_caixas *smaller = (ty_caixas*) malloc( sizeof(ty_caixas)*1);
smaller = F_cx->fst;
looper   = F_cx->fst;
while (looper->nxt != NULL)
{
if(smaller->tempo == 0)
{
smaller->tempo = smaller->tempo + tempo;
for (i=0;i<=1024;i++)
{
if (smaller->id_c[i] == 0)
{
smaller->id_c[i]    = id_c ;
i = 2000 ;
}
}
//printf("encontrou zerado add:%d\n",smaller->tempo);
return;
}
else
{
if(smaller->tempo > looper->tempo)
{
smaller = looper;
looper = looper->nxt;
}
else
{
looper = looper->nxt;
//printf("menor tempo por enquanto ->%d\n",smaller->tempo);
//printf("tempo proximo ->%d\n",looper->tempo);
}
}
}
//looper = looper->nxt;
if(smaller->tempo > looper->tempo)
{
smaller = looper;
smaller->tempo = smaller->tempo  + tempo;
//printf("menor tempo final%d\n",smaller->tempo);
for (i=0;i<=1024;i++)
{
if (smaller->id_c[i] == 0)
{
smaller->id_c[i]    = id_c ;
i = 2000 ;
}
}

}
else
{
smaller->tempo = smaller->tempo  + tempo;
//printf("menor tempo final%d\n",smaller->tempo);
for (i=0; i<=1024;i++)
{
if (smaller->id_c[i] == 0)
{
smaller->id_c[i]    = id_c ;
i = 2000 ;
}
}

}
}

int main()
{
int Qt_C, Qt_Cx, i , tempo ;
ty_fcaixas f_caixas; //Fila de caixas.
initCx(&f_caixas);
scanf("%d %d", &Qt_C, &Qt_Cx);

for (i=1 ; i<=Qt_Cx ; i++ )
{
startcx(&f_caixas,i);
}

for (i=1 ; i<=Qt_C ; i++ )
{
scanf("%d",&tempo);
cxcx(&f_caixas, tempo,i);
}
printar(&f_caixas);
}
