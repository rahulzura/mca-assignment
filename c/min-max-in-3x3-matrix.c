#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS];
    int min, max;
    int cur_el;

    printf("Enter a 3 by 3 matrix:\n");
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            scanf(" %d", &matrix[i][j]); 
        }
    }

    min = max = matrix[0][0];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cur_el = matrix[i][j];
            if (cur_el < min) {
                min = cur_el;
            }

            if (cur_el > max) {
                max = cur_el;
            }
        }
    }

    printf("Minimum: %d\nMaximum: %d\n", min, max);
    return 0;
}