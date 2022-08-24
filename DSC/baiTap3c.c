#include<stdio.h>
#define MAX_M 500
typedef struct{
	int u,v;
}Edge;

typedef struct{
	int n,m;
	Edge edges[MAX_M];
}Graph;

//Dinh nghia ham init_graph(Graph *pG, int n)
void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
}
//Kiem tra cung u,v co trong mang chua
int kt_edge(Graph *pG, int u, int v){
	int i;
	for(i=0; i<=pG->m; i++){
		if(pG->edges[i].u == u && pG->edges[i].v == v)
			return 0;
	}
	return 1;
}
//Dinh nghia ham add_edge(Graph *pG, int u, int v)
void add_edge(Graph *pG, int u, int v){
	int count = 0;
	int i;
	for(i=0; i<=pG->m; i++){
		if(pG->edges[i].u == u && pG->edges[i].v == v)
			count = 1;
		else if (pG->edges[i].u == v && pG->edges[i].v == u)
			count = 1;
	}
	if(count==0){
		pG->edges[pG->m].u = u;
		pG->edges[pG->m].v = v;
		pG->m++;	
	}			
}					


int main(){
	Graph G;
	init_graph(&G, 4);
	add_edge(&G, 1, 2);
	add_edge(&G, 3, 4);
	add_edge(&G, 1, 2);
	add_edge(&G, 2, 1);
	printf("n = %d, m = %d\n", G.n, G.m);
	int e;
	for(e=0; e<G.m; e++){
		printf("%d %d\n", G.edges[e].u, G.edges[e].v);
	}
	return 0;
}




