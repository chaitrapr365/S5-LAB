#include<stdio.h>
struct frame
{
  int content;
  int freq;
  int count;
}frames[100];
void main()
{
  int n,no,i,j,count,id=0,fault=0,min,page[100];
  printf("Enter the no.of pages:");
  scanf("%d",&n);
  printf("Enter the pages:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&page[i]);
  }
  printf("Enter the no.of frames:");
  scanf("%d",&no);
  for(i=0;i<no;i++)
  {
    frames[i].content=-1;
    frames[i].freq=0;
    frames[i].count=0;
  }
  printf("pageno\t\tframes");
  for(count=1,i=0;i<n;i++)
  {
    printf("\nPage %d-->\t",page[i]);
    for(j=0;j<no;j++)
    {
      if(frames[j].content == page[i])
      {
        printf("HIT");
        frames[j].freq++;
        frames[j].count=count++;
        break;
      }
    }
    if(j==no)
    {
      if(id<no)
      {
        frames[id].content=page[i];
        frames[id].freq++;
        frames[id].count=count++;
        id++;
      }
      else
      {
        for(min=0,j=0;j<no;j++)
        {
          if(frames[min].freq > frames[j].freq)
          {
            min=j;
          }
          else if((frames[min].freq == frames[j].freq) && (frames[min].count>frames[j].count))
          {
            min=j;
          }
        }
        frames[min].content=page[i];
        frames[min].freq=1;
        frames[min].count=count++;
      }
      fault++;
      for(j=0;j<no;j++)
      {
      printf("%d ",frames[j].content);
      }
    }
  }
  printf("\nPage Fault-> %d\n",fault);
}
/*OUTPUT
Enter the no.of pages:8
Enter the pages:1 3 5 3 7 6 4 5
Enter the no.of frames:3
pageno		frames
Page 1-->	1 -1 -1 
Page 3-->	1 3 -1 
Page 5-->	1 3 5 
Page 3-->	HIT
Page 7-->	7 3 5 
Page 6-->	7 3 6 
Page 4-->	4 3 6 
Page 5-->	4 3 5 
Page Fault-> 7
*/
