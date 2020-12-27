#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    int matrix[ROWS][COLS];
    int sum = 0;

    printf("Enter a 3 by 3 matrix:\n");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            scanf(" %d", &matrix[i][j]);
        }
    }


    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Pointer aritmatic
            // *(matrix + i) is same as matrix[i]
            // *(*(matrix + i) + j) is same as martix[i][j]
            sum += *(*(matrix + i) + j);
        }
    }

    printf("Sum is %d\n", sum);
    return 0;
}