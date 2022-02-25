#include<stdio.h>
void main()
{
 int i,j,k,np,nf,frame[20],pages[100],fault=0,hit;
 printf("Enter the no of frames:");
 scanf("%d",&nf);
 for(i=0;i<nf;i++)
 {
  frame[i]=-1;
 }
 printf("Enter the no of pages:");
 scanf("%d",&np);
 printf("Enter the reference string:");
 for(i=0;i<np;i++)
 {
  scanf("%d",&pages[i]);
 }
 printf("REFERENCE STRING\tFRAME 1\t\tFRAME 2\t\tFRAME 3");
 for(j=0,i=0;i<np;i++)
 {
  printf("\n%d\t\t\t",pages[i]);
  hit=0;
  for(k=0;k<nf;k++)
  {
   if(pages[i]==frame[k])
   {
    hit=1;
   }
  }
  if(hit==0)
  {
   frame[j]=pages[i];
   j=(j+1)%nf;
   fault++;
   for(k=0;k<nf;k++)
   {
    printf("%d\t\t",frame[k]);
   }
   printf("\n");
  }
  else
  {
   printf("HIT\n");
  }
 }
 printf("PAGE FAULTS:%d",fault);
}
