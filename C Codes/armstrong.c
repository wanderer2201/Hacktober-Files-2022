#include<stdio.h>
int main()
{
    int n,rem,i,num;
    for( i=100; i<=500; i++)
    {  num=0;
      n=i;
      while(n!=0) {
      rem=n%10;
      num=num+rem*rem*rem;
      n=n/10; }
      if(i==num)
      printf("%d\n",i);
    }
  return 0;    
}