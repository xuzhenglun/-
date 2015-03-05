#include <stdio.h>
#include <stdlib.h>

typedef struct Node //定义节点结构
{
    int left;
    int right;
} node;

typedef struct Line//定义队列节点
{
    int date;
    struct Line * next;
} line;

void add_line(line *head,int item)//队列插入方法
{
    line *temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=(line *)malloc(sizeof(line));
    temp->next->date=item;
    temp->next->next=NULL;
}

int delete_line(line *head){//队列取出方法
    int date=head->next->date;
    line *temp=head->next;
    head->next=head->next->next;
    free(temp);
    return date;
}

int getfather(node *p,int m,int target)//获取父节点
{
    int i;
    for(i=0; i<m; i++)
    {
        if(p[i].left == target || p[i].right == target )
            return i;
    }
    return -1;
}

int getroot(node *p,int m)//获取根节点
{
    int temp=0,index;
    while(temp!=-1)
    {
        index=temp;
        temp=getfather(p,m,index);
    }
    return index;
}

void leaves_printer(node *all,int n)//层次遍历树,并且打印
{
    line *p=(line *)malloc(sizeof(line));
    p->next=(line *)malloc(sizeof(line));
    p->next->next=NULL;
    p->next->date=n;
    int temp=n;
    while(p->next!=NULL){
        temp=delete_line(p);
        if(all[temp].left == -1 && all[temp].right == -1) printf("%d",temp);
        if(all[temp].left == -1 && all[temp].right == -1 && p->next!=NULL) printf(" ");
        if(all[temp].left!=-1) add_line(p,all[temp].left);
        if(all[temp].right!=-1) add_line(p,all[temp].right);
    }
}

void main(void)
{
    int m;
    scanf("%d\n",&m);
    node *p=(node *)malloc(m*sizeof(node));
    for(int i=0; i<m; i++,getchar())
    {
        char left,right;
        scanf("%c %c",&left,&right);
        if( left>='0' && left <='9')  p[i].left =(int)( left-'0');
        else p[i].left= -1;
        if(right>='0' && right <='9') p[i].right=(int)(right-'0');
        else p[i].right=-1;
    }
    int index=getroot(p,m);
    leaves_printer(p,index);
}
