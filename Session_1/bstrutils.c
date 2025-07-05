#include "strutils.h" 
#include <stdlib.h>
void str_reverse(char *str)
{
    if (str == NULL) return;

    char *start = str;
    char *end = str;
    
    // Move end pointer to the last character
    while (*end != '\0') {
        end++;
    }
    end--; // Set to the last character

    // Swap characters from start and end until they meet in the middle
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void str_trim(char *str)
{
    if (str == NULL) return;

    // Remove leading whitespace by moving the start pointer
    char *start = str;
    while (*start == ' ' || *start == '\t') {
        start++;
    }

    // If the string is all whitespace, set it to an empty string
    if (*start == '\0') {
        *str = '\0';
        return;
    }

    // Find the last non-whitespace character
    char *end = start;
    while (*end != '\0') {
        end++;
    }
    end--; // Set to the last character

    // Trim trailing whitespace
    while (end > start && (*end == ' ' || *end == '\t')) {
        end--;
    }
    *(end + 1) = '\0';

    // Shift the trimmed string to the start of the original buffer if needed
    if (start != str) {
        char *dst = str;
        while ((*dst++ = *start++));
    }
}

int str_to_int(const char *str, int *out_num)
{
    if (str == NULL || out_num == NULL) return -1;

    char *end;
    long value = strtol(str, &end, 10);

    // Check for conversion errors
    if (end == str || *end != '\0') return -1;

    *out_num = (int)value;
    return 0;
}