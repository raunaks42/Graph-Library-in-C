#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define min(x, y) x < y ? x : y


/* 
Travelling Salesman Problem by Permutations
Input: graph as adjacency matrix, dimension of matrix, pointer to cost result
Output: cost result in pointer, returns path
*/


int get_next_permutation(int *permutation, int n) {
	int i;
	int j;
	int k;
	int temp_int;
	int swaps;

	for(i = n-2; i >= 0; i--) {
		if(permutation[i] < permutation[i+1]) {
			break;
		}
	}
	if(i == -1) {
		return 0;
	}

	for(j = i+1; j < n; j++) {
		if(permutation[j] < permutation[i]) {
			break;
		}
	}
	j--;

	temp_int = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = temp_int;

	swaps = (n-1-i)/2;	
	for(k = 0; k < swaps; k++) {
		temp_int = permutation[i+1+k];
		permutation[i+1+k] = permutation[n-1-k];
		permutation[n-1-k] = temp_int;
	}
	return 1;
}

int *tsp_permutation(int** a, int n, int *minc)
{
	int cost,mincost,count,count1;
	mincost=9999999;
	int* permutation = (int *) malloc(n * sizeof(int));
	int *ans=(int *) malloc((n+1) * sizeof(int));
	for(int i = 0; i < n-1; i++) {
		permutation[i] = i+1;
	}

	do {
		count=count+1;
		cost=a[0][permutation[0]];
		cost=cost+a[permutation[n-2]][0];
		for(int i=0;i<=n-3;i++)
		{
			cost=cost+a[permutation[i]][permutation[i+1]];
		}
		if(mincost>cost)
		{
			mincost=cost;
			for(int i=0;i<n-1;i++)
			{
				ans[i+1]=permutation[i];
			}
			
		}
		
	} while (get_next_permutation(permutation, n-1));
	ans[0]=0; ans[n]=0;
	*minc=mincost;
    free(permutation);
	return ans;
}


/* 
Depth First Search Traversal
Input: graph as adjacency matrix, dimension of matrix
Output: returns dfs traversal order
*/


void DFS(int** graph, int* visited, int v, int n, int *trav, int *tind) {
	
	visited[v] = 1;
	trav[(*tind)++]=v;
	for (int i = 0; i < n; i++) if (graph[v][i] == 1 && visited[i] != 1) DFS(graph, visited, i, n, trav, tind);
}

int *dfs(int** graph, int n) {
	int* visited = (int*)malloc(sizeof(int) * n);
	int* trav= (int*)malloc(sizeof(int)*n);
	int* tind=(int*)malloc(sizeof(int));
	*tind=0;
	for (int i = 0; i < n; i++) visited[i] = 0;
	for (int i = 0; i < n; i++)
		if (!visited[i]) {
			DFS(graph, visited, i, n, trav, tind);
		}
	free(visited);
	return trav;
}


/* 
Breadth First Search Traversal
Input: graph as adjacency matrix, dimension of matrix
Output: returns bfs traversal order
*/


void BFS(int** graph, int* visited, int v, int n, int *trav, int *tind) {
	int* q = (int*)malloc(sizeof(int) * n);
	int r = 0;
	
	visited[v] = 1;
	trav[(*tind)++]=v;
	q[r++] = v;
	while (r > 0) {
		for (int j = 0; j < n; j++)
			if (graph[q[0]][j] == 1 && visited[j] != 1) {
				visited[j] = 1;
				trav[(*tind)++]=j;
				q[r++] = j;
			}
		for (int m = 0; m < r; m++) q[m] = q[m + 1];
		r--;
	}
	free(q);
}

int *bfs(int** graph, int n) {
	int* visited = (int*)malloc(sizeof(int) * n);
	int* trav= (int*)malloc(sizeof(int)*n);
	int* tind=(int*)malloc(sizeof(int));
	*tind=0;
	for (int i = 0; i < n; i++) visited[i] = 0;
	for (int i = 0; i < n; i++)
		if (!visited[i]) {
			BFS(graph, visited, i, n, trav, tind);
		}
	free(visited);
	return trav;
}


/* 
Warshall's Algorithm for Transitive Closure
Input: graph as adjacency matrix, dimension of matrix
Output: modified graph
*/


