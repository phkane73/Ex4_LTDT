#include<stdio.h>
#define MAX_N 100
#define MAX_ELEMENTS 100

typedef int ElementType;
typedef struct{
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

void make_null(List *pL){
	pL->size = 0;
}

void push_back(List *pL, ElementType x){
	pL->data[pL->size] = x;
	pL->size++;
}

ElementType element_at(List *pL, int i){
	return pL->data[i-1];
}

int count_list(List *pL){
	return pL->size;
}

typedef struct{
	int n;
	List adj[MAX_N];
}Graph;

void init_graph(Graph *pG, int n){
	int u;
	pG->n = n;
	for(u=1; u<=n; u++)
		make_null(&pG->adj[u]);
}

void add_edge(Graph *pG, int u, int v){
	push_back(&pG->adj[u], v);
	push_back(&pG->adj[v], u);
}

int adjacent(Graph *pG, int u, int v){
	int j;
	for(j=1; j<=pG->adj[u].size; j++)
		if(element_at(&pG->adj[u], j) == v)
			return 1;
	return 0;
}

int degree(Graph *pG, int u){
	return pG->adj[u].size;
}

void neighbours(Graph *pG, int u){
	int j;
	for(j=1; j<=pG->n; j++){
		if(adjacent(pG, u, j) != 0)
			printf("%d ", j);
	}
	printf("\n");
}

int main(){
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(e=0; e<m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for(e=1; e<=G.n; e++){
		printf("deg(%d) = %d\n", e, degree(&G,e));
	}
	for(e=1; e<=G.n; e++){
		printf("neighbours(%d) =", e);
		 neighbours(&G,e);
	}
	return 0;
}








