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
 int n,i,k,idle=0,j,num=0;
 float sumwt=0.0,sumtt=0.0,wait,turn;
 printf("Enter the no of processes:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter the process name:");
  __fpurge(stdin);
  gets(p[i].pname);
  printf("Enter arrival time:");
  scanf("%d",&p[i].at);
  printf("Enter burst time:");
  scanf("%d",&p[i].bt);
 }
 for(i=0;i<n;i++) //sorting based on arrival time
 {
  for(j=0;j<n-1-i;j++)
  {
   if(p[j].at>p[j+1].at)
   {
    temp=p[j];
    p[j]=p[j+1];
    p[j+1]=temp;
   }
  }
 }
 for(i=0,k=0;k<n;)
 {
  if(p[k].at<=i && p[k].status==0)
  {
   if(idle==1) 
   {
    d[num].ct=i;
    num++;
   }
   strcpy(d[num].name,p[k].pname);
   d[num].st=i;
   d[num].ct=i+p[k].bt;
   p[k].wt=d[num].st-p[k].at;
   p[k].tt=p[k].wt+p[k].bt;
   i=d[num].ct;
   p[k].status=1;
   k++;
   num++;
   idle=0;
  }
  else if(idle==0)
  {
   strcpy(d[num].name,"idle");
   d[num].st=i;
   i++;
   num++;
   idle=1;
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

/*
Enter the no of processes:3
Enter the process name:A
Enter arrival time:0
Enter burst time:3
Enter the process name:B 
Enter arrival time:2
Enter burst time:3
Enter the process name:C
Enter arrival time:4
Enter burst time:2
Process name|AT		|BT	|TT	|WT	|Status	|
A		0	3	3	0	1		
B		2	3	4	1	1		
C		4	2	4	2	1		
Average waiting time:1.000000
Average turn around time:3.666667
GANTT CHART
|A	|B	|C	|
0	3	6	8

*/

