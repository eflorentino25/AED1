#include<stdio.h>
#include<math.h>
#define N 20;

int min , max , *p_min , *p_max  ;
int wa_int[20]  ;


*p_min = nullptr;
*p_max = nullptr;

    void inserirint(int lv_index, int lv_val, int vetor[N])
    {

    vetor[lv_index] = lv_val;

    }

    void minimo(int vetor[N],int *p_min,int *p_max)
    {
        int i;

    for(i=0; i<=N; i++)
    {
    if (vetor[i] < *p_min)
    {
    *p_min = vetor[i];
    }
    if (vetor[i] > *p_max)
    {
    *p_max = vetor[i];
        }
    }
    }


int main(void)
{
int i;
for(i = 0; i <20 ; i + 1)
    {
        inserirint(i,i,wa_int[N]);
    }
    minimo(wa_int[N],min,max);
    printf("valor minimo:%d & máximo: %d",min,max);
}
