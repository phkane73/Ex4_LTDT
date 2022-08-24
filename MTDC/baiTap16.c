#include<stdio.h>
#define MAX_N 100
#define MAX_M 500

typedef struct{
	int n, m;
	int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *pG, int n, int m){
	int u, e;
	pG->n = n;
	pG->m = m;
	for(u=1; u<=n; u++)
		for(e=1; e<=m; e++)
			pG->A[u][e] = 0;
	
}

void add_edge(Graph *pG, int e, int u, int v){
	pG->A[u][e] = 1;
	pG->A[v][e] = 1;
}

int adjacent(Graph *pG, int u, int v){
	int e;
	for(e=1; e<=pG->m; e++)
		if(pG->A[u][e] == 1 && pG->A[v][e] == 1)
			return 1;
	return 0;
}

int degree(Graph *pG, int u){
	int e, deg_u = 0;
	for(e=1; e<=pG->m; e++)
		if(pG->A[u][e] == 1)
			deg_u++;
	return deg_u;
}

void neighbours(Graph *pG, int u){
	int v;
	for(v=1; v<=pG->n; v++)
		if(adjacent(pG, u, v) != 0)
			printf("%d ", v);
	printf("\n");
}


int main(){
	Graph G;
	int n, m, u, v, e;
	freopen("data.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n, m);
	for(e=0; e<m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, e, u, v);
	}
	for(e=1; e<=G.n; e++){
		printf("neighbours(%d) = ",e);
		neighbours(&G, e);
	}
	for(e=1; e<=G.n; e++){
		printf("deg(%d) = %d\n",e, degree(&G, e));	
	}
	return 0;
}







