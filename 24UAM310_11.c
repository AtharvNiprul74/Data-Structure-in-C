#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void CreateGraph(int graph[MAX][MAX], int n) {
    int i, j;
    printf("Enter the adjacency matrix of the graph (use 0 for no edge, 1 for an edge):");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}
void DepthSearch(int graph[MAX][MAX], int visited[MAX], int vertex, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DepthSearch(graph, visited, i, n);
        }
    }
}
int main() {
    int n;
    int graph[MAX][MAX], visited[MAX] = {0};
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    CreateGraph(graph, n);
    printf("\nDepth First Traversal (starting from vertex 0): ");
    DepthSearch(graph, visited, 0, n);  
    printf("\n");
    return 0;
}