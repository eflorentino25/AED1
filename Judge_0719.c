#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct caract
{
char           letra ;
int            qt    ;
struct caract *ant   ;
struct caract *nxt   ;
}                    ;

typedef struct caract ty_caract;

struct lista
{
struct caract *l_int ;
int           size   ;
struct caract *fst   ;
struct caract *lst   ;
}                    ;

typedef struct lista ty_lista  ;

void insereElementoInicio (ty_lista *listaAux, char tetra)
{ // Alocando espaço para o qtmento
 ty_caract *novo = (ty_caract*) malloc(sizeof(ty_caract));
 ty_caract *adit = (ty_caract*) malloc(sizeof(ty_caract));
 ty_caract *thir = (ty_caract*) malloc(sizeof(ty_caract));
 adit->letra = ' ';
 adit->qt = 0;
 int loop;
 int in = 0  ;
//if (letra == 'o')printf("\n letra = 'o' \n");
if (listaAux->size == 0 )
    {
//    printf("Primeira Letra : %c \n",tetra);
    novo->letra     = tetra             ;
    novo->qt        = novo->qt + 1      ;
    novo->ant       = NULL              ;
    novo->nxt       = NULL              ;
    listaAux->fst   = novo              ;
    listaAux->lst   = novo              ;
    listaAux->size  = 1                 ;
  //  printf("Primeira letra -> %c : %i, tamList:%i \n ",novo->qt, novo->letra, listaAux->size);
    }
else
    {
//    printf("Letra : %c \n",tetra);
		novo = listaAux->lst;
  //  for (loop = 1; loop <= listaAux->size ; loop++)
	    if( novo->letra == tetra )
        {
          novo->qt =  novo->qt + 1                                  ;
//          printf("Repetida: %c Quantia:%d \n" , tetra, novo->qt)    ;
        }
	    else
	    {
	      novo->nxt 	= adit   ;
	      adit->letra 	= tetra  ;
          adit->qt++             ;
	      adit->nxt 	= NULL   ;
		  adit->ant 	= novo	 ;
	      listaAux->lst = adit   ;
	      listaAux->size++		 ;
	    }
    }
}

//-------------------------------------------------------------------

