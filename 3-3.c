#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define null -1

typedef struct Node
{
    int date;
} node;

void treeprinter(node *p,int i)  //后序递归输出
{
    if(p[2*i].date!=0) treeprinter(p,2*i);
    if(p[2*i+1].date!=0) treeprinter(p,2*i+1);
    printf("%d",p[i].date);
    if(i!=1) printf(" ");
}

int main(void)
{
    int MAX,n=1;
    node *p=(node *)malloc((MAX<<2)*sizeof(node));
    scanf("%d",&MAX);



    for(int i=1; i<=MAX<<1; i++)
    {

        char input[5]= {0};
        int  num=null;
        scanf("%4s",input); //先接受前四个字符,貌似因为/n也会被接受,所以Pop的话也能够正确接受
        if(!strcmp(input,"Push")) scanf("%d",&num);

        if(!strcmp(input,"Push"))  //如果是Push指令,那么就这样
        {

            p[n].date=num;
            n=n<<1;
        }

        if(!strcmp(input,"Pop"))  //如果是Pop指令,那么就这样
        {
            if(n%2==0) n++;
            else
            {
                n=n/2+1;
                while(!p[n/2].date) n=n/2;
            }

        }
    }
    treeprinter(p,1);
    free(p);  //释放内存
    return 0;
}
