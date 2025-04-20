// Design and implement C program to solve discrete Knapsack 
// and continuous Knapsack problems using greedy approximation method.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int profit;
    int weight;
    float ratio;     // profit-to-weight ratio
    float fraction;  // fraction of item taken
} Item;

Item* items;
int n;           // number of items
float capacity;  // total knapsack capacity

void inputItems() {
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    items = (Item*)calloc(n, sizeof(Item));

    for (int i = 0; i < n; i++) {
        printf("Item %d Profit: ", i + 1);
        scanf("%d", &items[i].profit);
        printf("Item %d Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
        items[i].fraction = 0;
    }
}

void sortItemsByRatio() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

void displaySolution(const char* title, float totalProfit) {
    printf("\n%s\n", title);
    printf("Item\tWeight\tProfit\tFraction\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%.2f\n", i + 1, items[i].weight, items[i].profit, items[i].fraction);
    }
    printf("\nTotal Profit: %.2f\n", totalProfit);
}

void discreteKnapsack() {
    float remaining = capacity, totalProfit = 0;
    for (int i = 0; i < n; i++) {
        items[i].fraction = 0;
        if (items[i].weight <= remaining) {
            items[i].fraction = 1;
            remaining -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            break;
        }
    }
    displaySolution("Discrete Knapsack Solution", totalProfit);
}

void continuousKnapsack() {
    float remaining = capacity, totalProfit = 0;
    for (int i = 0; i < n; i++) items[i].fraction = 0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remaining) {
            items[i].fraction = 1;
            remaining -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            items[i].fraction = remaining / items[i].weight;
            totalProfit += items[i].profit * items[i].fraction;
            break;
        }
        if (remaining == 0) break;
    }
    displaySolution("Continuous Knapsack Solution", totalProfit);
}

int main() {
    inputItems();
    sortItemsByRatio();
    discreteKnapsack();
    continuousKnapsack();
    free(items);
    return 0;
}
