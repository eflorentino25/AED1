#include<stdio.h>
#include<stdlib.h>
#define N 10
struct elem
{
    int info    ;
    tyElem prox ;
    tyElem ant  ;
    };
typedef struct elem tyElem

struct LCE
{
   tyElem primeiro  ;
   tyElem ultimo    ;
   int Lista[N]     ;
};

typedef struct  LCD tyLista

//--------------------
void inicializaLista (tipoListaEE *listaAux)
{ // Inicializa elementos da lista
 listaAux->tamanhoLista = 0;
 listaAux->primeiro = -1;
 listaAux->ultimo = -1;
    for (i=0; i<N; i++)       {
    listaAux->elemento[i].valor = 0;
    listaAux->elemento[i].prox = -1;
    listaAux-> posLivre[i]=1;
                           }
 }
//--------------------


int main()

{




}







