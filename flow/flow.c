#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "C:/ICTSV+/vector/vector.h"

const int N = 100;
typedef struct 
{
    int u, v, cost, flow;
} edge;

vector *g;

void initAdjacentList()
{
    g = (vector*)malloc(sizeof(vector) * (size_t)N);
    for(int i = 0; i < N; i++)
    {
        initvector(&g[i], sizeof(edge));
    }
}

int main()
{
    initAdjacentList();
    edge cur = {1, 2, 3, 78};
    push_back(&g[1], &cur);
    edge *u = (edge*)g[1].data + 0;
    printf("%d %d %d %d",u->u, u->v, u->cost, u->flow);
}