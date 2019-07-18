#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 40


typedef struct Pessoa
{
   char nome[max];
   int idPessoa;
   struct Pessoa *prox;

}Pessoa;

typedef struct Fila
{
    struct Pessoa *inicio;
    struct Pessoa *fim;
    int tam;
}Fila;

void iniciafila (Fila *ptr)
{
    ptr->inicio = NULL;
    ptr->fim = NULL;
}


void insereFila (Fila *ptr, char nom[], int id)
{
    int i = 0 ;
//     printf("%d identi\n",id);
//     printf("%s",nom);
     Pessoa *novo;
     novo = (Pessoa *) malloc(sizeof(Pessoa));

    if (ptr->inicio == NULL && ptr->fim ==   NULL)
    {
                printf("%d identi\n",id);
                printf("%s",nom);
        ptr->inicio=novo;
        ptr->tam++;
        ptr->fim=novo;
        strcpy(nom,novo->nome );
//        novo->nome = nom ;
        novo->idPessoa=id;
        novo->prox=NULL;

    }else
    {
        novo=ptr->fim;
        Pessoa *Nnovo= malloc(sizeof(Pessoa));
        novo->prox=Nnovo;
        strcpy(nom,Nnovo->nome);
//        Nnovo->nome=nom;
        Nnovo->idPessoa=id;
        Nnovo->prox= NULL;
        ptr->fim=Nnovo;
        ptr->tam++;
    }
}



int main ()
{
    Fila filaPeople;
    char nome[max];
    int id;
    int i, cont, tam;


    while (i < 3)
    {

        printf ("digite o nome da pessoa\n");
        scanf ("%s", nome);
        scanf("%d", &id);
        insereFila(&filaPeople, nome, id);
        i++;
    }
return 0;
}
