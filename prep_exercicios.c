#include<stdio.h>
#include<stdlib.h>

int a,b,c ;
int wa_cinq[50];

void  main()
{

for (a = 0 ; a <= 49 ; a++)
    {
    b = rand();
    wa_cinq[a]= b;
    printf("%d;", b);
    }

    printf("\n \n \n");
for ( a=49 ; a >=0; a--)
    {
    printf("%d;", wa_cinq[a]);
    }

}
