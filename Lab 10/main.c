// Design and implement C program to sort a given set of 'n' integer elements using Quick Sort method and compute its time complexity. Run the program for varied values of n > 5000 and record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500000

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition the array using Lomuto scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high + 1;

    do {
        do { i++; } while (i <= high && arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i < j) swap(&arr[i], &arr[j]);
    } while (i < j);

    swap(&arr[low], &arr[j]);
    return j;
}

// QuickSort implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Generate random array input
void generateRandomInput(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

// Display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d\n", arr[i]);
    }
}

int main() {
    int arr[MAX_SIZE], n, choice;
    clock_t start, end;
    double timeTaken;

    srand((unsigned int)time(NULL));  // Seed RNG

    while (1) {
        printf("\n1. Plot the Graph\n2. Perform QuickSort\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                FILE *file = fopen("qPlot.dat", "w");
                if (file == NULL) {
                    perror("Error opening file");
                    exit(EXIT_FAILURE);
                }

                for (int size = 5000; size <= 50000; size += 1000) {
                    generateRandomInput(arr, size);
                    start = clock();
                    quickSort(arr, 0, size - 1);
                    end = clock();
                    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
                    fprintf(file, "%d\t%lf\n", size, timeTaken);
                }

                fclose(file);
                printf("\nData file <qPlot.dat> generated. Use a plotting utility to view the graph.\n");
                break;
            }

            case 2: {
                printf("Enter the number of elements to sort: ");
                scanf("%d", &n);
                if (n > MAX_SIZE || n <= 0) {
                    printf("Invalid size! Please enter a value between 1 and %d.\n", MAX_SIZE);
                    break;
                }

                generateRandomInput(arr, n);
                printf("\nUnsorted Array:\n");
                displayArray(arr, n);

                // start = clock();
                quickSort(arr, 0, n - 1);
                // end = clock();

                printf("\nSorted Array:\n");
                displayArray(arr, n);

                // timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
                // printf("\nTime complexity of the algorithm = %lf seconds\n", timeTaken);
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
