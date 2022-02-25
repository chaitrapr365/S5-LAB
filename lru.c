#include<stdio.h>
int pages[50],frames[50],time[50];
int n,no,j,p,f,pa,flag,fr;
int fault=0;
void input()
{
  printf("Enter the number of frames:");
  scanf("%d",&no);
  printf("Enter the number of pages:");
  scanf("%d",&n);
  printf("Enter the pages:");
  for(p=0;p<n;p++)
  {
    scanf("%d",&pages[p]);
  }
}
void lru()
{
  j=0;
  printf("Pageno\t\tframes");
  for(f=0;f<no;f++)
  {
    frames[f]=-1;
  }
  for(p=0;p<n;p++)
  {
    printf("\nPage %d-->\t",pages[p]);
    flag=0;
    pa=pages[p];
    time[pa]=p;
    for(f=0;f<no;f++)
    {
      if(pages[p]==frames[f])
      {
        flag=1;
        break;
      }
    }
    if(flag)
    {
      printf("HIT");
    }
    else
    {
      frames[j]=pages[p];
      fault++;
      for(f=0;f<no;f++)
      {
        printf("%d ",frames[f]);
      }
    }
    if(frames[j+1]==-1)
    {
      j++;
    }
    else
    {
      j=leastRecentlyUsed();
    }
  }
}
int leastRecentlyUsed()
{
  int index=-1;
  int min=50;
  for(f=0;f<no;f++)
  {
    fr=frames[f];
    if(time[fr]<min)
    {
      min=time[fr];
      index=f;
    }
  }
  return index;
}
void main()
{
  for(int m=0;m<50;m++)
  {
    time[m]=0;
  }
  input();
  lru();
  printf("\nPage Fault:- %d\n",fault);
}
/*OUTPUT
Enter the number of frames:3
Enter the number of pages:7
Enter the pages:1 6 1 3 8 3 2
Pageno		frames
Page 1-->	1 -1 -1 
Page 6-->	1 6 -1 
Page 1-->	HIT
Page 3-->	1 6 3 
Page 8-->	1 8 3 
Page 3-->	HIT
Page 2-->	2 8 3 
Page Fault:- 5
*/ 
