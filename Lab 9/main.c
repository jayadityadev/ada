// Design and implement C program to sort a given set of 'n' 
// integer elements using Selection Sort method and compute its 
// time complexity. Run the program for varied values of 
// n > 5000 and record the time taken to sort. Plot a graph of 
// the time taken versus n. The elements can be read from a file or 
// can be generated using the random number generator.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500000

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to generate random input array
void generateRandomInput(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d\n", arr[i]);
    }
}

int main() {
    int array[MAX_SIZE];
    int numElements, choice;
    FILE *file;
    clock_t start, end;
    double timeTaken;

    srand((unsigned int)time(NULL));  // Seed RNG

    while (1) {
        printf("\n1. Plot the Graph\n2. Perform Selection Sort\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                file = fopen("sPlot.dat", "w");
                if (file == NULL) {
                    perror("Error opening file");
                    exit(EXIT_FAILURE);
                }

                for (int size = 5000; size <= 50000; size += 1000) {
                    generateRandomInput(array, size);
                    start = clock();
                    selectionSort(array, size);
                    end = clock();
                    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
                    fprintf(file, "%d\t%lf\n", size, timeTaken);
                }

                fclose(file);
                printf("\nData file <sPlot.dat> generated. Use a plotting utility to view the graph.\n");
                break;

            case 2:
                printf("Enter the number of elements to sort: ");
                scanf("%d", &numElements);
                if (numElements > MAX_SIZE || numElements <= 0) {
                    printf("Invalid size! Please enter a value between 1 and %d.\n", MAX_SIZE);
                    break;
                }

                generateRandomInput(array, numElements);
                printf("\nUnsorted Array:\n");
                displayArray(array, numElements);

                selectionSort(array, numElements);

                printf("\nSorted Array:\n");
                displayArray(array, numElements);
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
