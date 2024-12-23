#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "C:/ICTSV+/vector/vector.h"
#include "C:/ICTSV+/data/getinput.h"
#include "C:/ICTSV+/libsextent/function.h"
#include "bruteforce.h"

graphnode *g;
activity *a;
vector graph;
vector act;

int *sum;
vector *adj;
graphnode *store;

void input()
{
    getgraph(&graph);
    getactivity(&act);
    g = (graphnode*)graph.data;
    a = (activity*)act.data;
}

void init()
{
    sum = (int*)calloc(size(&graph) * 2, sizeof(int));
    adj = (vector*)malloc(sizeof(vector) * size(&graph) * 2);
    store = (graphnode*)malloc(sizeof(graphnode) * size(&graph));
    for(int i = 0; i <= size(&graph); i++)
    {
        initvector(&adj[i], sizeof(int));
    }
    for(int i = 0; i < size(&graph); i++)
    {
        graphnode cur = g[i]; 
        store[i] = cur;
        push_back(&adj[cur.par], &cur.idx);
    }
}

void graphTraverse(int *sum, int u, int pre)
{
    for(int i = 0; i < size(&adj[u]); i++)
    {
        int v = *((int*)adj[u].data + i);
        if(v == pre) continue; 
        graphTraverse(sum, v, u);
        sum[u] += sum[v];
        sum[u] = fmin(sum[u], store[u].bound);
    }
}

void reset(int *sum, int u, int pre)
{
    if(size(&adj[u]) != 0) sum[u] = 0;  
    for(int i = 0; i < size(&adj[u]); i++)
    {
        int v = *((int*)adj[u].data + i);
        if(v == pre) continue; 
        reset(sum, v, u);
    }
}

void try(int *ans, int x)
{
    for(int i = 0; i < (a + x)->number; i++)
    {
        graphnode cur = {0, 0, 0, "temp"};
        memcpy(&cur.name, &(a + x)->catname[i], strlen((a + x)->catname[i]));
        char *pos = binary_search(&graph, 0, size(&graph) - 1, (char*)&cur, graphcmp);
        graphnode *castpos = (graphnode*)pos;
        sum[castpos->idx] += castpos->bound;
        if(x < size(&act) - 1) try(ans, x + 1);
        else 
        {
            graphTraverse(sum, 0, 0);
            *ans = fmax(*ans, sum[0]); 
            reset(sum, 0, 0);
        }
        sum[castpos->idx] -= castpos->bound;
    }
}

int bruteforce()
{
    int ans = 0;
    input();
    init();
    mergesort(&graph, 0, size(&graph) - 1, graphcmp);
    try(&ans, 0);
    return ans;
}