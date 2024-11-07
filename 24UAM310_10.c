#include <stdio.h>

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

void Display(int matrix[MAX][MAX], int n) {
    int i, j;
    printf("\nThe matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void findPathMatrix(int graph[MAX][MAX], int path[MAX][MAX], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 0 && i != j)
                path[i][j] = -1;
            else
                path[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (path[i][k] + path[k][j] < path[i][j]) {
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (path[i][j] == -1) {
                path[i][j] = 0;
            } else {
                path[i][j] = 1; 
            }
        }
    }
}

int main() {
    int n, i, j;
    int graph[MAX][MAX], path[MAX][MAX];
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    CreateGraph(graph, n);
    printf("\nAdjacency Matrix:");
    Display(graph, n);
    findPathMatrix(graph, path, n);
    printf("\nPath Matrix:");
    Display(path, n);
    return 0;
}