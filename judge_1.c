#include <stdlib.h>
#include <stdio.h>

void main()
{
int *wa_nump     = NULL;
int *wa_nump_aux = NULL;
int lv_novo , i , c ;
wa_nump = (int*) malloc(sizeof(int)*1);

if (wa_nump == NULL)
    {
    printf("memória insuficiente.");
    }
for( i = 0 ; i <=11; i++ )
    {
        printf("coloque um novo numero, diferente dos anteriores.");
        scanf("%d", &lv_novo);
        wa_nump[i] = lv_novo;
        wa_nump_aux = (int*) malloc(sizeof(int)*(i+1));
        if (wa_nump_aux == NULL) printf("memoria insuficiente");
     for(c = 0; c <= i; c++)
        {
         wa_nump_aux[c] = wa_nump[c];
        }
        free(wa_nump);
        wa_nump = (int*) malloc(sizeof(int)*(i+1));
        if (wa_nump == NULL) printf("memoria insuficiente");

     for (c = 0; c <= i; c++)
        {
        wa_nump[c] = wa_nump_aux[c];
        printf("%d\n", wa_nump[c]);
        }
        free(wa_nump_aux);
    }
}
