#include <stdlib.h>
#include <stdio.h>

int main()
{
int *wa_nump = NULL;
//int *wa_nump_aux = NULL;
int lv_novo , i , c ;
int first, lv_last = 0 , lv_igual;

wa_nump = (int*) malloc(sizeof(int)*1);

for (i = 0 ; i < 150 ; i ++)
    {
    printf("coloque um numero: \n");

    //c = (sizeof(wa_nump)/sizeof(int));
    scanf("%d", &lv_novo);
    //printf("\n%d", c );
    for (c = 0 ; c <= i; c++)
        {
            if  (wa_nump[c] == lv_novo)
            {
             lv_igual = 1 ;
             break;
            }
        }
    if  (lv_igual != 0 )
        {
        lv_igual = 0;
        continue;
        }
    else
        {
        wa_nump[lv_last] = lv_novo;
        lv_last++;
//        printf( "\n %d", wa_nump[lv_last-1]);
        wa_nump = (int*) realloc( wa_nump ,((lv_last+1)*sizeof(int)));
        }
    }

    for (i = 0 ; i < lv_last-1 ; i ++)    printf(" %d", wa_nump[i]);

}
