#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

#include<C:/ICTSV+/vector/vector.h>
#include<C:/ICTSV+/data/getinput.h>


void mergesort(vector *g, int l, int r, int cmp(char*, char*))
{
    if(l >= r) return;
    int m = (l + r) / 2;
    mergesort(g, l, m, cmp);
    mergesort(g, m + 1, r, cmp);
    int pointerL = l, pointerR = m + 1, pointerA = 0;
    int size = r - l + 1;
    char *temp = (char*)malloc(size * g->typesize);

    while(pointerL <= m && pointerR <= r)
    {
        if(cmp((char*)g->data + pointerL * g->typesize, (char*)g->data + pointerR * g->typesize) <= 0) 
        {
            memcpy(temp + pointerA * g->typesize, (char*)g->data + pointerL * g->typesize, g->typesize);
            pointerL++;
        }
        else 
        {
            memcpy(temp + pointerA * g->typesize, (char*)g->data + pointerR * g->typesize, g->typesize); 
            pointerR++;  
        }
        pointerA++;
    }
    while(pointerL <= m) 
    {
        memcpy(temp + pointerA * g->typesize, (char*)g->data + pointerL * g->typesize, g->typesize);
        pointerL++;
        pointerA++;
    }
    while(pointerR <= r)
    {
        memcpy(temp + pointerA * g->typesize, (char*)g->data + pointerR * g->typesize, g->typesize); 
        pointerR++;  
        pointerA++;
    }
    memcpy((char*)g->data + l * g->typesize, temp, size * g->typesize);
    free(temp);
} 

char* binary_search(vector *g, int l, int r, char* target, int cmp(char*, char*))
{
    while(l <= r)
    {
        int m = (l + r) / 2;
        char *pos = (char*)g->data + m * g->typesize;
        int cmpvalue = cmp(target, pos); 
        if(cmpvalue == 0) return pos;
        else if(cmpvalue > 0) l = m + 1;
        else r = m - 1; 
    }
    return NULL;
}