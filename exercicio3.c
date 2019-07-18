#include <stdio.h>
#include <stdlib.h>

int preencher(int m[4][4]){

int a,b,c;

for(a=0;a<4;a++){
    for(b=0;b<4;b++){
        c=rand()%10;
        m[a][b]=c;
        //printf("%d \n",c);
    }
}

}
int procurar(int m[4][4],int v[10]){

int a,b,c;
for(c=0;c<10;c++){
    v[c]=0;
}

for(c=0;c<10;c++){
    for(a=0;a<4;a++){
        for(b=0;b<4;b++){
            if(m[a][b]==c){
                v[c]=v[c]+1;
                //printf("igual");
            }
        }
    }
}
}

void main(){

int m[4][4],v[10],a;

preencher(m);

procurar(m,v);

printf("\nOs valores sao \n\n");

for(a=0;a<10;a++){

    printf("Numero %d, Qte na matriz: %d\n",a,v[a]);
}

}
