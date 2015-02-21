#include "stdio.h"
#include "stdlib.h"

typedef struct
        Node
{
    int coe;
    int exp;
    struct Node *next;
} node;

int main(void)
{
    node *head=(node*)malloc(sizeof(node));
    node *i=head;
    do
    {
        i->next=(node*)malloc(sizeof(node));
        i=i->next;
        scanf("%d %d",&i->coe,&i->exp);
    }
    while(i->exp!=0);
    i->next=-1;

    if(head->next->exp==0) printf("0 0");
    for(i=head; i->next->exp!=0; i=i->next)
    {
        printf("%d %d",((i->next)->coe)*((i->next)->exp),(i->next->exp)-1);
        if((i->next->next->next)!=-1)printf(" ");
    }
//printf("|");

}
