// Design and implement C/C++ Program to obtain the Topological ordering of
// vertices in a given digraph.

#include <stdio.h>
#define MAX 100

void topologicalSort(int graph[MAX][MAX], int n, int indegree[MAX]);

int main() {
    int graph[MAX][MAX], indegree[MAX] = {0};
    int i, j, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    printf("\nTopological Sort Order:\n");
    topologicalSort(graph, n, indegree);

    return 0;
}

void topologicalSort(int graph[MAX][MAX], int n, int indegree[MAX]) {
    int count = 0;

    for (int k = 0; k < n; k++) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                printf("%d ", i + 1); 
                indegree[i] = -1;
                count++;
                found = 1;

                for (int j = 0; j < n; j++) {
                    if (graph[i][j] == 1)
                        indegree[j]--;
                }
                break;
            }
        }

        if (!found) {
            printf("\nCycle detected! Topological sort not possible.\n");
            return;
        }
    }

    if (count != n) {
        printf("\nCycle detected! Topological sort not complete.\n");
    }
}
