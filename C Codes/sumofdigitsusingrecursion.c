#include<stdio.h>
int sum(int a);
int main()
{
    int n,s;
    scanf("%d",&n);
    s=sum(n);
    printf("%d",s);   
   return 0;
}
int sum(int a)
{
   if(a==0)
   return 0;
   else 
   return (a%10 +sum(a/10));  
}