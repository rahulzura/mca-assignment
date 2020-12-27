#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_str_len(char *str) {
    int i = 0;
    char c;

    do {
        c = str[i];
        ++i;
    } while (c != '\0');

    return i;
}

void replace_char_in_str(char *str, char c_to_replace_by, int pos) {
    int len = get_str_len(str);

    if (pos > len - 1) {
        // out of bound
        printf("Position entered is greater than length of string. Nothing to replace.");
    }

    str[pos] = c_to_replace_by;
}

void convert_str_to_upper(char *str) {
    int i = 0;
    char c = str[i];
    while (c != '\0') {
        str[i] = toupper(c);
        c = str[++i];
    }
}

void convert_alt_char_to_upper(char *str) {
    int i = 0;
    char c = str[i];

    while (c != '\0') {
        if (i % 2 == 0) {
            str[i] = toupper(c);
        }
        c = str[++i];
    }
}

void print_char_group_of_chars_in_str(char *str) {
    int i = 0;
    char c = str[i];

    while (c != '\0') {
        // check if alphabet
        if (isalpha(c)) {
            printf("%c is an alphabet\n", c);
        } 
        
        // check if digit
        else if (isdigit(c)) {
            printf("%c is a digit\n", c);
        }

        // it's special char
        else {
            printf("%c is a special character\n", c);
        }

        c = str[++i];
    }
}

int main() {
    char str[101];
    int option;
    int pos;
    char c;

    printf("Enter a string (upto 100 characters): ");
    scanf(" %s", str);

    printf("Choose an option (1, 2, 3 or 4):\n1. Replace one character\n2. Convert string to uppercase\n3. Convert alternate characters to uppercase\n4. For each character in the string, show whether it's a alphabet, digit or special character\n");

    scanf(" %d", &option);

    switch (option) {
        case 1:
            printf("Enter a character and position of character which you want to replace in string respectively: ");
            scanf(" %c %d", &c, &pos);

            // do the replacement
            replace_char_in_str(str, c, pos - 1);
            printf("String after replacement:\n%s\n", str);
            break;
        case 2:
            // convert string to uppercase
            convert_str_to_upper(str);
            printf("String after converting to uppercase:\n%s\n", str);
            break;
        case 3:
            // convert alternate characters to uppercase
            convert_alt_char_to_upper(str);
            printf("String after converting alternate characters to uppercase\n%s\n", str);
            break;
        case 4:
            // show each character's group
            print_char_group_of_chars_in_str(str);
            break;
        default:
            printf("You choose invalid option!\n");
    }
    return 0;
}