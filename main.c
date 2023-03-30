#include "functii.h"

int main()
{
    int n,val;
    scanf("%d",&n);

    coada *first=(coada*)malloc(sizeof(coada));
    coada *last;

    scanf("%d",&val);
    first->next=NULL;
    add_to_coada(&first,val);//initializarea primului nod
    first->prev=NULL;//apelanda cu first functia inseamna ca first va
    //deveni o adresa adugata dupa first-ul original atunci
    //trb initializat noul first cu ->prev NULL ca sa devina primul elemnt
    // daca nu intelegi e ok doar pune l asa sau iti faci citirea cum vrei tu :)
    last=first;

    for(int i=1;i<n;i++)
    {
        scanf("%d",&val);
        add_to_coada(&last,val);

    }

    printf("coada originala:");
    display(first);


    stiva *lasts=(stiva*)malloc(sizeof(stiva));
    add_to_stiva(&lasts,extract_value(&first));
    lasts->prev=NULL;


    while(first!=last)//ne vom duce pana cand ajungem la un singut element din lista ca sa
        //il folosim fara sa distrugem first sau last axa pt a pastra corect lista
    {
        add_to_stiva(&lasts,extract_value(&first));
    }
    add_to_stiva(&lasts,first->val);
    //acum toate valorile din coada sunt salvate in stiva
    //iar extragand elemnte din stiva si adaugandu le in coada se vor adauga inversate

    first->next=NULL;
    add_to_coada(&first,extract_value_stiva(&lasts));
    first->prev=NULL;
    last=first;
    while(lasts!=NULL)
    {
        add_to_coada(&last,extract_value_stiva(&lasts));
    }
    printf("coada inversata:");
    display(first);





    return 0;
}
