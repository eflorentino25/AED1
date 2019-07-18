#include<stdio.h>
#include<stdlib.h>

struct ValId{
    int id              ;
    int valor           ;
    int chave           ;
    int chaveAnterior   ;
            }   ;
typedef struct ValId tipoValId;

struct elemento {
 tipoValId *dados           ;
 //int info                 ;
 struct elemento *prox      ;
 //struct elemento *ant       ;
                }           ;
typedef struct elemento tipoElemento;


struct estruturaBC{
 tipoElemento *primeiro ;
 tipoElemento *ultimo   ;
 int tamanhoLista       ;
                    }   ;
typedef struct estruturaBC tipoBC;


//---------------------------

void inicializaLista (tipoBC *listaAux){
 listaAux->primeiro = NULL;
 listaAux->ultimo = NULL;
 listaAux->tamanhoLista=0;
}
//---------------------------

void insereElementoInicio(tipoBC *listaAux)
{ // Alocando espaço para o elemento
 tipoElemento *novoElem = malloc(sizeof(tipoElemento));
 // Atribuindo os dados de id e valor
 int id , valor ,chave , chaveAnterior;
 scanf("%d %d", &id, &valor);
 novoElem->dados->id     = id   ;
 novoElem->dados->valor  = valor;

 //preenchendo lugar na lista.
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


 void atualizaElemento(tipoBC *listaAux)
 {
     int id, valor ;
     scanf("%d %d", &id, &valor);


 }

//---------------------------
void removeElemento(tipoBC *listaAux)
{
    int id, i;

    scanf("%d", &id);

    tipoElemento *Aux  = (tipoElemento*) malloc(sizeof(tipoElemento));
    tipoElemento *Aux2 = (tipoElemento*) malloc(sizeof(tipoElemento));
    tipoElemento *Aux3 = (tipoElemento*) malloc(sizeof(tipoElemento));


    Aux = listaAux->primeiro;

    for (i = 0; i <= listaAux->tamanhoLista && listaAux->ultimo != NULL; i++ )
    {
        if  (Aux->dados->id == id )
        {
        Aux2 = Aux->prox;
        free(void Aux);
        recalculaLista(Aux2,Aux3,listaAux->tamanhoLista);
        Aux3->prox = Aux2;
        }

        else
        {
        Aux3 = Aux;
        Aux  = Aux->prox;
        }
    }
}

//---------------------------
void recalculaLista(tipoElemento Elem, tipoElemento elemAnt, int Tamanho)
{
    int id, valor, resultadoAnt,hashNova, hashAnt,i;

    for(i = 0; i <= Tamanho & Elem.prox != NULL ; i++)
    {
    valor       = Elem->dados->valor;
    id          = Elem->dados->id;
    hashAnt     = elemAnt->dados->chave
    hashNova    = ((valor%id) + hashAnt);
    Elem->dados->chave = hashNova;
    Elem->dados->chaveAnterior = elemAnt->dados->chave;
    elemAnt = Elem;
    Elem = Elem->prox;
    }









}



//---------------------------

void transfereElemento(tipoBC *listaAux)
{
scanf("%d %d %d", &IDpaga, &valor, &IDrecebe);

}

//---------------------------

void  imprimeLista(tipoBC *listaAux)
{

}
//---------------------------

 int main()
 {
    int op;
    tipoBC wa_lista ;

//Inicia as funções

    printf("insira qual número de função deseja realizar: \n");
    printf("1 - inserir; 2 - atualizar; 3 - remover; 4 - transferir; 5- imprimir ;-1 Sair \n");
    scanf("%d", &op);
    while(op!=-1)

    switch (op) {
    case (1):
            insereElementoInicio(&wa_lista);
    case (2):
            atualizaElemento(&wa_lista);
    case (3):
            removeElemento(&wa_lista);
    case (4):
            transfereElemento(&wa_lista);
    case (5):
            imprimeLista(&wa_lista);
    case (-1):
            return(0);
                }
    scanf("%d", &op);
 }


