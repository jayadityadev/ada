// Design and implement C/C++ Program for N Queen's problem using Backtracking.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int board[MAX], count = 0;

int isSafe(int row, int col) {
    for (int prevRow = 1; prevRow < row; prevRow++) {
        if (board[prevRow] == col || abs(board[prevRow] - col) == abs(prevRow - row)) {
            return 0;
        }
    }
    return 1;
}

void printSolution(int n) {
    printf("Solution %d:\n", ++count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

void solveNQueens(int row, int n) {
    if (row > n) {
        printSolution(n);
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n); 
        }
    }
}

int main() {
    int n;
    printf("Enter the value of N (number of queens): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid input. N must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("\nSolutions to %d-Queens Problem:\n\n", n);
    solveNQueens(1, n);

    if (count == 0)
        printf("No solution exists for N = %d\n", n);

    return 0;
}
