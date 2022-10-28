#include<stdio.h>
int main()
{
    int i,n,rev,rem;
    for ( i=100; i<=500; i++)
    { n=i;
    rev=0;
      while(n!=0) {
      rem=n%10;
      rev=rev*10+rem;
      n=n/10; }
      if(i==rev) {
      printf("%d\n",i); }
    }
  return 0;    
}