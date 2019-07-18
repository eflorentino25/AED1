#include <stdlib.h>
#include <stdio.h>

int main()
{
int *wa_nump = NULL;
int *wa_nump_aux = NULL;
int lv_novo , i , c , b ;
int first = 14, lv_last = 0 , lv_igual;
wa_nump = (int*) malloc(sizeof(int)* 14);

for (i = 0; i <=13 ; i ++)
    {
    wa_nump[i] = i;
    }
for (i = 0;i<=13;i++)
    {
    printf("coloque o número que deseja remover:\n");
    scanf("%d",&lv_novo);
    for(c = 0 ; c <= i ; c++)
        {
        if(wa_nump[c] == lv_novo)
            {
            for (b = c +1 ; b<=13 ; b++ )
                {
                wa_nump_aux[b] = wa_nump[b];
                lv_last = b;
                }
                first = first -1 ;
            wa_nump = (int*)  realloc(wa_nump,sizeof(int)*(first));
            }
         else
            {
            continue;
            }
        for (b = c; b<= lv_last; b++ )
            {
            wa_nump[b] = wa_nump_aux[b];
            }
        }
    }
    for(i = 0; i <= ; i++)
        {

        }

}

