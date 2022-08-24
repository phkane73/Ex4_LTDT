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
	if(u==v && pG->A[u][v] == 1)
		pG->A[u][v] += 1;
	else if(u==v)
		pG->A[u][v] = 1;
	else{
		pG->A[u][v] += 1;
		pG->A[v][u] += 1;
	}
		
	pG->m++;
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
	
	for(u=1; u<=G.n; u++){
		for(v=1; v<=G.n; v++)
			printf("%d ", G.A[u][v]);
		printf("\n");
	}
	return 0;
}
