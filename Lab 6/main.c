// Design and implement C/C++ Program to solve 0/1 Knapsack problem using Dynamic Programming method.

#include <stdio.h>
#define MAX 100

int value[MAX][MAX];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int n, int m, int cost[], int weight[]) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                value[i][j] = 0;
            else if (weight[i] <= j)
                value[i][j] = max(value[i-1][j], cost[i] + value[i-1][j - weight[i]]);
            else
                value[i][j] = value[i-1][j];
        }
    }
    return value[n][m];
}

void findSolution(int n, int m, int weight[]) {
    int i = n, j = m;
    int x[MAX] = {0};

    while (i > 0 && j > 0) {
        if (value[i][j] != value[i-1][j]) {
            x[i] = 1;
            j -= weight[i];
        }
        i--;
    }

    printf("Items selected (by index): ");
    for (i = 1; i <= n; i++) {
        if (x[i])
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n, m, i, j;
    int cost[MAX], weight[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of each item: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter the profits of each item: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &cost[i]);

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &m);

    int optiVal = knapsack(n, m, cost, weight);

    printf("\nDynamic Programming Table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++)
            printf("%d\t", value[i][j]);
        printf("\n");
    }

    printf("\nThe optimal solution value is: %d\n", optiVal);

    findSolution(n, m, weight);

    return 0;
}
