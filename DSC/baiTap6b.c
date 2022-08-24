#include<stdio.h>
#define MAX_M 500
typedef struct{
	int u,v;
}Edge;

typedef struct{
	int n,m;
	Edge edges[MAX_M];
}Graph;

void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int degree(Graph *pG, int u){
	int e, deg_u = 0;
	for(e=0; e<=pG->m; e++){
		if(pG->edges[e].u == u)
			deg_u++;
		if(pG->edges[e].v == u)
			deg_u++;
	}
	return deg_u;
}

int adjacent(Graph *pG, int u, int v){
	int e;
	for(e=0; e<=pG->m; e++)
		if(pG->edges[e].u == u && pG->edges[e].v == v)
			return 1;
	return 0;
}

void neighbours(Graph *pG, int u){
	int e;
	for(e=1; e<=pG->n; e++)
		if(adjacent(pG, u, e)!=0)
			printf("%d ", e);
	printf("\n");
}


int main(){
	Graph G;
	int n, m, u, v, e;
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(e=0; e<m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	for(e=1; e<=n; e++){
		printf("neighbours(%d) = ", e);
		neighbours(&G, e);
	}
	return 0;
}
