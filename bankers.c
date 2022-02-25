#include<stdio.h>
#include<string.h>
int resmax[100];
int maxalloc[100];
int avail[100];
struct process
{
  char name[100];
  int max[100];
  int alloc[100];
  int need[100];
  int done;
}p[20],temp;
void main()
{
  int i,j,r,pr,flag,ls,ml=0,g=0;
  char s[100]="";
  printf("Enter no.of resources:");
  scanf("%d",&r);
  printf("Enter maximum resource count:");
  for(j=0;j<r;j++)
  {
    scanf("%d",&resmax[j]);
  }
  printf("Enter the no.of processes:");
  scanf("%d",&pr);
  for(i=0;i<pr;i++)
  {
    printf("\nEnter process name:");
    scanf("%s",&p[i].name);
    printf("Enter max allocation:");
    for(j=0;j<r;j++)
    {
      scanf("%d",&p[i].max[j]);
    }
    printf("Enter allocated resources:");
    for(j=0;j<r;j++)
    {
      scanf("%d",&p[i].alloc[j]);
    }
    for(j=0;j<r;j++)
    {
      maxalloc[j]=maxalloc[j]+p[i].alloc[j];
    }
    for(j=0;j<r;j++)
    {
      p[i].need[j]=p[i].max[j]-p[i].alloc[j];
    }
    p[i].done=0;
  }
  printf("\n PROCESS \tMAXIMUM \tALLOCATED \tNEED\n");
  for(i=0;i<pr;i++)
  {
    printf("\n     %s      \t ",p[i].name);
    for(j=0;j<r;j++)    
    {
      printf("%d ",p[i].max[j]);
    }
    printf(" \t  ");
    for(j=0;j<r;j++)    
    {
      printf("%d ",p[i].alloc[j]);
    }
    printf("\t  ");
    for(j=0;j<r;j++)    
    {
      printf("%d ",p[i].need[j]);
    }
  }
  printf("\nAvailable:-");
  for(i=0;i<r;i++)
  {
    avail[i]=resmax[i]-maxalloc[i];
    printf("%d ",avail[i]);
  }
  for(i=0,ls=0;ls<pr;)
  {
    for(flag=0,j=0;j<r;j++)
    {
      if(avail[j] >= p[i].need[j])
      {
        flag++;
      }
    }
    if(flag==r && p[i].done==0)
    {
      p[i].done=1;
      for(ml=0,j=0;j<r;j++)
      {
        avail[j]=avail[j]+p[i].alloc[j];
        if(avail[j] == resmax[j])
        {
          ml++;
        }
      }
      ls++;
      g++;
      strcat(s,p[i].name);
      strcat(s,", ");
    }
    else
    {
      i++;
      if(i==pr)
      {
        if(g==0)
        {
          printf("\t\tREQUEST NOT ALLOCATED DEADLOCK OCCURED\n");
          break;
        }
        i=0;
        g=0;
      }
    }
  }
  if(ml==r && ls==pr)
  {
    printf("\n\nSYSTEM IS IN SAFE STATE\n");
    printf("\nSafe state sequence:%s",s);
    printf("\b\b.  \n");
  }
  else if(g==0)
  {
    printf("\nSYSTEM IS IN UNSAFE STATE\n");
  }
}
/*
OUTPUT
Enter no.of resources:3
Enter maximum resource count:10 5 7
Enter the no.of processes:5

Enter process name:p1
Enter max allocation:7 5 3
Enter allocated resources:0 1 0

Enter process name:p2
Enter max allocation:3 2 2
Enter allocated resources:2 0 0

Enter process name:p3
Enter max allocation:9 0 2
Enter allocated resources:3 0 2

Enter process name:p4
Enter max allocation:4 2 2
Enter allocated resources:2 1 1

Enter process name:p5
Enter max allocation:5 3 3
Enter allocated resources:0 0 2

 PROCESS 	MAXIMUM 	ALLOCATED 	NEED

     p1      	 7 5 3  	  0 1 0 	  7 4 3 
     p2      	 3 2 2  	  2 0 0 	  1 2 2 
     p3      	 9 0 2  	  3 0 2 	  6 0 0 
     p4      	 4 2 2  	  2 1 1 	  2 1 1 
     p5      	 5 3 3  	  0 0 2 	  5 3 1 
Available:-3 3 2 

SYSTEM IS IN SAFE STATE

Safe state sequence:p2, p4, p5, p1, p3.  
*/
