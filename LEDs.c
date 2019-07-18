#include <stdlib.h>
#include <stdio.h>


//---------------------------
struct elemento
{
 int info;
 struct elemento *prox;
};
typedef struct elemento tipoElemento;

//---------------------------
struct listaDE
{
 tipoElemento *primeiro;
 tipoElemento *ultimo;
 int tamanhoLista;
};
typedef struct listaDE tipoLDE;

//---------------------------

void inicializaLista (tipoLDE *listaAux){
 listaAux->primeiro = NULL;
 listaAux->ultimo = NULL;
 listaAux->tamanhoLista=0;
}
//---------------------------

void insereElementoFinal (tipoLDE *listaAux, int info)
{ // Alocando espaço para o elemento
 tipoElemento *novoElem = malloc(sizeof(tipoElemento));
 // Atribuindo os dados de info
 novoElem ->info=info;
if (listaAux->tamanhoLista == 0){
 novoElem ->prox = NULL;
 listaAux->primeiro= novoElem;
 listaAux->ultimo= novoElem;
 //printf("%d",listaAux->ultimo->info);
 } else {
 novoElem ->prox = NULL;
 listaAux->ultimo->prox = novoElem;
 listaAux->ultimo= novoElem;
 } // fim do if
 listaAux->tamanhoLista++; }

 //---------------------------

void insereElementoInicio(tipoLDE *listaAux, int info)
{// Alocando espaço para elemento.
    tipoElemento *novoElem = malloc(sizeof(tipoElemento));
 //Atribuindo os dados de info
    novoElem ->info=info;
 if (listaAux->tamanhoLista == 0)
    {
    novoElem ->prox = NULL;
    listaAux->primeiro= novoElem;
    listaAux->ultimo= novoElem;
    }
    else
    {
    novoElem->prox = listaAux->primeiro;
    listaAux->ultimo->prox = NULL;
    listaAux->primeiro= novoElem;
    //printf("%d",listaAux->primeiro->info);
    } // fim do if
    listaAux->tamanhoLista++;
}
//-------------
void    printTudo(tipoLDE *listaAux)
{
    int i,lv_pos,lv_valor;
    tipoElemento *printElem;
    printElem    =   malloc(sizeof(tipoElemento));
    //nextElem     =   malloc(sizeof(tipoElemento));
    for (i = 0; i <= listaAux->tamanhoLista;i ++ )
    {
    if (i == 0)
        {
     printElem =  listaAux->primeiro->prox;
     lv_valor       =  listaAux->primeiro->info;
     printf("%d\n", lv_valor);
        }
     else
        {
     lv_valor = printElem->info;
     printf("%d\n", lv_valor);
     printElem = printElem->prox;

        }
    }
}
//-------------
tipoLDE procuraElem(tipoLDE *listaAux,int lv_busca )
{
//    int i,b,c,lv_valor;
//    tipoElemento *proxElem;
//    proxElem = malloc(sizeof(tipoElemento));
//    for(i = 0; i <= listaAux->tamanhoLista; i++)
 //       {
  //      if (i == 0)
    // v       {
  //      proxElem =  listaAux->primeiro->prox;
   //     lv_valor       =  listaAux->primeiro->info;
     //       if (lv_valor ==  lv_busca)return ( listaAux );
    //        }
 //       else
//            {
// //       lv_valor = proxElem->info;
 //       if (lv_valor ==  lv_busca)return ( proxElem );
//        proxElem = proxElem->prox;
//
 //           }
  //      }
}

//------------



int main()
{
//-------

int i,c ,b ;
tipoLDE lista02, lista_local;

//-------


inicializaLista(&lista02);
insereElementoFinal(&lista02,998);
insereElementoInicio(&lista02,1232);
insereElementoInicio(&lista02,1235);
insereElementoInicio(&lista02,1234);
printTudo(&lista02);
lista_local = procuraElem(&lista02,1235);

//printf("%d", lista02.primeiro->info);

}


