
struct noArvoreBinaria {
char info;
struct noArvoreBinaria* esq;
struct noArvoreBinaria* dir;
};
typedef struct noArvoreBinaria tipoNoAB;

void inicializa (char c, tipoNoAB *arvoreAux){
arvoreAux->info = c;
//Alg.e Estruturas de Dados I – Prof. Valério Rosset 25
arvoreAux->info = c;
arvoreAux->esq = NULL;
arvoreAux->dir=NULL;
}

//Alg.e Estruturas de Dados I – Prof. Valério Rosset 28
void imprime ( tipoNoAB *aux ){
if (aux!= NULL)
printf("%c", aux->info);

printf("%c", aux->info);
if (aux->dir!= NULL)
imprime(aux->dir);
if (aux->esq!= NULL)
imprime(aux->esq);
}

tipoNoAB* insereNo ( char c ) {
tipoNoAB* novo = malloc(sizeof(tipoNoAB));
novo->info = c;
//Alg.e Estruturas de Dados I – Prof. Valério Rosset 26
novo->info = c;
novo->dir = NULL;
novo->esq= NULL;
return novo;
}