void printqtms (ty_lista *listaAux)
{
char primastring[500]; //String com todos os caracteres * sem correção
char secundastring[500]; //String com os caracteres corrigidos.
int i;
ty_caract *novo = (ty_caract*) malloc(sizeof(ty_caract));
ty_caract *adit = (ty_caract*) malloc(sizeof(ty_caract));
ty_caract *thir = (ty_caract*) malloc(sizeof(ty_caract));


novo = listaAux->fst;

  char str1[4];
  char subletra[2];
//for(i=0;i<500;i++)
//{
//primastring[i]	 = 0 ;
//secundastring[i] = 0 ;	
//}
	primastring[0]	 = '\0' ;
	secundastring[0] = '\0' ;	
  

//Contar todos os caracteres que existem na string. inicial
while (novo->nxt != NULL)
    {
//     printf("Letra para impressão %c",novo->letra)            ;
     sprintf(str1, "%d", novo->qt)                              ;
	 strcat(primastring,str1)	                                ;
     subletra[0] = novo->letra                                  ;
     subletra[1] = '\0'                                         ;
	 strcat(primastring,subletra)		                        ;
//	 printf("Concatenada %s \n",primastring)                    ;

	 novo = novo->nxt                                           ;
	 str1[0] = '0'                                              ;
	 str1[1] = '0'                                              ;
	 str1[2] = '0'                                              ;
	 str1[3] = '0'                                              ;
    }
     sprintf(str1, "%d", novo->qt)                              ;
	 strcat(primastring,str1)	                                ;
     subletra[0] = novo->letra                                  ;
     subletra[1] = '\0'                                         ;
	 strcat(primastring,subletra)		                        ;
	 printf("%d\n",strlen(primastring))                         ;
	 printf("%s\n",primastring)                                 ;
	 
//***
//Limpando as variaveis
	 str1[0] = '0'                                              ;
	 str1[1] = '0'                                              ;
	 str1[2] = '0'                                              ;
	 str1[3] = '0'                                              ;


//Eliminando o ruído qq caso que Elementoesq > 2 centro =1 Elementodir>2;
novo = listaAux->fst;
while (novo->nxt != NULL)
    {
        if (novo == listaAux->fst)
        {
        	thir = novo                   ;
        	novo = novo->nxt              ;
        	adit = novo->nxt              ;
        	if(thir->qt == 1 )
        	{
                if (novo->qt > 1)
                {
                    thir->letra = novo->letra   ;
                    listaAux->fst = novo        ;
                    thir->ant = NULL            ;
                    thir->nxt = NULL            ;
                    novo->qt = novo->qt + 1     ;
                }
        	}
        	else if(thir->qt > 1)
        	{
 			    if(novo->qt == 1)
			    {
			    	if	(adit->qt > 1)
			    	{
			    		if (thir->qt >= adit->qt)
                        {
                        //    printf("2ºcaso\n")			;
                            thir->nxt 	= adit        	;
                            thir->qt  	= thir->qt + 1	;
                            novo->nxt 	= NULL          ;
                            novo->ant 	= NULL          ;
                            novo->qt 	= 0             ;
						    novo 		= adit 			;
						    adit 		= adit->nxt     ;
							//printf("prima Letra %c Quantia %d \n",listaAux->fst->letra,listaAux->fst->qt);
                        }
                        else if(thir->qt < adit->qt)
                        {
                         //   printf("3ºcaso\n")		    ;
                            thir->nxt 	= adit          ;
							adit->ant   = thir          ;
                            novo->nxt 	= NULL          ;
                            novo->ant 	= NULL          ;
                            novo->qt 	= 0             ;
							adit->qt 	= adit->qt + 1  ;
							novo 		= adit 		    ;
							adit 		= adit->nxt     ;
                        }
					}
				}
        	}
        	//printf("Letras iniciais: %c %c %c \n",thir->letra,novo->letra,adit->letra);
           // printf("quantidades iniciais:thir %d  novo %d  adit %d \n",thir->qt,novo->qt,adit->qt);
        }
        else
		{
          //  printf("Correcoes: %c %c %c \n",thir->letra,novo->letra,adit->letra);
          //  printf("Numeros  : %d %d %d \n",thir->qt,novo->qt,adit->qt);
            if(thir->qt >2 && novo->qt == 1 && adit->qt>2)
            {
                if(thir->qt >= adit->qt)
                {
                  //  printf("4ºcaso\n")						;
				//	printf("Letra adit %c Quantia %d\n",adit->letra,adit->qt);
        	        thir->qt 	= thir->qt + 1				;
        	        thir->nxt 	= adit						;
					adit->ant   = thir                      ;
					novo->qt 	= 0							;
					novo->nxt 	= NULL						;
					novo->ant   = NULL						;
					//printf("Letra adit %c Quantia %d\n",adit->letra,adit->qt);
					//printf("prima Letra %c Quantia %d\n",listaAux->fst->letra,listaAux->fst->qt);
					//printf("4-Correcoes: %c %c %c \n",thir->letra,novo->letra,adit->letra);
					//printf("4-Numeros  : %d %d %d \n",thir->qt,novo->qt,adit->qt);
                }
                else if (thir->qt < adit->qt)
                {
                 //   printf("5ºcaso")			;
        	        adit->qt++					;
        	        thir->nxt 	= adit			;
					adit->ant   = thir          ;
					novo->qt 	= 0				;
					novo->nxt 	= NULL			;
					novo->ant   = NULL			;
                }
        	}
			if(adit->nxt != NULL)
			{
		        thir = thir->nxt    ;
                novo = thir->nxt    ;
				if (novo->nxt != NULL)
				{
				   adit = novo->nxt    ;
				   adit->ant = novo	   ;
				   novo->ant = thir	   ;
				  // printf("Loop adit %c Quantia %d\n",adit->letra,adit->qt);	
				}	
			}
			else
			{
				//printf("passeinobreak");
				break				;		
			}
				
        }
    }
//***
  //printf("adit ultimo %c Quantia %d\n",adit->letra,adit->qt);
    if(adit->qt == 1 && adit->ant->qt > 1 && adit->nxt == NULL )
	{
		thir 		= adit->ant		;
		thir->qt 	= thir->qt +1 	;	 
		thir->nxt	= NULL			;
		adit->qt   	= 0				;
		adit->nxt  	= NULL			;
		adit->ant   = NULL			;
	}
	else if (novo->qt == 1 && novo->ant->qt > 1 && novo->nxt == NULL )
	{
			novo->ant->qt 	= novo->ant->qt + 1	;
			novo->ant->nxt	= NULL 				;
			novo->ant		= NULL				;
			novo->qt		= 0					;
			
		
	}
	//}
////************** Reimprimir ***********

////Contar todos os caracteres que existem na string. inicial
novo = listaAux->fst;
while (novo->nxt != NULL)
    {
//     printf("Letra para impressão %c",novo->letra)              ;
     sprintf(str1, "%d", novo->qt)                              ;
	 strcat(secundastring,str1)	                                ;
     subletra[0] = novo->letra                                  ;
     subletra[1] = '\0'                                         ;
	 strcat(secundastring,subletra)		                        ;
//	 printf("Concatenada %s \n",secundastring)                       ;

	 novo = novo->nxt                                           ;
	 str1[0] = '0'                                              ;
	 str1[1] = '0'                                              ;
	 str1[2] = '0'                                              ;
	 str1[3] = '0'                                              ;
    }
     sprintf(str1, "%d", novo->qt)              ;
	 strcat(secundastring,str1)	                ;

     subletra[0] = novo->letra                                  ;
     subletra[1] = '\0'                                         ;
	 strcat(secundastring,subletra)		                        ;
	 printf("%d\n",strlen(secundastring))         ;
	 printf("%s\n",secundastring)                 ;
}

void il(ty_lista *listaAux)
{
listaAux->fst   = NULL      ;
listaAux->lst   = NULL      ;
listaAux->l_int = NULL      ;
listaAux->size  = 0         ;
}

//
int main ()
{

int i,j,C,E;
char N[1023];
ty_lista l_pol;

scanf("%[^\n]%*c",N);

il(&l_pol); //initialize list.

for( i = 0 ; i < 1023 ; i++ )
    {
	if(N[i] == '\0')break;
    insereElementoInicio(&l_pol,N[i]);
//    printf("%c\n",N[i]);
    }

 printqtms(&l_pol);

 return 0 ;

}



//WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW
//ABC
//AAAAAAAATTTTTTTTTTTTUUUUUIIIIENNNNNNNNNWNNNNNNNNNN
//WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWP