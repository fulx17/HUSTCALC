#ifndef VECTOR_H
#define VECTOR_H
#include<stddef.h>

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t typesize;
} vector;

int size(vector *cur);
void initvector(vector *cur, size_t elementsize);
void push_back(vector *cur, void *value);
void pop_back(vector *cur);
void clear(vector *cur);

#endif