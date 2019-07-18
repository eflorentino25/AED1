#include<stdlib.h>
#include<stdio.h>

typedef struct adjlist_node adjlist;
struct adjlist_node {
 int vert ; //vertice de ligacao
 adjlist *next;
};

typedef struct graph_header graph;
struct graph_header {
 unsigned int size; //qde vertices
 adjlist **adj;
 int *info; //Info de cada nó // qualquer info
};

graph* initGraph(unsigned int nvert) {
    graph *G;
    G = (graph*) malloc(sizeof(graph));
    G->adj = (adjlist**) malloc(nvert * sizeof(adjlist*));
    for(int i=0 ; i<nvert ; i++) G->adj[i] = NULL;
    G->info = (int*) malloc(nvert * sizeof(int));
    G->size = nvert;
    return G;
}
void initVertex(graph *G, unsigned int i, int data)
 {
     G->info[i]=data;
}
void graphAddEdge(graph* G, int v, int w)
 {
   adjlist *L;
   L = (adjlist*) malloc(sizeof(struct adjlist_node));
   L->vert = w;
   L->next = G->adj[v];
   G->adj[v] = L;
   L = (adjlist*) malloc(sizeof(struct adjlist_node));
   L->vert = v;
   L->next = G->adj[w];
   G->adj[w] = L;
}
int graphHasEdge(graph* G, int v, int w)
 {
     adjlist *L = G->adj[v];
     while(L != NULL) {
          if(L->vert == w) return 1;
          L = L->next; }
     return 0;
}
void showGraph(graph* G)
 {
    int i, nvert = G->size;
    adjlist *L;
    for(i=0; i<nvert; i++) {
       printf("vertex=%d – edges:", i);
       L = G->adj[i];
       while(L != NULL) {
            printf("%d ", L->vert);
            L = L->next; }
       printf("\n");
                }
}
void main(void) {
int Vt, QtA , QtV , i , from , to ;//Vetor de busca,quantia aresta,quantia vertice,i p/loop, de onde para onde.

scanf("%d",&Vt);
scanf("%d %d",&QtV,&QtA);

graph* G = initGraph(QtV);
for (i = 0 ; i <=QtA ; i++)
{
 scanf("%d %d",&from, &to );
graphAddEdge(G, from, to); // AB
}
//   graphAddEdge(G, 1, 2); // BC
//   graphAddEdge(G, 2, 3); // CD
//   graphAddEdge(G, 0, 4); // AE
//   graphAddEdge(G, 1, 4); // BE
//   graphAddEdge(G, 2, 4); // CE
   showGraph(G);
}
