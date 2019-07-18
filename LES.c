#include <stdio.h>
#include <stdlib.h>
#define  N  150

struct LES{               // ABAP "TYPES:"
    int ultimo;
    int Tamanho;
    int lista[N];
          };

 typedef struct LES ty_les;

 ty_les wa_les;


void inicializaLista(LES *listaAux)
{
// Zera a lista
listaAux->tamanhoLista =0;
//Alg.e Estruturas de Dados I – Prof. Valério Rosset 15
//• Chamada
listaAux->tamanhoLista =0;
for (i=0; i<N; i++)
    {
    listaAux->lista[i]=0;
    // Inicializa o último
    listaAux->ultimo = 0;
    }
}


void insereElemento (LES *listaAux)
{
// Atualiza a lista
listaAux->tamanhoLista++;
//Alg.e Estruturas de Dados I – Prof. Valério Rosset 16
listaAux->tamanhoLista++;
// Insere elemento ao final da lista
scanf("%d", &listaAux->lista[listaAux->tamanhoLista-1]);
// Atualiza o último
listaAux->ultimo = listaAux->tamanhoLista-1;
}

int main()
{

    inicializaLista(&wa_les);

    for(i = 0; i <= 149 ; i++)
        {
        insereElemento(&wa_les);
        }
}
