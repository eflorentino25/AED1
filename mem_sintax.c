#include <stdio.h>
#include <stdlib.h>

int getMax(int vetor[20] , int max, int min)
{
    int a;
    for( a = 0 ; a <= 19 ; a++ )
    {
        if (max < vetor[a] )
        {
            max = vetor[a] ;
            printf("%d" , &max);
        }
        if  (min > a)
        {
            min = (vetor[a]);
        }
    }
}

void main()
{
int lv_counter , lv_min, lv_max ; //*lp_min, *lp_max ;
int wa_allnum[20] ; // Criando o vetor com 20 posições

//*lp_min = lv_min;  //Atribuindo variáveis aos ponteiros.
//*lp_max = lv_max;

for (lv_counter = 0; lv_counter <= 19 ; lv_counter++ )
    {
        printf("%d" , &lv_counter);
        printf('0 \n');
        wa_allnum[lv_counter] = lv_counter;
        //printf("%d" , &wa_allnum[lv_counter]);
    }
    //getMax(wa_allnum , lv_max, lv_min);
}
