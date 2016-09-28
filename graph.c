#include <stdio.h>
#include <stdlib.h>

struct adjNode{
	int index;
	int pathLength;
	struct adjNode *next;
};

struct adjList{
	struct adjNode *head;
};
struct graph{
	int numberOFVertex;
	struct adjList *array;
};

typedef struct adjNode adjNode;
typedef struct adjList adjList;
typedef struct graph graph; 

#define new_adjNode (adjNode *)malloc(sizeof(adjNode))


graph* createGraph(int n){
	graph *g = (graph *)malloc(sizeof(graph));

	g->numberOFVertex = n;
	g->array = (adjList *)malloc(n*sizeof(adjList));

	int i=0;
	for(i=0;i<n;i++){
		g->array[i].head = NULL;
	}
	return g;
}

adjNode* newadjNode(int x,int l){
	adjNode *temp = new_adjNode;
	temp->index = x;
	temp->pathLength = l;
	temp->next = NULL;
	return temp;
}

void addEdge(graph *g,int x,int y,int l){

	adjNode *temp = newadjNode(x,l);
	temp->next = g->array[y].head;
	g->array[y].head = temp;

	temp = newadjNode(y,l);
	temp->next = g->array[x].head;
	g->array[x].head = temp;
}

void printAdjList(graph *g){
	int i=0;
	for(i=0;i<g->numberOFVertex;i++){
		adjNode *curr = g->array[i].head;
		printf("%d  ->  ",(i+1));
		while(curr!=NULL){
			printf(" (%d,%d) ",curr->index+1,curr->pathLength);
			curr = curr->next;
		}
		printf("\n");
	}

}

int main(){
	int n,m;				// n-> Number of Nodes		m-> Number of Edges
	scanf("%d %d",&n,&m);

	graph *g = createGraph(n);
	
	int x,y;
	while(m--){
		scanf("%d %d",&x,&y);
		addEdge(g,x-1,y-1,1);
	}
	printAdjList(g);
	return 0;
}
/*

Input:-
5 7
1 2
2 3
3 4
4 5
1 5
3 2
1 4
*/