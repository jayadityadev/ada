// Design and implement C/C++ Program to find a subset of a given set S = {sl , s2,.....,sn} of n
// positive integers whose sum is equal to a given positive integer d.

#include <stdio.h>

int n, a[100], x[100], total, sol_no = 0;

void sumOfSubset(int sum, int k, int rem) {
    // Include a[k]
    x[k] = 1;
    if (sum + a[k] == total) {
        printf("Solution #%d:\t", ++sol_no);
        for (int i = 1; i <= k; i++)
            if (x[i]) printf("%d\t", a[i]);
        printf("\n");
    } else if (sum + a[k] + a[k + 1] <= total) {
        sumOfSubset(sum + a[k], k + 1, rem - a[k]);
    }

    // Exclude a[k]
    if ((sum + rem - a[k] >= total) && (sum + a[k + 1] <= total)) {
        x[k] = 0;
        sumOfSubset(sum, k + 1, rem - a[k]);
    }
}

int main() {
    int rem = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        rem += a[i];
    }

    printf("Enter the sum total to be computed: ");
    scanf("%d", &total);

    printf("The possible combinations are:\n");
    sumOfSubset(0, 1, rem);

    if (sol_no == 0)
        printf("No valid subset found.\n");

    return 0;
}
