// Design and implement C/C++ Program to solve All-Pairs Shortest Paths problem
// using Floyd’s algorithm.

#include <stdio.h>
#define MAX 100
#define INF 999

void floydWarshall(int graph[MAX][MAX], int n);

int main() {
    int n, i, j;
    int graph[MAX][MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, n);
    return 0;
}

void floydWarshall(int graph[MAX][MAX], int n) {
    int dist[MAX][MAX], i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = (dist[i][j] < dist[i][k] + dist[k][j]) 
                                 ? dist[i][j] : (dist[i][k] + dist[k][j]);
            }
        }
    }

    printf("\nThe shortest distance matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}
