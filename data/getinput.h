#ifndef GETINPUT_H
#define GETINPUT_H

#include "C:/ICTSV+/vector/vector.h"

extern size_t string_size;

typedef struct 
{
    int idx, par, bound;
    char name[300];
} graphnode;

typedef struct 
{
    char name[300];
    int number;
    char catname[3][300];
} activity;

void format_activity(char *str);

void getgraph(vector *a);

void getactivity(vector *a);

int graphcmp(char *a, char *b);

#endif