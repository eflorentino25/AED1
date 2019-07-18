/* Program: Grafos Ponderados
Def.: Definição, estrutura, operações e manipulação
Author: Valerio Rosset
Version: 3.0 - 08/11/2018
*/

#include <stdio.h>
#include <math.h>
#define NULL 0
#define MAXVERTICES 6

 struct vertice{
 int peso;
 int aresta; // 0 ou 1
 };

 struct grafo {
 struct vertice matrizAdj [MAXVERTICES][MAXVERTICES]; //Cria um vértice para  cada ponto da matriz.
 };
 typedef struct grafo tipoGrafo;

 // vetores auxiliares
 int verticesAbertos [MAXVERTICES]; // 0 aberto; 1 fechado
 int estimativas [MAXVERTICES];
 int precedentes [MAXVERTICES];

 void inicializa(tipoGrafo *grafoAux){
 int i,j;
 for (i=0; i<=MAXVERTICES-1; i++)
 for (j=0; j<=MAXVERTICES-1; j++){
 grafoAux->matrizAdj[i][j].peso=0;
 grafoAux->matrizAdj[i][j].aresta=0;
 }
 }

 void criaLigacao(tipoGrafo *grafoAux, int i, int j, int peso){
 grafoAux->matrizAdj[i][j].aresta=1;
 grafoAux->matrizAdj[i][j].peso=peso;
 grafoAux->matrizAdj[j][i].aresta=1;
 grafoAux->matrizAdj[j][i].peso=peso;
 }

 void removeLigacao (tipoGrafo* grafoAux, int i, int j){
 grafoAux->matrizAdj[i][j].aresta=0;
 grafoAux->matrizAdj[j][i].aresta=0;
 }


 void mostrar_todos_caminhos(tipoGrafo *grafoAux, int i , int j )
 {
    int a = j;
    for (i = i ; i <= MAXVERTICES-1 ; i++)
        {
        for (j = j; j <= MAXVERTICES-1 ; j++)
            {
            if (grafoAux->matrizAdj[i][j].aresta == 1)printf("(%d , %d )" ,i , j );

            }
            j = 0;
        }
 }


 void mostraMatriz(tipoGrafo *grafoAux)
 {
 int i,j;
 for (i=0; i<=MAXVERTICES-1; i++){
 for (j=0; j<=MAXVERTICES-1; j++)
 printf ("%d ", grafoAux->matrizAdj[i][j].aresta);
 printf("\n");
 }
 }

 void main(){

 tipoGrafo grafo1;

 inicializa(&grafo1);

 criaLigacao(&grafo1,0,1,2);
 criaLigacao(&grafo1,1,3,4);
 criaLigacao(&grafo1,1,2,2);
 criaLigacao(&grafo1,2,3,2);
 criaLigacao(&grafo1,2,4,1);
 criaLigacao(&grafo1,3,5,2);


 mostraMatriz(&grafo1);

 mostrar_todos_caminhos(&grafo1,2);

 }

