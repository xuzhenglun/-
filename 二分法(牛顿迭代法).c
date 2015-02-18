#include "stdio.h"
#define MAX 4
#include "math.h"

float fun(float a[],float x)
{
    return (((x*a[0])+a[1])*x+a[2])*x+a[3];
}

void root(float a[],float low,float end)
{
    if(end-low < 0.01) printf("%.2f",(end+low)/2.0);
    else
    {
        if(fabs((end+low)/2.0 < 0.01)&&(end-low)<0.01) printf("0");
        else
        {
            if(fun(a,low)*fun(a,end)>0.0) printf("ERROR");
            else
            {
                if(fun(a,low)*fun(a,((low+end)/2.0))<=0) root(a,low,(low+end)/2.0);
                else
                    root(a,(low+end)/2.0,end);
            }
        }
    }
}

int main(void)
{
    float low,end,a[MAX];
    for(int i=0; i<MAX; scanf("%f ",&a[i++]));
    scanf("%f %f",&low,&end);
    root(a,low,end);
    return 0;
}