void transitive_closure_warshalls(int** R, int n) {
	int i,j,k;
	for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++) R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
}


/* 
Floyd's Algorithm for All Pairs Shortest Distance
Input: graph as adjacency matrix, dimension of matrix
Output: modified graph
*/


void all_pairs_shortest_path_distances_floyds(int** D, int n) {
	int i,j,k;
	for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}


/* 
Topological Sort using DFS
Input: graph as adjacency matrix, dimension of matrix
Output: return topological sort order
*/


void TOPO_DFS(int** graph, int* visited, int v, int n, int *toposort, int *topoindex) {
	visited[v] = 1;
	for (int i = 0; i < n; i++) if (graph[v][i] == 1 && visited[i] != 1) {
		TOPO_DFS(graph, visited, i, n, toposort, topoindex);
	}
	toposort[(*topoindex)++]=v;
}

int *topological_sort_dfs(int** graph, int n) {
	int* visited = (int*)malloc(sizeof(int) * n);
	int* tsa = (int*)malloc(sizeof(int) * n);
	int* toposort = (int*)malloc(sizeof(int) * n);
	int* topoindex = (int*)malloc(sizeof(int));
	*topoindex=0;
	int i, j;
	for (i = 0; i < n; i++) visited[i] = 0;
	for (i = 0; i < n; i++)
		if (!visited[i]) {
			TOPO_DFS(graph, visited, i, n, toposort, topoindex);
		}
	for (i = n-1, j=0; i >= 0 && j<n; i--, j++) tsa[j]=toposort[i];
	free(visited); free(toposort); free(topoindex);
	return tsa;
}


/* 
Topological Sort using Source Removal
Input: graph as adjacency matrix, dimension of matrix
Output: return topological sort order
*/


int *topological_sort_source_removal(int **graph, int n) {
	int* tsa = (int*)malloc(sizeof(int) * n);
	int tind=0;
	int i,j,k,source=1;
	for(j=0;j<n;j++, source=1) {
		for(k=0;k<n && source;k++) if(graph[k][j]) source=0;
		if(source) {
			tsa[tind++]=j;
			for(k=0;k<n;k++) graph[j][k]=0;
		}
	}
	return tsa;
} 


/* 
Prim's Algorithm for Minimum Spanning Tree
Input: graph as adjacency matrix, dimension of matrix
Output: prints mst
*/


