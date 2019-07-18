#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------
// TIPOS & STRUCTS
struct ValId{
    int id      ;
    int Valor   ;
            }   ;
typedef struct ValId tipoValId;

struct elemento {
 tipoValId *dados       ;
 //int info               ;
 struct elemento *prox  ;
 struct elemento *ant   ;
                }       ;
typedef struct elemento tipoElemento;


struct estruturaBC{
 tipoElemento *primeiro ;
 tipoElemento *ultimo   ;
 int tamanhoLista       ;
                    }   ;
typedef struct estruturaBC tipoBC;

//-----------------------------------------------------------------

void inicializaLista (tipoBC *listaAux)
{
 listaAux->primeiro = NULL;
 listaAux->ultimo = NULL;
 listaAux->tamanhoLista=0;
}

//-----------------------------------------------------------------
void insereElementoFinal (tipoBC *listaAux)
{ // Alocando espaço para o elemento
 tipoElemento *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
 // fazendo leitura dos dados para info
 printf("Insira um número para adicionar a lista");
 scanf("%d", &novo->dados->Valor);
 if (listaAux->tamanhoLista == 0){
 novo->prox = NULL;
 novo->ant = NULL;
 listaAux->primeiro=novo;
 listaAux->ultimo=novo;
 }else{
 novo->prox = NULL;
 novo->ant = listaAux->ultimo;
 listaAux->ultimo->prox = novo;
 listaAux->ultimo=novo; }
listaAux->tamanhoLista++;
}
//-----------------------------------------------------------------

void insereElementoInicio (tipoBC *listaAux)
{ // Alocando espaço para o elemento
 tipoElemento *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
 // fazendo leitura dos dados para info
 printf("Insira um número para adicionar a lista");
 scanf("%d", &novo->dados->Valor);
 if (listaAux->tamanhoLista == 0)
    {
    novo->prox = NULL;
    novo->ant  = NULL;
    listaAux->primeiro = novo;
    listaAux->ultimo   = novo;
    }
 else
    {
    novo->prox = listaAux->primeiro ;
    novo->ant  = NULL;
    listaAux->primeiro = novo ;
    listaAux->tamanhoLista++;
    }
}
//-----------------------------------------------------------------
void printarLista(tipoBC *listaAux)
{
    tipoElemento *printElem;
    printElem    =   malloc(sizeof(tipoElemento));
    int  i, b , lv_valor;

    b = listaAux->tamanhoLista;

    for (i = 0 ; i <= b ; i++ )
    {
        if (i == 0)
        {
        printElem =  listaAux->primeiro->prox;
        lv_valor  =  listaAux->primeiro->dados->Valor;
        printf("%d\n", lv_valor);
        }
        else
        {
        lv_valor  = printElem->dados->Valor;
        printf("%d\n", lv_valor);
        printElem = printElem->prox;
        }
    }
}

//-----------------------------------------------------------------
void  removeElemento(tipoBC *listaAux)
{

}
//-----------------------------------------------------------------
int main()
{

tipoBC wa_dupla;
inicializaLista(&wa_dupla);
insereElementoFinal(&wa_dupla);
insereElementoFinal(&wa_dupla);
insereElementoFinal(&wa_dupla);
insereElementoFinal(&wa_dupla);
insereElementoInicio(&wa_dupla);
insereElementoInicio(&wa_dupla);
removeElemento(&wa_dupla);
printarLista(&wa_dupla);



}








