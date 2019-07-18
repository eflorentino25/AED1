#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct caract
{
char           abc   ;
int            num   ;
struct caract *ant   ;
struct caract *nxt   ;
}                    ;

typedef struct caract ty_caract;

struct lista
{
struct caract *l_int ;
int           size   ;
struct caract *fst   ;
struct caract *lst   ;
}                    ;

typedef struct lista ty_lista  ;

void insereElementoInicio (ty_lista *listaAux, char letra)
{ // Alocando espaço para o elemento
 ty_caract *novo = (ty_caract*) malloc(sizeof(ty_caract));
 ty_caract *adit = (ty_caract*) malloc(sizeof(ty_caract));
 int loop;
 int in = 0  ;
if (letra == 'o')printf("\n letra = 'o' \n");
if (listaAux->size == 0 )
    {
    novo->abc       = letra  ;
    novo->num       = 1      ;
    novo->ant       = NULL   ;
    novo->nxt       = NULL   ;
    listaAux->fst   = novo   ;
    listaAux->lst   = novo   ;
    listaAux->size  = 1      ;
    printf("Primeira letra -> %c : %i, tamList:%i \n ",novo->abc, novo->num, listaAux->size);
    }
else
    {
    novo = listaAux->fst;
    for (loop = 1; loop <= listaAux->size ; loop++)
        {
        if (novo->abc == letra)
            {
           novo->num = novo->num + 1 ;
           in = 1;
           if (novo->nxt != NULL)
                {
                novo = novo->nxt;
                }
            }
        else
            {
            if (novo->nxt != NULL)
                {
                novo = novo->nxt;
                }
            }
        }
        if (in == 0)
            {
              novo              = listaAux->lst         ;
              //update list.
              adit->abc         = letra                 ;
              adit->num         = 1                     ;
              adit->nxt         = NULL                  ;
              adit->ant         = novo                  ;
              novo->nxt         = adit                  ;
              listaAux->lst     = adit                  ;
              listaAux->size    = listaAux->size + 1    ;
            }
    }
}

void printelems (ty_lista *listaAux)
{
ty_caract *novo = (ty_caract*) malloc(sizeof(ty_caract));
novo = listaAux->fst;
while (novo->nxt != NULL)
    {
    printf("%c : %i \n",novo->abc, novo->num);
    novo = novo->nxt;
    }
    printf("%c : %i \n",novo->abc, novo->num);
    printf("Tamanho final lista :%i \n",listaAux->size);
}

void il(ty_lista *listaAux)
{
listaAux->fst   = NULL      ;
listaAux->lst   = NULL      ;
listaAux->l_int = NULL      ;
listaAux->size  = 0         ;
}


int main ()
{
char recebe[256];

int i,j;

ty_lista stringer;

for (j = 0 ; j < strlen(recebe); j++)recebe[j] = 0;

scanf("%[^\n]s",recebe);

il(&stringer); //initialize list.

i = 0;
while (recebe[i] != '\0')
    {
    if (recebe[i]>64 && recebe[i]<91)
        {
        recebe[i] = recebe[i] + 32 ; //Make all characters lower case.
        printf("Transforma Minuscula -> %c \n ",recebe[i]);
        }
    insereElementoInicio(&stringer,recebe[i]);
    i++ ;
    }
 printelems(&stringer);
}
/*
for (i = 0 ; i < strlen(recebe); i++) //loop through whole string into function.
    {

    if (recebe[i]>64 && recebe[i]<91)
        {
    recebe[i] = recebe[i] + 32 ; //Make all characters lower case.
        }
    if (recebe[i] != '\0')
        {
    insereElementoInicio(&stringer,recebe[i]);
        }
    else
        {
        break;
        }
    }
printelems(&stringer);
}
*/
