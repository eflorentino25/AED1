#include<stdio.h>

int recursivo(int j)
 {
 if (j < 100)
    {
    j = j+1;e
    recursivo(j);
    }
    else{ return j; }
}

int main()
{
int a = 0;

a = recursivo(a);
printf("%i",a);

}
