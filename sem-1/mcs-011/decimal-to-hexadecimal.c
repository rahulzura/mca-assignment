#include <stdio.h>

int main() {
    int d_num, r;
    char remainders[11] = {'\0'}; // Fill the array with '\0' character
    char h_num[11] = {'\0'};
    char hexa_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int r_index = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &d_num);

    while (d_num > 0) {
        r = d_num % 16;
        d_num /= 16;

        remainders[r_index] = hexa_digits[r]; // assign remainder in hexadecimal digit
        ++r_index;
    }

    // h_num is the reverse of the remainders
    for (int i = 0; i < r_index; ++i) {
        // last digit in remainders assigned to first digit of h_num and so on
        h_num[i] = remainders[r_index - 1 - i]; 
    }

    printf("Hexadecimal: %s\n", h_num);
    return 0;
}