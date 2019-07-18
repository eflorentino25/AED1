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
int        size   ;
struct caract *fst   ;
struct caract *lst   ;
}                    ;

typedef struct lista ty_lista  ;

void insereElementoInicio (ty_lista *listaAux, char letra)
{ // Alocando espaço para o elemento
 ty_caract *novo = (ty_caract*) malloc(sizeof(ty_caract));
 ty_caract *adit = (ty_caract*) malloc(sizeof(ty_caract));
 ty_caract *thir = (ty_caract*) malloc(sizeof(ty_caract));
 int loop;
 int in = 0  ;
//if (letra == 'o')printf("\n letra = 'o' \n");
if (listaAux->size == 0 )
    {
    novo->abc       = letra  ;
    novo->num       = 1      ;
    novo->ant       = NULL   ;
    novo->nxt       = NULL   ;
    listaAux->fst   = novo   ;
    listaAux->lst   = novo   ;
    listaAux->size  = 1      ;
  //  printf("Primeira letra -> %c : %i, tamList:%i \n ",novo->abc, novo->num, listaAux->size);
    }
else
    {
    novo = listaAux->fst;
  //  for (loop = 1; loop <= listaAux->size ; loop++)
    while ( 1 >  0)
        {
        if( letra != listaAux->fst->abc)
                {
                if(letra < listaAux->fst->abc)
                    {
                   adit->abc = letra;
                   adit->num = 1    ;
                   adit->nxt = listaAux->fst;
                   adit->ant = NULL;
                   listaAux->fst->ant = adit;
                   listaAux->fst = adit;
                   listaAux->size = listaAux->size + 1 ;
                //   printf("primeira letra lista %c \n",listaAux->fst->abc);
                   return NULL ;
                    }
                else
                    {
                    if(letra > listaAux->lst->abc)
                        {
                        listaAux->lst->nxt = adit ;
                        adit->abc = letra;
                        adit->num = 1    ;
                        adit->nxt = NULL ;
                        adit->ant = listaAux->lst;
                        listaAux->lst = adit;
                        listaAux->size = listaAux->size + 1 ;
                    //    printf("ultima letra lista %c \n",listaAux->lst->abc);
                        return NULL ;
                         }
                    else
                         {
                        while(novo->nxt != NULL)
                            {
                            novo = novo->nxt;
                            if(novo->abc == letra)
                                {
                                novo->num = novo->num +  1 ;
                                return NULL;
                                }
                            else
                                {
                                    if(novo->abc > letra )
                                        {
                                        thir = novo->ant;
                                        if(letra > thir->abc)
                                            {
                                        adit->abc = letra;
                                        adit->num = 1    ;
                                        adit->nxt = novo ;
                                        adit->ant = thir ;
                                        thir->nxt = adit ;
                                        novo->ant = adit ;
                                        listaAux->size++ ;
                                       // printf("'%c' entre '%c' e '%c' \n",adit->abc , thir->abc,novo->abc);
                                            return NULL ;
                                             }
                                        }
                                    else // novo->abc < letra
                                        {
                                        novo = novo; //não faz nada.
                                        }
                                }
                            }
                         }
                    }
                }
            else
                {
                novo->num = novo->num + 1;
                return NULL ;
                }
            }
        }
}

//-------------------------------------------------------------------

void printelems (ty_lista *listaAux)
{
char letras[] =  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y','Z'};
int i = 0 ;
ty_caract *novo = (ty_caract*) malloc(sizeof(ty_caract));
novo = listaAux->fst;
while (novo->nxt != NULL)
    {
    for(i=0;i<=25;i++)
        {
          if   (novo->abc == letras[i])   printf("%c %i \n",novo->abc, novo->num);
        }
    novo = novo->nxt;
    }
    for(i=0;i<=25;i++)
        {
          if   (novo->abc == letras[i]) printf("%c %i \n",novo->abc, novo->num);
        }
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
    if (recebe[i]>96  && recebe[i]<123) // (frase[i] >96 && frase[i]<123)
        {
        recebe[i] = recebe[i] - 32 ; //Make all characters UPPER case.
        }
    insereElementoInicio(&stringer,recebe[i]);
    i++ ;
    }
 printelems(&stringer);
}
