#include<stdio.h>
void main()
{
  int n,no,avail,i,j,k,count=0;
  int frame[50],a[50];
  printf("Enter the number of pages:");
  scanf("%d",&n);
  printf("Enter the pages:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter the number of frames:");
  scanf("%d",&no);
  for(i=0;i<no;i++)
  {
    frame[i]=-1;
  }
  j=0;
  printf("pageno\t\tframes");
  for(i=0;i<n;i++)
  {
    printf("\nPage %d-->\t",a[i]);
    avail=0;
    for(k=0;k<no;k++)
    {
      if(frame[k]==a[i])
      {
        avail=1;
      }
    }
    if(avail==0)
    {
      frame[j]=a[i];
      j=(j+1)%no;
      count++;
      for(k=0;k<no;k++)
      {
        printf("%d ",frame[k]);
      }
    }
    else
    {
      printf("HIT");
    }
  }
  printf("\nPage Fault:- %d\n",count);
}
/*OUTPUT
Enter the number of pages:5
Enter the pages:1 4 2 4 3
Enter the number of frames:3
pageno		frames
Page 1-->	1 -1 -1 
Page 4-->	1 4 -1 
Page 2-->	1 4 2 
Page 4-->	HIT
Page 3-->	3 4 2 
Page Fault:- 4
*/
