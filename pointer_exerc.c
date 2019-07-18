#include<stdio.h>
int x = 10 , y = 20 ;
int *p ;
p = &y;
x = x+*p;
*p = x/2;
p=&x;
printf("%d %d %d¥n",x,y,*p);
