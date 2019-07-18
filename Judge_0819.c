//*****************************************************************************
//** JUDGE 08 - Decriptação de dados. Obter string
//*****************************************************************************
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//*****************************************************************************
//** JUDGE 08  - Declaração para as estruturas para recebimento e ordenação alfabetica
//*****************************************************************************

struct caract
{
char abc ;
int num ;
struct caract *ant ;
struct caract *nxt ;
} ;

typedef struct caract ty_caract;

struct lista
{
struct caract *l_int ;
int size ;
struct caract *fst ;
struct caract *lst ;
} ;
typedef struct lista ty_lista ;

//*****************************************************************************
//** JUDGE 08 - Estruturas para Arvore
//*****************************************************************************
struct  noarvore
{
int         repeticao         ;
char       letra                 ;
struct noarvore *esq ;
struct noarvore *dir  ;
};
typedef struct noarvore ty_noarvore;

struct arvore
{
struct noarvore *raiz            ;
int                           numnos    ;
};
typedef struct arvore ty_arvore;

//*****************************************************************************
//** JUDGE 08 - Inicio das Funções para manipulação da árvore
//*****************************************************************************

void inicializaArv(ty_arvore *arv)
{
 arv->raiz = NULL;
}

void emOrdem(ty_noarvore *no) //Print da árvore.
{
                if(no==NULL)
                {
                printf("nó vazio man");
                return ;
                }
                emOrdem(no->esq);
                printf("%c\n",no->letra);
                emOrdem(no->dir);
}


ty_noarvore *criaNo(int num, char x) // aloca e cria o nó
{
                ty_noarvore *no;
                no = malloc(sizeof(ty_noarvore));
                no->repeticao = num;
                no->letra = x ;
                no->dir = NULL;
                no->esq = NULL;
                return no;
}


void insereNo(ty_noarvore *no, int num, char letra) //Insere nó na arvore
{
                if(num < no->repeticao)
                {
                                if(no->esq!=NULL)
                                {
                                insereNo(no->esq,num,letra);
                                }
                                else
                                {
                                no->esq = criaNo(num,letra);
                                }
                }
                else
                {
                                if(no->dir!=NULL) insereNo(no->dir,num,letra);
                                else no->dir = criaNo(num,letra);
                }

}

//*****************************************************************************
//** JUDGE 08 - Inicios das Funções para manipulação e ordenação da string.
//*****************************************************************************

void insereElementoInicio (ty_lista *listaAux, char letra)
{ // Alocando espaço para o elemento
ty_caract *novo = (ty_caract*) malloc(sizeof(ty_caract));
ty_caract *adit = (ty_caract*) malloc(sizeof(ty_caract));
ty_caract *thir = (ty_caract*) malloc(sizeof(ty_caract));
int loop;
int in = 0 ;
//printf("%c\n",letra);
if (listaAux->size == 0 )
{
novo->abc = letra ;
novo->num = 1 ;
novo->ant = NULL ;
novo->nxt = NULL ;
listaAux->fst = novo ;
listaAux->lst = novo ;
listaAux->size = 1 ;
//printf("%c\n",letra);
}
else
{
novo = listaAux->fst;
while ( 1 > 0)
{
if( letra != listaAux->fst->abc)
{
if(letra < listaAux->fst->abc)
{
//printf("%c\n",letra);
adit->abc = letra;
adit->num = 1 ;
adit->nxt = listaAux->fst;
adit->ant = NULL;
listaAux->fst->ant = adit;
listaAux->fst = adit;
listaAux->size = listaAux->size + 1 ;
return NULL ;
}
else
{
if(letra > listaAux->lst->abc)
{
//printf("%c\n",letra);
listaAux->lst->nxt = adit ;
adit->abc = letra;
adit->num = 1 ;
adit->nxt = NULL ;
adit->ant = listaAux->lst;
listaAux->lst = adit;
listaAux->size = listaAux->size + 1 ;
return NULL ;
}
else
{
while(novo->nxt != NULL)
{
novo = novo->nxt;
if(novo->abc == letra)
{
//printf("%c\n",letra);
novo->num = novo->num + 1 ;
return NULL;
}
else
{
if(novo->abc > letra )
{
//printf("%c\n",letra);
thir = novo->ant;
if(letra > thir->abc)
{
adit->abc = letra;
adit->num = 1 ;
adit->nxt = novo ;
adit->ant = thir ;
thir->nxt = adit ;
novo->ant = adit ;
listaAux->size++ ;
//printf("%c\n",letra);
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

void il(ty_lista *listaAux)
{
listaAux->fst = NULL ;
listaAux->lst = NULL ;
listaAux->l_int = NULL ;
listaAux->size = 0 ;
}
void transformtotree (ty_lista *listaAux, ty_noarvore *raiz)
{
ty_caract *novo = (ty_caract*) malloc(sizeof(ty_caract));
novo = listaAux->fst;
while (novo->nxt != NULL)
                {
                //printf("%c %i \n",novo->abc, novo->num);
                if(raiz==NULL)raiz = criaNo( novo->num , novo->abc );
                else insereNo( raiz  ,  novo->num , novo->abc );
                novo = novo->nxt ;
                }
                //printf("%c %i \n",novo->abc, novo->num);
insereNo(raiz,novo->num,novo->abc);
}

//*****************************************************************************
//** JUDGE 08 - Inicio do programa Principal
//*****************************************************************************

int main ()
{
//instanciação de variáveis.
char recebe[1025];
ty_arvore baoba;
int i,j;
ty_lista stringer;

inicializaArv(&baoba);

for (j = 0 ; j < strlen(recebe); j++)recebe[j] = 0;

scanf("%[^\n]s",recebe);

il(&stringer); //initialize list.

i = 0;
while (recebe[i] != '\0')
{
                if (recebe[i]>96  && recebe[i]<123 ) //Transformar em Letras maiusculas todas as letras
                {
                recebe[i] = recebe[i] - 32 ; //Make all characters upper case.
                }
                insereElementoInicio(&stringer,recebe[i]);
//                printf("%c\n", recebe[i]);
                i++ ;
}
transformtotree(&stringer , baoba.raiz ) ;
emOrdem(baoba.raiz);
return 0 ;
}




