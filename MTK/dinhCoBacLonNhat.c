#include<stdio.h>
#define MAX_N 100

typedef struct{
	int n, m;
	int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *pG, int n){
	int u,v;
	pG->n = n;
	pG->m = 0;
	for(u=1; u<=n; u++)
		for(v=1; v<=n; v++)
			pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
	pG->A[u][v] = 1;
	pG->A[v][u] = 1;
	pG->m++;
}

int degree(Graph *pG, int u){
	int v;
	int deg_u = 0;
	for(v=1; v<=pG->n; v++)
		deg_u += pG->A[u][v];
	return deg_u +pG->A[u][u];
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
	int max =0;
	for(u=1; u<=G.n; u++){
		if(degree(&G, u) >max)
			max = degree(&G, u);
	}
	
	for(u=1; u<=G.n; u++){
		if(degree(&G, u) == max)
			printf("%d %d", u , max);
	}
	return 0;
}
