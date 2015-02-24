/*
02-线性结构3. 求前缀表达式的值（25）

坑爹的是字符串转化,别的难度不高.字符串转化貌似有个函数,不过还是自己实现算了= =.
Pop_int这种函数名里面的int是历史遗留问题,一开始闹抽没想到小数.后来就没该.

另外求解为啥后面pop出来不先赋值在带入domath函数会出错.具体domath(Pop_int(p),Pop_int(p),'+')可以,但是domath(Pop_int(p),Pop_int(p),Pop_char(p));就不可以了.

*/



#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define MAX 10001

typedef struct Stack
{
    int index[MAX];                      //0代表空，1代表数字，2代表运算符
    char ch[MAX];
    float num[MAX];
    int top;
} stack;

void Push_char(stack *p,char item)
{
    if(p->top==MAX-1)
    {
        printf("FULL STACK\n");
        return;
    }
    else
    {
        p->ch[++(p->top)]=item;
        p->index[(p->top)]=2;
    }
}

void Push_int(stack *p,float item)
{
    if(p->top==MAX-1)
    {
        printf("FULL STACK\n");
        return;
    }
    else
    {
        p->num[++(p->top)]=item;
        p->index[(p->top)]=1;
    }
}

char Pop_char(stack *p)
{
    if(p->top==-1)
    {
        printf("EMPTY STACK\n");
        return -1;
    }
    else
    {
        p->index[(p->top)]=0;
        return (p->ch[(p->top)--]);
    }
}

float Pop_int(stack *p)
{
    if(p->top==-1)
    {
        printf("EMPTY STACK\n");
        return -1;
    }
    else
    {
        p->index[(p->top)]=0;
        return (p->num[(p->top)--]);
    }
}

float domath(float a,float b,char c)
{
    switch(c)
    {
    case '+':
    {
        return a+b;
        break;
    }
    case '-':
    {
        return b-a;
        break;
    }
    case '*':
    {
        return b*a;
        break;
    }
    case '/':
    {
        if(a==0)
        {
            printf("ERROR");
            exit(0);
        }
        return b/a;
        break;
    }

    }

}


float truemath(char sym,float num)
{
    if(sym=='-')
        return -num;
    else
        return num;
}

int main(void)
{
    char input[MAX];
    gets(input);
    stack *p=(stack *)malloc(sizeof(stack));

    for(int i=0; input[i]!='\0'; i++)
    {
        float temp_int;
        int type;
        char temp_char;
//printf("%c\n",input[i]);
        if((input[i]=='+' ||input[i]=='-' ||input[i]=='*' ||input[i]=='/') && (input[i+1]==' ' ||input[i+1]=='\0' ) ) //判断是否是符号，
        {
            temp_char=0;
            temp_int=0;
            temp_char=input[i];
            type=2;
            // printf("%c\n",temp_char);
            i++;
        }
        else
        {
            temp_char=0;
            temp_int=0;
            while(input[i]!=' ' && input[i]!='\0')  //数字字符串 转换为 float类型
            {
                type=1;
                if(input[i]=='+' || input[i]=='-')
                {
                    temp_char=input[i];
                    i++;
                }
                if(input[i]>='0' && input[i]<='9' )
                {
                    temp_int=temp_int*10+(float)(input[i]-'0');
                }
                if(input[i]=='.')
                {
                    float point=0.0;
                    int count=0;
                    for(i++; input[i]!=' ' && input[i]!='\0'; i++)
                    {
                        point=point*10+(float)(input[i]-'0');
                        //printf("%d  :",i);
                        //printf("%f\n",point);
                        count++;
                    }
                    if(point!=0) i--;
                    temp_int=temp_int+point*pow(10,-count);

                }
                i++;
            }
        }


        if(type==1)
        {
            Push_int(p,truemath(temp_char,temp_int));

        }
        if(type==2)
        {
            Push_char(p,temp_char);

        }


        while(p->index[p->top-2]==2 && p->index[p->top]==1 &&p->index[p->top-1]==1 && p->top>2)
        {
            float a,b;
            char c;
            a=Pop_int(p);
            b=Pop_int(p);
            c=Pop_char(p);
            Push_int(p,domath(a,b,c));
        }
    }

    printf("%.1f\n",Pop_int(p));
    return 0;
}
