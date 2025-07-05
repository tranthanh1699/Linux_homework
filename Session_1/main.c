#include <stdio.h>
#include "strutils.h"

int main() {
    printf("What action you want to do?\n"
           "1. Reverse a string\n"
           "2. Trim a string\n"
           "3. Convert a string to an integer\n"
           "Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            char str[100];
            printf("Enter a string to reverse: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { /* bỏ qua */ }
            fgets(str, sizeof(str), stdin);
            str_reverse(str);
            printf("Reversed string: %s\n", str);
            break;
        }
        case 2: {
            char str[100];
            printf("Enter a string to trim: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { /* bỏ qua */ }
            fgets(str, sizeof(str), stdin);
            str_trim(str);
            printf("Trimmed string: %s\n", str);
            break;
        }
        case 3: {
            char str[100];
            int num;
            printf("Enter a string to convert to an integer: ");
            scanf("%s", str);
            if (str_to_int(str, &num) == 0) {
                printf("Converted number: %d\n", num);
            } else {
                printf("Failed to convert string to number.\n");
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}