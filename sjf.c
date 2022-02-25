#include<stdio.h>
#include<string.h>
struct process
{
 char pname[20];
 int at,bt,wt,tt,status;
} p[20],temp;
struct done
{
 char name[20];
 int st,ct;
} d[20];
void main()
{
 int n,i,k,idle=0,j,num=0,found,min,ls;
 float sumwt=0.0,sumtt=0.0,wait,turn;
 printf("Enter the no of processes:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  __fpurge(stdin);
  printf("Enter the process name:");
  scanf("%s",p[i].pname);
  //gets(p[i].pname);
  printf("Enter arrival time:");
  scanf("%d",&p[i].at);
  printf("Enter burst time:");
  scanf("%d",&p[i].bt);
 }
 for(i=0,ls=0;ls<n;)
 {
  found=0;
  for(j=0;j<n;j++)
  {
   if(p[j].at<=i && p[j].status==0)
   {
    if(found==0)
    {
     min=j;
     found=1;
    }
    else if(found!=0 && p[min].bt>p[j].bt)
    {
     min=j;
    }
   }
  }
  if(idle==0 && found==0)
  {
   strcpy("idle",d[num].name);
   d[num].st=i;
   i++;
   idle=1;
  }
  else if(found==1)
  {
   if(idle==1)
   {
    d[num].ct=i;
    idle=0;
    num++;
   }
  strcpy(p[min].pname,d[num].name);
  printf("++%s",p[min].pname);
  p[min].status=1;
  d[num].st=i;
  d[num].ct=i+p[num].bt;
  i=d[num].ct;
  p[min].tt=i-p[min].at;
  p[min].wt=p[min].tt;
  ls++;
  num++;
 }
 else
 {
  i++;
 }
 }
 printf("Process name|AT\t\t|BT\t|TT\t|WT\t|Status\t|\n");
  for(i=0;i<n;i++)
  {
  
   sumwt=sumwt+p[i].wt;
   sumtt=sumtt+p[i].tt;
   printf("%s\t\t%d\t%d\t%d\t%d\t%d\t\t\n",p[i].pname,p[i].at,p[i].bt,p[i].tt,p[i].wt,p[i].status);
  }
  wait=(float)(sumwt/n);
  turn=(float)(sumtt/n);
  printf("Average waiting time:%f",wait);
  printf("\nAverage turn around time:%f",turn);
  printf("\nGANTT CHART\n");
  //printf("|");
  for(i=0;i<num;i++)
  {
    printf("|");
    printf("%s\t",d[i].name);
  }
  printf("|");
  printf("\n");
  printf("%d",d[0].st);
  for(i=0;i<num;i++)
  {
   printf("\t%d",d[i].ct);
  }
  printf("\n");
}
 
