#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include "C:/ICTSV+/vector/vector.h"
#include "C:/ICTSV+/data/getinput.h"
#include "C:/ICTSV+/libsextent/function.h"

void input();

void init();

void graphTraverse(int *sum, int u, int pre);

void reset(int *sum, int u, int pre);

void try(int *ans, int x);

int bruteforce();

#endif