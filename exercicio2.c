#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int    nalunos , max  , *p_max ;
float  nota;

 void main()
{


*p_max = 0;

p_max = (float*) malloc(sizeof(float) * 1) ;

printf("Coloque a nota do aluno, -1 caso deseje parar de adicionar notas:\n ") ;
scanf("%f", nota);

if (nota >  0 )
    {
    nalunos++;
    p_max = (float*) realloc(sizeof(float) * nalunos);
    p_max[nalunos] = nota;
    }
else
    {
    printf("Número total de alunos:%i \n Notas do primeiro ao último %f", nalunos , p_max );
    return();
    }
}

