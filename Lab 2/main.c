// Design and implement C program to find Minimum Cost Spanning Tree of a given 
// connected undirected graph using Prim's algorithm.

#include <stdio.h>
#define INF 999

int cost[20][20], visited[20];
int n, source;

void inputCostMatrix() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
}

void primsMST() {
    int minCost = 0, edgeCount = 1;
    visited[source] = 1;

    printf("\nMinimum Cost Spanning Tree:\n");

    while (edgeCount < n) {
        int min = INF, a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) continue;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("Edge %d\t(%d -> %d) = %d\n", edgeCount++, a+1, b+1, min);
            minCost += min;
            visited[b] = 1;
            cost[a][b] = cost[b][a] = INF;
        }
    }

    printf("\nMinimum Cost = %d\n", minCost);
}

int main() {
    inputCostMatrix();

    printf("Enter the root node (1 to %d): ", n);
    scanf("%d", &source);
    source--; // Adjust for 0-based index

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    primsMST();
    return 0;
}
