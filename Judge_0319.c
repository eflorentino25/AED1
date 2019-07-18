#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct caract
{
int            num   ;
int            ele   ;
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

void insereElementoInicio (ty_lista *listaAux, int num, int exp)
{ // Alocando espaço para o elemento
 ty_caract *novo = (ty_caract*) malloc(sizeof(ty_caract));
 ty_caract *adit = (ty_caract*) malloc(sizeof(ty_caract));
 ty_caract *thir = (ty_caract*) malloc(sizeof(ty_caract));
 int loop;
 int in = 0  ;
//if (letra == 'o')printf("\n letra = 'o' \n");
if (listaAux->size == 0 )
    {
    novo->num       = num    ;
    novo->ele       = exp    ;
    novo->ant       = NULL   ;
    novo->nxt       = NULL   ;
    listaAux->fst   = novo   ;
    listaAux->lst   = novo   ;
    listaAux->size  = 1      ;
  //  printf("Primeira letra -> %c : %i, tamList:%i \n ",novo->ele, novo->num, listaAux->size);
    }
else
    {
    novo = listaAux->fst;
  //  for (loop = 1; loop <= listaAux->size ; loop++)
    while ( 1 >  0)
        {
        if( exp != listaAux->fst->ele)
                {
                if( exp < listaAux->fst->ele)
                    {
                   adit->num = num              ;
                   adit->ele = exp              ;
                   adit->nxt = listaAux->fst    ;
                   adit->ant = NULL             ;
                   listaAux->fst->ant = adit    ;
                   listaAux->fst = adit         ;
                   listaAux->size = listaAux->size + 1 ;
                //   printf("primeira letra lista %c \n",listaAux->fst->ele);
                   return NULL ;
                    }
                else
                    {
                    if( exp > listaAux->lst->ele)
                        {
                        listaAux->lst->nxt = adit   ;
                        adit->ele = exp             ;
                        adit->num = num             ;
                        adit->nxt = NULL            ;
                        adit->ant = listaAux->lst   ;
                        listaAux->lst = adit        ;
                        listaAux->size = listaAux->size + 1 ;
                    //    printf("ultima letra lista %c \n",listaAux->lst->ele);
                        return NULL ;
                         }
                    else
                         {
                        while(novo->nxt != NULL)
                            {
                            novo = novo->nxt;
                            if(novo->ele == exp)
                                {
                                novo->num = novo->num +  num ;
                                return NULL;
                                }
                            else
                                {
                                    if(novo->ele > exp )
                                        {
                                        thir = novo->ant;
                                        if(exp > thir->ele)
                                            {
                                        adit->ele = exp  ;
                                        adit->num = num  ;
                                        adit->nxt = novo ;
                                        adit->ant = thir ;
                                        thir->nxt = adit ;
                                        novo->ant = adit ;
                                        listaAux->size++ ;
                                       // printf("'%c' entre '%c' e '%c' \n",adit->ele , thir->ele,novo->ele);
                                            return NULL ;
                                             }
                                        }
                                    else // novo->ele < letra
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
                novo->num = novo->num + num;
                return NULL ;
                }
            }
        }
}

//-------------------------------------------------------------------

void printelems (ty_lista *listaAux)
{
ty_caract *novo = (ty_caract*) malloc(sizeof(ty_caract));
novo = listaAux->lst;
while (novo->ant != NULL)
    {
    if(novo->num == 0)
        {
        printf("");
        novo = novo->ant;
        listaAux->size--;
        }
    else if(novo->num > 0)
        {
        printf("+%dx^%d ",novo->num,novo->ele);
        novo = novo->ant;
        }

    else
        {
        printf("%dx^%d ",novo->num,novo->ele);
        novo = novo->ant;
        }

    }
    if(novo->num == 0)
        {
        listaAux->size--;
        if(listaAux->size == 0 )
            {
            printf("nulo \n");
            }
        else
            {
            printf("\n");
            }

        }
    else if(novo->num > 0)
        {
        printf("+%dx^%d \n",novo->num,novo->ele);
        }

    else
        {
        printf("%dx^%d \n",novo->num,novo->ele);
        }

    printf("%d",listaAux->size);
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

int i,j,N,C,E;

ty_lista l_pol;

scanf("%d",&N);

il(&l_pol); //initialize list.
for(i = 0 ; i< N;i++)
    {
    scanf("%d",&C);
    scanf("%d",&E);
    if((-10000 <=  C) && (C <= 10000) && (0 <= E) && (E <= 1023))insereElementoInicio(&l_pol,C,E);
    }

 printelems(&l_pol);
 return 0 ;

}
