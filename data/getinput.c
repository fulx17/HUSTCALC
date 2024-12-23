#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "getinput.h"
#include "C:/ICTSV+/vector/vector.h"

size_t string_size = 300;


void getgraph(vector *a)
{
    initvector(a, sizeof(graphnode));
    graphnode temp;
    FILE *inp = fopen("C:/ICTSV+/data/constgraph.txt","r");
    while(fscanf(inp,"%d %d %d ", &temp.idx, &temp.par, &temp.bound) == 3)
    {
        fgets(temp.name, string_size * sizeof(temp.name), inp);
        temp.name[strcspn(temp.name, "\n")] = '\0';
        push_back(a, &temp);
    }
    fclose(inp);
}

void format_activity(char *str)
{
    for(int i = 0; i < strlen(str); i++) str[i] = str[i + 3];
}

void getactivity(vector *a)
{
    initvector(a, sizeof(activity));
    activity temp;
    char num[20];
    FILE *inp = fopen("C:/ICTSV+/data/input.txt","r");
    while(fgets(temp.name, string_size * sizeof(temp.name), inp))
    {
        fgets(num, 16, inp);
        sscanf(num, "%d", &temp.number);
        for(int j = 0; j < temp.number; j++) 
        {
            fgets(temp.catname[j], string_size * sizeof(temp.catname[j]), inp);
            temp.catname[j][strcspn(temp.catname[j], "\n")] = '\0';
            format_activity(temp.catname[j]);
        }
        temp.name[strcspn(temp.name, "\n")] = '\0';
        push_back(a, &temp);
    }
    fclose(inp);
}

int graphcmp(char *a, char *b)
{
    graphnode *A = (graphnode*)a;
    graphnode *B = (graphnode*)b;
    return strcmp(A->name, B->name);
}
