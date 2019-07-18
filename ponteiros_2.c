#include <stdio.h>
#include <stdlib.h>

 main()
 {
    int *p , i;

    p = (int*) malloc(20 * sizeof(int));

    if (p == NULL)
        {
        printf("memoria insuficiente");
        }
    else
    {
        for(i=0; i <= 20 ; i ++) *(p+i) = i;
        for(i=0; i <= 20 ; i ++) printf("%d\n", p[i]);
        free(p);
    }



 }
