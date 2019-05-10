#include<stdbool.h>


/* 
Travelling Salesman Problem by Permutations
Input: graph as adjacency matrix, dimension of matrix, pointer to cost result
Output: cost result in pointer, returns path
*/
int get_next_permutation(int *permutation, int n);
int *tsp_permutation(int** a, int n, int *minc);


/* 
Depth First Search Traversal
Input: graph as adjacency matrix, dimension of matrix
Output: returns dfs traversal order
*/
void DFS(int** graph, int* visited, int v, int n, int *trav, int *tind);
int *dfs(int** graph, int n);


/* 
Breadth First Search Traversal
Input: graph as adjacency matrix, dimension of matrix
Output: returns bfs traversal order
*/
void BFS(int** graph, int* visited, int v, int n, int *trav, int *tind);
int *bfs(int** graph, int n);


/* 
Warshall's Algorithm for Transitive Closure
Input: graph as adjacency matrix, dimension of matrix
Output: modified graph
*/
void transitive_closure_warshalls(int** R, int n);


/* 
Floyd's Algorithm for All Pairs Shortest Distance
Input: graph as adjacency matrix, dimension of matrix
Output: modified graph
*/
void all_pairs_shortest_path_distances_floyds(int** D, int n);


/* 
Topological Sort using DFS
Input: graph as adjacency matrix, dimension of matrix
Output: return topological sort order
*/
void TOPO_DFS(int** graph, int* visited, int v, int n, int *toposort, int *topoindex);
int *topological_sort_dfs(int** graph, int n);


/* 
Topological Sort using Source Removal
Input: graph as adjacency matrix, dimension of matrix
Output: return topological sort order
*/
int *topological_sort_source_removal(int **graph, int n);


/* 
Prim's Algorithm for Minimum Spanning Tree
Input: graph as adjacency matrix, dimension of matrix
Output: prints mst
*/
int minKey(int key[], bool mstSet[], int n);
int printMST(int parent[], int n, int **graph);
void minimum_spanning_tree_prims(int **graph, int n);


/* 
Kruskal's Algorithm for Minimum Spanning Tree
Input: graph as adjacency matrix, dimension of matrix
Output: prints mst
*/
int find(int i, int *parent);
void union1(int i, int j, int *parent);
void minimum_spanning_tree_kruskals(int **cost, int n);


/* 
Dijkstra's Algorithm for Source to All Destinations Shortest Path
Input: graph as adjacency matrix, dimension of matrix, starting node
Output: prints shortest distances and paths
*/
void dijkstra(int **G, int n, int startnode);


/* 
Hamiltonian Circuit using BackTracking
Input: graph as adjacency matrix, dimension of matrix
Output: prints hamiltonian circuit
*/
bool isSafe(int v, int **graph, int path[], int pos);
bool hamCycleUtil(int **graph, int path[], int pos, int n);
void printSolution(int path[], int n);
void hamiltonian_circuit(int **graph, int n);


/* 
Check Graph Connectivity using DFS
Input: graph as adjacency matrix, dimension of matrix
Output: returns 1 if connected, 0 if not
*/
void CONNDFS(int** graph, int* visited, int v, int n);
int connected(int** graph, int n);


/* 
Undirected Graph Cycle Detection using DFS
Input: graph as adjacency matrix, dimension of matrix
Output: returns 1 if cycle detected, 0 if not
*/
int CYCLEDFS(int** graph, int* visited, int v, int n, int prev);
int cycle_undirected(int** graph, int n);