// C program to find single source shortest paths for Directed Acyclic Graphs
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define INF INT_MAX
#define MAX 1024

// Graph is represented using adjacency list. Every node of adjacency list
// contains vertex number of the vertex to which edge connects. It also
// contains weight of the edge

typedef struct stackItem {
    int value;
    struct stackItem *next;
} stackItem;

typedef struct {
    stackItem *top;
} StackD;

void stackInit(StackD *stack) {
    stack->top = NULL;
}

int stackEmpty(StackD *stack) {
    if (stack->top == NULL)
        return 1;
    return 0;
}

void push(StackD *stack, int ch) {
  stackItem *newStackItem = (stackItem*)malloc(sizeof(stackItem));
  if (!newStackItem) {
    exit(-1);
  }
  newStackItem->value = ch;
  newStackItem->next = stack->top;
  stack->top = newStackItem;
}

int pop(StackD *stack) {
  int c;

  if (stackEmpty(stack)) {
    return -1;
  }

  stackItem *paux;
  paux = stack->top;
  stack->top = paux->next;
  c = paux->value;
  free(paux);

  return c;
}

void showStack(StackD *stack) {
  stackItem *newStackItem;
  newStackItem = stack->top;
//  printf("Stack: ");
  while(newStackItem) {
//    printf("%d ",newStackItem->value);
    newStackItem = newStackItem->next;
  }
//  printf("\n");
}


typedef struct adjlist_node {
  int vert; //Link vertex
  int cost; //Edge weight
  struct adjlist_node *next;
} adjlist;

typedef struct graph_header {
  unsigned int size; //number of vertex used
  adjlist **adj;
  int *info; //any info
} graph;

graph *initGraph(unsigned int nvert) {
  graph *G;
  int i;
  G = (graph *)malloc(sizeof(graph));
  G->adj = (adjlist **)malloc(nvert * sizeof(adjlist*));
  for (i = 0; i < nvert;i++) G->adj[i] = NULL;
  G->info = (int *)malloc(nvert * sizeof(int));
  G->size = nvert;
  return G;
}

void initVertex(graph *G, unsigned int i, int data) {
  G->info[i] = data;
}

void graphAddEdge(graph* G, int v, int w, int weight) {
  adjlist *L;
  L = (adjlist*)malloc(sizeof(struct adjlist_node));
  L->vert = w;
  L->cost = weight;
  if (G->adj[v] == NULL) {
    L->next = G->adj[v];
    G->adj[v] = L;  }
  else {
    adjlist *N;
    N = G->adj[v];
    if (L->vert < N->vert) {
      L->next = G->adj[v];
      G->adj[v] = L;
    } else {
      while (N->next) {
	if (L->vert < N->next->vert) {
	  break;
	}
	N = N->next;
      }
      L->next = N->next;
      N->next = L;
    }
  }
}


// A recursive function used by shortestPath. See below link for details
// http://www.geeksforgeeks.org/topological-sorting/
// modified version of DFS
void topologicalSortUtil(graph* G, int v, int visited[], StackD *stack) {
  // Mark the current node as visited
  visited[v] = 1;

  // Recursive procedure for all the vertices adjacent to this vertex
  adjlist *L = G->adj[v];
  while (L) {
    if (!visited[L->vert])
      topologicalSortUtil(G, L->vert, visited, stack);
    L = L->next;
  }

  // Push current vertex to stack which stores topological sort
  push(stack, v);
}

//Relax function: update lowest distance u->v
// u: vertex cost for outcoming edge
// v: vertex cost for incoming edge
// weightEdge: weight for edge u->v
void relax(int u, int v, int weightEdge, int *dist, int Restrict) {
  if (dist[v] > dist[u] + weightEdge && weightEdge <= Restrict)
    dist[v] = dist[u] + weightEdge;
}


// The function to find shortest paths from given vertex. It uses recursive
// topologicalSortUtil() to get topological sorting of given graph.
void shortestPath(graph* G, int s, int r) {
  StackD Stack;
  int dist[MAX];

  stackInit(&Stack);

  // Mark all the vertices as not visited
  int visited[MAX];
  int i;
  for (i = 0; i < G->size; i++)
    visited[i] = 0;

  //showStack(&Stack);

  // Call the recursive helper function to store Topological Sort
  // starting from all vertices one by one
  for (i = s; i < G->size; i++)
    if (visited[i] == 0)
      topologicalSortUtil(G, i, visited, &Stack);

  showStack(&Stack);

  // Initialize distances to all vertices as infinite and distance
  // to source as 0
  for (i = 0; i < G->size; i++)
    dist[i] = INF;
  dist[s] = 0;

  adjlist *L;

  // Process vertices in topological order
  while (stackEmpty(&Stack) == 0) {
    // Get the next vertex from topological order
    int u = pop(&Stack);
    L = G->adj[u];

    // Update distances of all adjacent vertices
    if (dist[u] != INF) {
      while (L) {
	// call relax function to update lowest distance
	relax(u, L->vert, L->cost, dist, r);
	L = L->next;
      }
    }
  }

  // Print the calculated shortest distances
//  printf("Following are shortest distances from source %d\n",s);
  for (i = 0; i < G->size; i++)
//    if (dist[i]==INF) printf("INF ");
{
    printf("%d ", dist[i]);
}

  printf("\n");
}


// Driver program to test above functions
int main()
{
int i, V, R, N , M, from, to, weight;
scanf("%d ",&V);
scanf("%d ",&R);
scanf("%d ",&N);
scanf("%d ",&M);
graph* g = initGraph(N);

for(i=0;i<=M;i++)
{
scanf("%d %d %d" , &from, &to, &weight);
  graphAddEdge(g, from, to, weight);
}
  shortestPath(g, V, R);


// Create a graph given in the above diagram.  Here vertex numbers are
// 0, 1, 2, 3, 4, 5 with following mappings:
// 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
//
//  graphAddEdge(g, 0, 2, 3);
//  graphAddEdge(g, 1, 3, 6);
//  graphAddEdge(g, 1, 2, 2);
//  graphAddEdge(g, 2, 4, 4);
//  graphAddEdge(g, 2, 5, 2);
//  graphAddEdge(g, 2, 3, 7);
//  graphAddEdge(g, 3, 4, -1);
//  graphAddEdge(g, 4, 5, -2);

  return 0;
}
