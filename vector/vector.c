#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include "vector.h"

int size(vector *cur)
{
    return (int)cur->size;
}

void initvector(vector *cur,size_t elementsize)
{
    cur->capacity = 2;
    cur->typesize = elementsize;
    cur->size = 0;
    cur->data = malloc(cur->capacity * cur->typesize);
}

void push_back(vector *cur, void *value)
{
    if(cur->size == cur->capacity)
    {
        cur->capacity *= 2;
        cur->data = realloc(cur->data, cur->capacity * cur->typesize);
    }
    void *target = (char*)cur->data + cur->size * cur->typesize;
    memcpy(target,value,cur->typesize);
    cur->size++; 
}
void pop_back(vector *cur)
{
    if(cur->size > 0)
    {
        cur->size--;
    }
}
void clear(vector *cur)
{
    free(cur->data);
    cur->data = NULL;
    cur->size = 0;
    cur->capacity = 0;
}
