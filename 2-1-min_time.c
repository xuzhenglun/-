#include "stdio.h"
#include "stdlib.h"
#define Maxsize 100001
typedef struct
{
    int data;
    int next;
} Node;

typedef struct
{
    int add;
    int data;
    int next;
} Sortednode;

void printlink(Node p[],int headnode);

int main(void)
{
    int headnode,num,k;
    Node *p;
    scanf("%d %d %d",&headnode,&num,&k);
    p=(Node *)malloc(Maxsize*sizeof(Node));
    for(int i=0; i<num; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        scanf("%d %d",&p[tmp].data,&p[tmp].next);
    }//input data in a table whitch look as a link table



    num=1;
//printf("%d\n",num);
    for(int i=headnode; p[i].next!=-1; i=p[i].next)
    {
        num++;
//count the number whitch is meanful
    }

    Sortednode *temp,*ans;
    temp=(Sortednode *)malloc(num*sizeof(Sortednode));
    ans=(Sortednode *)malloc(num*sizeof(Sortednode));

    for(int t=0,i=headnode;i!=-1 && t<num;i=p[i].next){
        temp[t].add=i;
        temp[t].data=p[i].data;
        temp[t++].next=p[i].next;
    }//copy node sortlly into anoter tables so that we can easy to find each nodes.
    free(p);

    if(num%k!=0){
        for(int i=num;i>num-num%k;i--){
            ans[i-1].add=temp[i-1].add;
            ans[i-1].data=temp[i-1].data;
            ans[i-1].next=temp[i-1].next;
        }
    }
    for(int i=num-num%k;i>0;i=i-k){
        for(int t=0;t<k;t++){
            ans[i-1-t].add=temp[i-k+t].add;
            ans[i-1-t].data=temp[i-k+t].data;
            ans[i-1-t].next=temp[i-k+t-1].add;
        }
    ans[i-1].next=ans[i].add;
    }
    ans[num-1].next=-1;
//按照顺序复制节点到最终的表中

    free(temp);
    for(int i=0;i<num-1;i++){
        printf("%05d %d %05d\n",ans[i].add,ans[i].data,ans[i].next);
    }
        printf("%05d %d %d\n",ans[num-1].add,ans[num-1].data,ans[num-1].next);
    free(ans);
//printlink(p,headnode);
    return 0;
}





void printlink(Node p[],int i)
{
    do
    {
        printf("%05d %d %05d\n",i,p[i].data,p[i].next);
        i=p[i].next;
//    getchar();
    }
    while(i!=-1);

}//测试函数
