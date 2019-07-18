/* A entrada para cada teste inicia-se com uma linha contendo três valores: o tamanho máximo de
caracteres da primeira string X (1 ≤ X ≤ 80), o tamanho máximo de caracteres da segunda string Y (1
≤ Y ≤ 80), e um caractere C do tipo char. Na próxima linha, devem ser fornecidos as duas strings,
separados por um espaço em branco. Nota-se que o tamanho máximo (X ou Y), não representam
necessariamente o tamanho real da string digitada

 Eduardo Florentino RA:111875
 */

 #include<stdio.h>
 #include<stdlib.h>


 int main()
 {
  char *X;
  char *Y;
  char *Z;
  int Val01,Val02,Val03,QT = 0;
  char procura;
  int i,j =0,c;

  scanf("%d %d %c",&Val01,&Val02,&procura);
  //printf("Valores: %d %d %c \n",Val01,Val02,procura);
  if(Val01<= 80 && Val01>=1 && Val02<= 80 && Val02>=1)
  {
  X = malloc(sizeof(char)*Val01);
  Y = malloc(sizeof(char)*Val02);
  Val03 = Val01+Val02;
  Z = malloc(sizeof(char)*Val03);
  }
  //Limpar espaços dos ponteiros alocados.
for(i = Val01 ; i>= 0 ; i--)
    {
    X[i] = NULL;
    }
for(i = Val02 ; i>= 0 ; i--)
    {
    Y[i] = NULL;
    }
for(i = Val03 ; i>= 0 ; i--)
    {
    Z[i] = NULL;
    }
  X[0] = 'a';
  Y[0] = 'a';
  Z[0] = 'a';
  scanf("%s",X);
  scanf("%s",Y);
  //printf("%s %s \n",X,Y);
  fflush(stdout);
  for(i = Val01 ; i>= 0 ; i--)
    {
    if(X[i]=='\0')
        {
        c = i-1;
        for( c = c ; c>=0 ; c-- )
            {
            if(X[c] != '\0')
                {
                 if( procura == X[c] )QT++;
                Z[j] = X[c];
                //printf("%d %c \n" ,j, X[c]);
                j++;
                }
            }
        break;
        }
    }

  for(i = Val02 ; i >=1 ; i-- )
    {
    if(Y[i]=='\0')
        {
        c = i-1;
        for( c = c ; c>=0 ; c--)
            {
            if(Y[c] != '\0')
                {
                if( procura == Y[c] )QT++;
                Z[j] = Y[c];
                j++;
                }
            }
        break;
        }
    }

 Z[j] = '\0';
 //for(i=0;i<=Val03;i++)
 //   {
//    if(Z[i]=='\0')break;
printf("%s\n",Z);
//    }
 printf("%d\n",j);
 printf("%d",QT);
 return 0;
 }

