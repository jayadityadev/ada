// Design and implement C/C++ Program for N Queen's problem using Backtracking.

#include <stdio.h>
#include <math.h>

#define MAX 20

int board[MAX], count = 0;

// Check if the queen placement is valid
int isSafe(int row, int col) {
    for (int prevRow = 1; prevRow < row; prevRow++) {
        // Check same column or diagonal attacks
        if (board[prevRow] == col || abs(board[prevRow] - col) == abs(prevRow - row)) {
            return 0;
        }
    }
    return 1;
}

// Print the board configuration
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

// Recursive function to place queens
void solveNQueens(int row, int n) {
    if (row > n) {
        printSolution(n);
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;  // Place queen
            solveNQueens(row + 1, n);  // Recur for next row
            // No need to undo board[row] since it will be overwritten
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
