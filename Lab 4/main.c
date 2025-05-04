// Design and implement C program to find shortest paths from a given vertex 
// in a weighted connected graph to other vertices using Dijkstra's algorithm.

#include <stdio.h>
#define INF 999

void dijkstrasAlgorithm(int graph[10][10], int n, int source);

int main() {
    int graph[10][10], n, source;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (%dx%d):\n", n, n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the source node (1 to %d): ", n);
    scanf("%d", &source);

    dijkstrasAlgorithm(graph, n, source);

    return 0;
}

void dijkstrasAlgorithm(int graph[10][10], int n, int source) {
    int dist[10], visited[10] = {0}, parent[10];
    
    for (int i = 1; i <= n; i++) {
        dist[i] = graph[source][i];
        parent[i] = source;
    }

    visited[source] = 1;

    for (int count = 1; count < n; count++) {
        int min = INF, u = -1;

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nShortest Paths from source node %d:\n", source);
    for (int i = 1; i <= n; i++) {
        if (i == source) continue;
        printf("To %d (Cost: %d): ", i, dist[i]);

        int path[10], idx = 0, j = i;
        while (j != source) {
            path[idx++] = j;
            j = parent[j];
        }
        path[idx] = source;

        for (int k = idx; k >= 0; k--) {
            printf("%d", path[k]);
            if (k > 0) printf(" -> ");
        }
        printf("\n");
    }
}
