#include<stdio.h>
int gcd(int a,int b);
int main()
{
    int n1,n2,x;
    scanf("%d",&n1);
    scanf("%d",&n2);
    x=gcd(n1,n2);
    printf("%d",x);
   return 0;
}
int gcd(int a,int b)
{
    if(b!=0)
    return gcd(b, a%b);
    else 
    return a;
}