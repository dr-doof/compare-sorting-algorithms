#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(int argc, char *argv[])
{
  long long int c[5]={0,0,0,0,0};
  int n=0,i=0;
  double t[5],clk[6];
  while(argv[1][i] != 0)
  {
    n*=10;
    n+=argv[1][i]-48;
    i++;
  }

  int a1[n],b1[n],c1[n],d1[n],e1[n];
  for(i=0;i<n;i++)
  {
    a1[i]=b1[i]=c1[i]=d1[i]=e1[i]=rand()%10;
  }

  int p;
  clk[0]=clock();
  c[0]=bubble_sort(a1,n);
  clk[1]=clock();
  c[1]=insertion_sort(b1,n);
  clk[2]=clock();
  c[2]=merge_sort(c1,0,n-1);
  clk[3]=clock();
  c[3]=quick_sort(d1,0,n-1);
  clk[4]=clock();
  c[4]=selection_sort(e1,n);
  clk[5]=clock();

  for(i=0;i<5;i++)
  {
    t[i]=clk[i+1]-clk[i];
  }

  printf("%d",n);
  for(i=0;i<5;i++)
  {
    printf("\t%lld",c[i]);
  }
  for(i=0;i<5;i++)
  {
    printf("\t%lf",t[i]);
  }
  printf("\n");
}
