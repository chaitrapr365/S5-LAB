#include<stdio.h>
int np,nf,frame[20],pages[100],in,fault=0,hit,i,j,k,min,time[200],fr,pa,p,f;
int id;
void input()
{
 printf("ENTER THE NO OF FRAMES:");
 scanf("%d",&nf);
 for(i=0;i<nf;i++)
 {
  frame[i]=-1;
 }
 printf("ENTER THE NO OF PAGES:");
 scanf("%d",&np);
 printf("ENTER THE REFERENCE STRING:");
 for(i=0;i<np;i++)
 {
  scanf("%d",&pages[i]);
  printf("%d",pages[i]);
 }
}
int leastrecent()
 {
  id=-1;
  min=50;
  for(f=0;f<nf;f++)
  {
   fr=frame[f];
   if(time[fr]<min)
   {
    min=time[fr];
    id=f;
   }
   return id;
 }}
void lru()
{
 printf("REFERENCE STRING\tFRAME 1\t\tFRAME 2\t\tFRAME 3");
 for(j=0,p=0;p<np;p++)
 {
  printf("\n%d\t\t\t",pages[i]);
  hit=0;
  pa=pages[p];
  time[pa]=p;
  for(f=0;f<nf;f++)
  {
   if(pages[p]==frame[f])
   {
    hit=1;
    break;
   }
  }
  if(hit==1)
  {
   printf("HIT");
  }
  else
  {
   frame[j]=pages[i];
   fault++;
   if(frame[j+1]==-1)
   {
    j++;
   }
   else
   {
    j=leastrecent();
   }
   for(k=0;k<nf;k++)
   {
    printf("%d\t\t",frame[k]);
   }
   printf("\n");
  }}
 }
 
void main()
 {
  input();
  lru();
  printf("PAGE FAULTS:\n",fault);
  }


