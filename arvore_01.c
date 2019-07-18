#include<stdio.h>
#include<stdlib.h>

struct nodaarvore
{
int                                             valor           ;
struct nodaarvore               *esq            ;
struct nodaarvore              *dir            ;
};

typedef struct nodaarvore no;
struct arvore
{
struct nodaarvore raiz;
};

typedef struct arvore raiz;

void eliminano(no *noAux)
{
                no *q;
                if (noAux->esq == NULL)
                {
                                q = noAux;
                                printf("\n Na função %d ",q->valor);
                                noAux = noAux->dir;
                                free(q);
                                printf("\n Após liberar %d ",q->valor);
                }
}
void inserebinario(int val; raiz *arvore)
{
if ()


}


int main()
{
no *no_1;
raiz jabuticabeira;
no_1 = malloc(sizeof(no)*1);
no_1->valor = 10;
no_1->esq = NULL;
no_1->dir = NULL;
printf("antes da func :%d ",no_1->valor);
eliminano( no_1);

}
