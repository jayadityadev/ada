// Design and implement C/C++ Program to find the transitive closure using
// Warshal’s algorithm.

#include <stdio.h>
#define MAX 100

void warshallsAlgorithm(int graph[MAX][MAX], int n);

int main() {
    int graph[MAX][MAX], n, i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the Adjacency Matrix (0 or 1):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    warshallsAlgorithm(graph, n);

    printf("\nThe Transitive Closure (Path Matrix) is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    return 0;
}

void warshallsAlgorithm(int graph[MAX][MAX], int n) {
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
}
