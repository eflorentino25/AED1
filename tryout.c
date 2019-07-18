








  /*
        if(novo->abc != letra )
            {
            if(novo->abc < letra)
                {
                if(novo->nxt != NULL)novo = novo->nxt;
                if(novo->nxt == NULL)
                    {
                    adit->abc = letra;
                    adit->num = 1    ;
                    adit->nxt = NULL ;
                    adit->ant = novo ;
                    novo->nxt = adit ;
                    listaAux->lst  = adit;
                    listaAux->size = listaAux->size + 1 ;
                    printf("%c menor que %c \n",novo->abc,adit->abc);
                    break;
                    }
                }
             else
                {
                if (novo->ant != NULL)
                        {
                        thir = novo->ant;
                        adit->abc = letra;
                        adit->num = 1    ;
                        adit->nxt = novo ;
                        adit->ant = thir ;
                        thir->nxt = adit ;
                        novo->ant = adit ;
                        listaAux->size = listaAux->size + 1 ;
                        }
                 else
                        {
                        adit->abc = letra;
                        adit->num = 1    ;
                        adit->nxt = novo ;
                        adit->ant = NULL ;
                        novo->ant = adit ;
                        listaAux->fst = adit;
                        listaAux->size = listaAux->size + 1 ;
                        }
                 printf("%c maior que %c \n",novo->abc,adit->abc);
                 break;
                }
            }
        else
            {
            novo->num++;
            printf("%c igual a %c \n",novo->abc,letra);
            break;
            }
       */
