#ifndef FUNCTION_H
#define FUNCTION_H
#include<C:/ICTSV+/vector/vector.h>

void mergesort(vector *g, int l, int r, int cmp(char*, char*));

char* binary_search(vector *g, int l, int r, char* target, int cmp(char*, char*));

#endif