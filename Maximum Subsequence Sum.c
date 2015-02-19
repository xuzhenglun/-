#include "stdio.h"

int sum(int num[],int n,int a[]){
    int thismax=0,Max=0,i=0,t=0,flag=-1;
    for(int i=0;i<n;i++){
        t++;
        thismax+=num[i];
        if(thismax<0) {thismax=0;t=0;}
        if(Max<thismax) {Max=thismax;a[1]=i;a[0]=t;}
        if(num[i]==0) flag=i;
        }
        if(Max==0) {a[1]=n-1;a[0]=n;Max=0;}
        if(flag!=-1 && Max==0) {a[0]=-1;a[1]=flag;}
 //     printf("%d %d %d %d\n",i,thismax,a[0],a[1]);
        return Max;
}

int main(void) {
    int num[100000]={0};
    int n=0;
    int a[2]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    int tmp=sum(num,n,a);
    printf("%d %d %d",tmp,num[(a[1]-a[0]+1)],num[(a[1])]);
    return 0;
}
