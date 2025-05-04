// Design and implement C program to sort a given set of 'n' integer elements using Merge Sort method and compute its time complexity. Run the program for varied values of n > 5000 and record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500000

int temp[MAX_SIZE];

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (int t = low; t <= high; t++)
        a[t] = temp[t];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void generateRandomInput(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000;
    }
}

void displayArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %5d\n", a[i]);
    }
}

int main() {
    int a[MAX_SIZE], n, choice;
    clock_t start, end;
    double timeTaken;

    srand((unsigned int)time(NULL));

    while (1) {
        printf("\n1. Plot the Graph\n2. Perform MergeSort\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                FILE *fp = fopen("mergePlot.dat", "w");
                if (fp == NULL) {
                    perror("Error opening file");
                    exit(EXIT_FAILURE);
                }

                for (int size = 5000; size <= 100000; size += 1000) {
                    generateRandomInput(a, size);
                    start = clock();
                    mergeSort(a, 0, size - 1);
                    end = clock();
                    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
                    fprintf(fp, "%d\t%lf\n", size, timeTaken);
                }

                fclose(fp);
                printf("\nData file <mergePlot.dat> generated. Use a plotting utility to visualize it.\n");
                break;
            }

            case 2: {
                printf("Enter the number of elements to sort: ");
                scanf("%d", &n);
                if (n <= 0 || n > MAX_SIZE) {
                    printf("Invalid size! Please enter a value between 1 and %d.\n", MAX_SIZE);
                    break;
                }

                generateRandomInput(a, n);
                printf("\nUnsorted Array:\n");
                displayArray(a, n);

                start = clock();
                mergeSort(a, 0, n - 1);
                end = clock();

                printf("\nSorted Array:\n");
                displayArray(a, n);

                timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
                printf("\nTime complexity of the algorithm = %lf seconds\n", timeTaken);
                break;
            }

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
