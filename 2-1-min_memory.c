//还有BUG,case6超时,case7错误.原因未知.
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int curadd;
	int data;
	int nextadd;
}Node;

int head,n,k;

int getnextadd(Node p[],int headadd){ //ÓÉcuraddµÃµœžÃœÚµãµÄnextadd
    int i;
    for(i=0;p[i].curadd!=headadd && i<n;i++);
    return p[i].nextadd;
}

int getnumadd(Node p[],int headadd,int num){ //ÓÉÁŽ±íµÄÂßŒ­ÐòºÅµÃ³öžÃœÚµãµÄÎïÀíµØÖ·
    for(int i=0;i<num;i++){
        headadd=getnextadd(p,headadd);
    }
    return headadd;
}

int getnum(Node p[],int add){ //ÓÉÎïÀíµØÖ·µÃµœÁŽ±íÎïÀíÐòºÅ
    int i;
    for(i=0;p[i].curadd!=add && i<n;i++);
    return i;
}

int main(void)
{
Node * p=NULL;
scanf("%d %d %d",&head,&n,&k);
p=(Node * )malloc(n*sizeof(Node));
for(int i=0;i<n;i++){
    scanf("%d %d %d",&p[i].curadd,&p[i].data,&p[i].nextadd);
}//°ÑÊýŸÝÒÔÊý×éžñÊœÊäÈëÄÚŽæ

int headnode;
for(headnode=0;p[headnode].curadd!=head;headnode++);
//ÕÒµœÁŽ±íÍ·

int num=0,r;
r=p[headnode].curadd;
do{
  //  printf("%d\n",r);
    r=getnextadd(p,r);
    num++;
}while(r!=-1 && num<n);
n=num; //ŒÆÊýžÃÁŽ±íÊµŒÊÓÐ¶àÉÙžöÓÐÐ§œÚµã
//printf("%d\n",n);
if(k!=1){
int last=p[getnum(p,(getnumadd(p,head,n-n%k)))].curadd;//±ž·ÝÓÒ²à¶à³öÀŽÒ»¶ÎµÄÍ·œáµãµØÖ·
int temp;
for(int i=n-n%k-1;i>=0;i=i-k){

    temp=p[getnum(p,(getnumadd(p,head,i)))].curadd;
  //  printf("Head of %d is %05d\n",i,temp);
    for(int t=0;t<k;t++){
    p[getnum(p,(getnumadd(p,temp,t)))].nextadd=p[getnum(p,(getnumadd(p,head,i-t-1)))].curadd;
    }

    p[getnum(p,(getnumadd(p,temp,k-1)))].nextadd=last;
    last=temp;
}
headnode=last;
p[getnum(p,(getnumadd(p,headnode,n-1)))].nextadd=-1;
}
else headnode=p[headnode].curadd;
int i;
for(i=0;i<n-1;i++){
   // printf("%d\n",headnode);
    printf("%05d %d %05d\n",p[getnum(p,getnumadd(p,headnode,i))].curadd,p[getnum(p,getnumadd(p,headnode,i))].data,p[getnum(p,getnumadd(p,headnode,i))].nextadd);
}

    printf("%05d %d %d",    p[getnum(p,getnumadd(p,headnode,i))].curadd,p[getnum(p,getnumadd(p,headnode,i))].data,p[getnum(p,getnumadd(p,headnode,i))].nextadd);
free(p);
/*printf("-------------------------\n");
for(int i=0;i<6;i++){
    printf("%05d %d %05d\n",p[i].curadd,p[i].data,p[i].nextadd);
}
*/
return 0;
}
