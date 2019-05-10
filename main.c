#include "graph.h"
#include<stdio.h>
#include<stdlib.h>

int main() {

	printf("\n\nTravelling Salesman Problem using Permutations:\n\n");
	int n, i, j;
	int *mincost=(int *)malloc(sizeof(int));
	printf("No of vertices:\n");
	scanf("%d",&n);
	int **a=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++) a[i]=(int*)malloc(sizeof(int)*n);
	printf("Enter the adjacency matrix:\n");
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
	int *ans=tsp_permutation(a,n,mincost);
	printf("Cost: %d\n",*mincost);
	printf("Path:\n");
	for(int i=0;i<n+1;i++) printf("%d ",ans[i]); printf("\n");
	for (i = 0; i < n; i++) free(a[i]);
	free(a); free(mincost);

	printf("\n\nDepth first search traversal:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	int** graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	int *trav=dfs(graph, n);
	printf("Traversal:\n");
	for (i = 0; i < n; i++) printf("%d ", trav[i]); printf("\n");
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);

	printf("\n\nBreadth first search traversal:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	trav=bfs(graph, n);
	printf("Traversal:\n");
	for (i = 0; i < n; i++) printf("%d ", trav[i]); printf("\n");
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);

	printf("\n\nWarshall's algorithm for Transitive Closure:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	transitive_closure_warshalls(graph, n);
	printf("The Transitive Closure is:\n");
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) printf("%d\t",graph[i][j]);
		printf("\n");
	}
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);

	printf("\n\nFloyd's algorithm for All Pairs Shortest Distances:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	all_pairs_shortest_path_distances_floyds(graph, n);
	printf("All Pairs Shortest Distance is:\n");
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) printf("%d\t",graph[i][j]);
		printf("\n");
	}
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);

	printf("\n\nTopological Sort using Depth First Search:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	int *sort=topological_sort_dfs(graph, n);
	printf("Topological Sort:\n");
	for (i = 0; i < n; i++) printf("%d ", sort[i]); printf("\n");
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);

	printf("\n\nTopological Sort using Source Removal:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	sort=topological_sort_source_removal(graph, n);
	printf("Topological Sort:\n");
	for (i = 0; i < n; i++) printf("%d ", sort[i]); printf("\n");
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);
	
	printf("\n\nPrim's Algorithm for Minimum Spanning Tree:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	minimum_spanning_tree_prims(graph,n); printf("\n");
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);

	printf("\n\nKruskal's Algorithm for Minimum Spanning Tree:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	minimum_spanning_tree_kruskals(graph,n); printf("\n");
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);

	printf("\n\nDijkstra's Algorithm for Source to All Destinations Shortest Paths:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	printf("Enter the source vertex:\n");
	int src; scanf("%d",&src);
	dijkstra(graph,n,src); printf("\n");
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);

	printf("\n\nHamiltonian Circuit using Backtracking:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	hamiltonian_circuit(graph,n); printf("\n");
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);

	printf("\n\nGraph Connecticity Check using Depth First Search:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	if(connected(graph,n)) printf("The Graph is Connected\n");
	else printf("Graph is disconnected\n");
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);

	printf("\n\nUndirected Graph Cycle Detection using Depth First Search:\n\n");
	printf("No of vertices:\n");
	scanf("%d", &n);
	graph = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) graph[i] = (int*)malloc(sizeof(int) * n);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
	if(cycle_undirected(graph,n)) printf("The Graph contains a cycle\n");
	else printf("Graph is acyclic\n");
	for (i = 0; i < n; i++) free(graph[i]);
	free(graph);

	return 0;
}