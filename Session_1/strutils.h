#ifndef STRUTILS_H
#define STRUTILS_H
#include <stdio.h>
void str_reverse(char *str);
void str_trim(char *str);
int str_to_int(const char *str, int *out_num);

#endif // STRUTILS_H