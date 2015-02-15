#include "stdio.h"

int sum1(int num[],int n){
   int maxsum=0;
    int thissum=0;
    for(int i=0;i<n;i++){
        thissum = 0;
        for(int j=i;j<n;j++){
            thissum+=num[j];
            if(thissum > maxsum)
                maxsum=thissum;
        }
    }
    return maxsum;
}


int max(int n1,int n2){
    if(n1>n2) return n1;
    else return n2;
}

int sum2(int num[],int n){
    static int Max=0;
    n=n/2;
    num+=n;
    if(n>1){
        Max=max(sum2(num,n),sum2(num-n,n));
        int thismax=0 ,leftmax=0,rightmax=0;
        for(int i=0;i<n;i++){
            thismax+=*(num+i);
            if(rightmax<thismax)
                rightmax=thismax;
        }
        thismax =0;
        for(int i=0;i<n;i++){
            thismax+=*(num-1-i);
            if(leftmax<thismax)
                leftmax=thismax;
        }
        return Max=max(Max,leftmax+rightmax);
    }
    else
        return max(*(num-1)+*num,(max(*(num-1),*num)));
}

int sum3(int num[],int n){
    int thismax=0,Max=0;
    for(int i=0;i<n;i++){
        thismax+=num[i];
        if(Max<thismax) Max=thismax;
        if(thismax<0) thismax=0;
        }
        return Max;
}

int main(void) {
    int num[100000]={0};
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    printf("%d",sum3(num,n));
    return 0;
}
