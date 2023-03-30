#include <stdio.h>
#include <stdlib.h>

typedef struct coada
{
    int val;
    struct coada *next,*prev;

}coada;

typedef struct stiva
{
    int val;
    struct coada *prev;

}stiva;

void add_to_coada(coada **last,int val);
void display(coada *first);
void add_to_stiva(stiva **last,int val);
int extract_value(coada **first);
int extract_value_stiva(stiva **last);