int minKey(int key[], bool mstSet[], int n) { 
	int min = INT_MAX, min_index; 
	for (int v = 0; v < n; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 
	return min_index; 
} 

int printMST(int parent[], int n, int **graph) { 
	printf("Edge \tWeight\n"); 
	for (int i = 1; i < n; i++) 
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 

void minimum_spanning_tree_prims(int **graph, int n) { 
	int parent[n]; 
	int key[n]; 
	bool mstSet[n]; 
	for (int i = 0; i < n; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 
	key[0] = 0;	 
	parent[0] = -1;
	for (int count = 0; count < n-1; count++) { 
		int u = minKey(key, mstSet, n); 
		mstSet[u] = true; 
		for (int v = 0; v < n; v++) 
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 
	printf("Minimum Spanning Tree by Prim's Algorithm:\n");
	printMST(parent, n, graph); 
} 


/* 
Kruskal's Algorithm for Minimum Spanning Tree
Input: graph as adjacency matrix, dimension of matrix
Output: prints mst
*/


int find(int i, int *parent) 
{ 
	while (parent[i] != i) 
		i = parent[i]; 
	return i; 
} 
 
void union1(int i, int j, int *parent) 
{ 
	int a = find(i, parent); 
	int b = find(j, parent); 
	parent[a] = b; 
} 

void minimum_spanning_tree_kruskals(int **cost, int n) 
{ 
	int parent[n];
	for (int i = 0; i < n; i++) 
		parent[i] = i; 
	int edge_count = 0;
	printf("Minimum Spanning Tree by Kruskal's Algorithm:\n");
	printf("Edge\tWeight\n"); 
	while (edge_count < n - 1) { 
		int min = INT_MAX, a = -1, b = -1; 
		for (int i = 0; i < n; i++) { 
			for (int j = 0; j < n; j++) { 
				if (find(i, parent) != find(j, parent) && cost[i][j] < min) { 
					min = cost[i][j]; 
					a = i; 
					b = j; 
				} 
			} 
		} 
		union1(a, b, parent); 
		printf("%d - %d\t%d\n", a, b, min);
		edge_count++; 
	}  
} 


/* 
Dijkstra's Algorithm for Source to All Destinations Shortest Path
Input: graph as adjacency matrix, dimension of matrix, starting node
Output: prints shortest distances and paths
*/


void dijkstra(int **G, int n, int startnode)
{
	int cost[n][n], distance[n], pred[n];
	int visited[n], count, mindistance, nextnode, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=INT_MAX;
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=INT_MAX;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
	printf("Shortest Path to all vertices from %d by Dijkstra's Algorithm:",startnode);
	for(i=0;i < n;i++) {
		if(i!=startnode)
		{
			printf("Distance of %d = %d\n", i, distance[i]);
			printf("Path = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=startnode);
		}
		printf("\n");
	}
}


/* 
Hamiltonian Circuit using BackTracking
Input: graph as adjacency matrix, dimension of matrix
Output: prints hamiltonian circuit
*/


bool isSafe(int v, int **graph, int path[], int pos) 
{ 
	if (graph [ path[pos-1] ][ v ] == 0) 
		return false; 
	for (int i = 0; i < pos; i++) 
		if (path[i] == v) 
			return false; 
	return true; 
} 

bool hamCycleUtil(int **graph, int path[], int pos, int n) 
{ 
	if (pos == n) 
	{ 
		if ( graph[ path[pos-1] ][ path[0] ] == 1 ) 
		return true; 
		else
		return false; 
	} 
	for (int v = 1; v < n; v++) 
	{ 
		if (isSafe(v, graph, path, pos)) 
		{ 
			path[pos] = v; 
			if (hamCycleUtil (graph, path, pos+1, n) == true) 
				return true; 
			path[pos] = -1; 
		} 
	} 
	return false; 
} 
void printSolution(int path[], int n) 
{ 
	printf ("Solution Exists:"
			" Following is one Hamiltonian Cycle \n"); 
	for (int i = 0; i < n; i++) 
		printf("%d->", path[i]); 
	printf("%d\n", path[0]);  
} 

void hamiltonian_circuit(int **graph, int n) 
{ 
	int path[n];
	for (int i = 0; i < n; i++) 
		path[i] = -1; 
	path[0] = 0; 
	printf("Hamiltonian Circuit by Backtracking:\n");
	if ( hamCycleUtil(graph, path, 1, n) == false ) 
	{ 
		printf("Solution does not exist"); 
		return;
	} 
	printSolution(path,n);
} 


/* 
Check Graph Connectivity using DFS
Input: graph as adjacency matrix, dimension of matrix
Output: returns 1 if connected, 0 if not
*/


void CONNDFS(int** graph, int* visited, int v, int n) {
	
	visited[v] = 1;
	for (int i = 0; i < n; i++) if (graph[v][i] == 1 && visited[i] != 1) CONNDFS(graph, visited, i, n);
}

int connected(int** graph, int n) {
	int count=0;
	int* visited = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) visited[i] = 0;
	for (int i = 0; i < n; i++)
		if (!visited[i]) {
			CONNDFS(graph, visited, i, n);
			count++;
		}
	free(visited);
	if(count>1) return 0;
	return 1;
}


/* 
Undirected Graph Cycle Detection using DFS
Input: graph as adjacency matrix, dimension of matrix
Output: returns 1 if cycle detected, 0 if not
*/


int CYCLEDFS(int** graph, int* visited, int v, int n, int prev) {
	int cycle=0;
	visited[v] = 1;
	for (int i = 0; i < n; i++) {
		if (graph[v][i] == 1 && visited[i] != 1) cycle|=CYCLEDFS(graph, visited, i, n, v);
		else if (graph[v][i]==1 && i!=prev && visited[i]==1) return 1; 
	}
	return cycle;
}

int cycle_undirected(int** graph, int n) {
	int cycle=0;
	int* visited = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) visited[i] = 0;
	for (int i = 0; i < n; i++)
		if (!visited[i]) {
			cycle|=CYCLEDFS(graph, visited, i, n, -1);
		}
	free(visited);
	return cycle;
}