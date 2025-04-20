// Design and implement C program to find Minimum Cost Spanning Tree of
// a given connected undirected graph using Kruskal's algorithm.

#include <stdio.h>
#define INF 999

int cost[20][20], parent[20];
int n;

void inputCostMatrix() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    parent[j] = i;
}

void kruskalMST() {
    int edgeCount = 1, minCost = 0;

    printf("\nEdges in the Minimum Cost Spanning Tree:\n");

    while (edgeCount < n) {
        int min = INF, a = -1, b = -1, u, v;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        u = find(a);
        v = find(b);

        if (u != v) {
            printf("Edge %d\t(%d -> %d) = %d\n", edgeCount++, a, b, min);
            minCost += min;
            unionSets(u, v);
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum Cost = %d\n", minCost);
}

int main() {
    inputCostMatrix();

    for (int i = 0; i < n; i++)
        parent[i] = 0;

    kruskalMST();
    return 0;
}
