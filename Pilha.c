#include<stdio.h>
#include<stdlib.h>
#define TamanhoMax 1024
//_____________Variáveis________________________//

struct pilha{
    int elem[TamanhoMax]    ;
    int topo                ;
};

typedef struct pilha TipoPilha;
int i,Qt = 0;
char N[TamanhoMax];
char opera;

//_____________Funções________________________//


void InicializaPilha(TipoPilha *PAux)
{
    int i;
    for(i =0 ;  i <= TamanhoMax-1 ; i++)
        {
        PAux->elem[i] = 0;
        }
    PAux->topo = -1;
}

int empilhar(TipoPilha *pilhaAux, char val)
{
    int rp,nx;

    if(pilhaAux->topo>=TamanhoMax-1)return -1 ;//pilhacheia

    else
        {
        if(val == '*')
            {
            printf("%c operação",val);
            nx = pilhaAux->elem[pilhaAux->topo] + 0;
            rp = pilhaAux->elem[pilhaAux->topo-1] + 0;
            pilhaAux->elem[pilhaAux->topo-1] = rp * nx ;
            pilhaAux->topo = pilhaAux->topo-1;
            printf("%d",pilhaAux->elem[pilhaAux->topo]);
            return 0;
            }
        else if(val == '-')
            {
            printf("%c operação -",val);
            nx = pilhaAux->elem[pilhaAux->topo] + 0;
            rp = pilhaAux->elem[pilhaAux->topo-1] + 0;
            pilhaAux->elem[pilhaAux->topo-1] = rp - nx ;
            pilhaAux->topo = pilhaAux->topo-1;
            printf("%d",pilhaAux->elem[pilhaAux->topo]);
            return 0;
            }
        else if(val == '+')
            {
            printf("%c operação +",val);
            nx = pilhaAux->elem[pilhaAux->topo] + 0;
            rp = pilhaAux->elem[pilhaAux->topo-1] + 0;
            pilhaAux->elem[pilhaAux->topo-1] = rp + nx ;
            pilhaAux->topo = pilhaAux->topo-1;
            printf("%d",pilhaAux->elem[pilhaAux->topo]);
            return 0;
            }
        else if(val == '/')
            {
            printf("%c operação /",val);
            nx = pilhaAux->elem[pilhaAux->topo] + 0;
            rp = pilhaAux->elem[pilhaAux->topo-1] + 0;
            pilhaAux->elem[pilhaAux->topo-1] = rp / nx ;
            pilhaAux->topo = pilhaAux->topo-1;
            printf("%d",pilhaAux->elem[pilhaAux->topo]);
            return 0;
            }
        else
            {
            printf("%c numero",  val);
            rp = val + 0 ;
            pilhaAux->topo++ ;
            pilhaAux->elem[pilhaAux->topo]= rp;
            printf("%d numero",pilhaAux->elem[pilhaAux->topo]);
            return 0;
            }
        }
}

//_____________Principal________________________//

void main()
{

TipoPilha Pilhamain;

InicializaPilha(&Pilhamain);

scanf("%s",N);
printf("%s",N);
i = 0;
while(N[i] =! '\0')
    {
    empilhar(&Pilhamain,N[i]);
    i++;
    }
}
