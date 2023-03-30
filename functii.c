#include "functii.h"

void add_to_coada(coada **last,int val)
{
    coada *new_node=(coada*)malloc(sizeof(coada));
    new_node->val=val;
    new_node->next=(*last)->next;
    new_node->prev=*last;
    (*last)->next=new_node;
    (*last)=new_node;

}
void display(coada *first)
{
  while(first!=NULL)
  {
      printf("%d ",first->val);
      first=first->next;
  }
  printf("\n");
}

int extract_value(coada **first)
{
    coada *aux=*first;
    int val=(*first)->val;
    *first=(*first)->next;
    (*first)->prev=NULL;
    free(aux);
    return val;
}

void add_to_stiva(stiva **last,int val)
{
    stiva *new_node=(stiva*)malloc(sizeof(stiva));
    new_node->val=val;
    new_node->prev=*last;
    (*last)=new_node;
}
int extract_value_stiva(stiva **last)
{
    stiva *aux=*last;
    int val=(*last)->val;
    *last=(*last)->prev;
    free(aux);
    return val;

}
