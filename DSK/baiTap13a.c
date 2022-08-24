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

void ht_graph(Graph *pG){
	int u,v;
	for(u=1; u<=pG->n; u++){
		for(v=1; v<=pG->n; v++)
			printf("%d ", pG->A[u][v]);
		printf("\n");
	}		
}

int main(){
	Graph G;
	int n;
	scanf("%d", &n);
	init_graph(&G,n);
	
	int u,v;
	for(u=1; u<=G.n; u++){
		for(v=1; v<=G.n; v++)
			scanf("%d", &G.A[u][v]);
//		printf("\n");
	}
//	ht_graph(&G);
	int k=0;
	int i;
	for(u=1; u<=G.n; u++){
		for(v=u; v<=G.n; v++){
			if(G.A[u][v] != 0){
				if(G.A[u][v] == 1)
					printf("%d %d\n", u, v);
				else if (G.A[u][v] >1){
					k = G.A[u][v];
					for(i=1; i<=k; i++)
					printf("%d %d\n", u, v);
				}	
			}
				
		}
	}
	return 0;
}


