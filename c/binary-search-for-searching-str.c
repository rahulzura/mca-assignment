#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int binary_search(char *str_arr[11], int left, int right, char str[]) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // check if the str is present in the middle
        if (strcmp(str, str_arr[mid]) == 0) {
            return mid;
        } else if (strcmp(str, str_arr[mid]) > 0) {
            // if str is greater than str at mid, then search the right half
            return binary_search(str_arr, mid, right, str);
        } else {
            // search the left half
            return binary_search(str_arr, left, mid, str);
        }
    }

    // right index is greater than left, meaning we searched the arr but didn't find the element
    return -1;
}

int main() {
    char *str_arr[5];
    char str[11] = {'\0'};
    int str_index;

    for (int i = 0; i < 5; ++i) {
        str_arr[i] = malloc(11 * sizeof(char));
    }

    printf("Enter 5 strings (containing upto 10 letters, \nand the strings should be in lexicographical order):\n");
    for (int i = 0; i < 5; ++i) {
        scanf(" %s", str_arr[i]);
    }

    printf("Enter the string to find: ");
    scanf(" %s", str);

    str_index = binary_search(str_arr, 0, 5, str);
    
    if (str_index != -1) {
        printf("The required string is at index %d\n", str_index);
    } else {
        printf("The required string is not in the array\n");
    }

    // Free the allocated memory
    for (int i = 0; i < 5; ++i) {
        free(str_arr[i]);
    }
    return 0;
}