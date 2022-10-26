#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array:");
    for( i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for( i = n-1; i>=0 ; i--)
    printf("%d ",a[i]);
    return 0;
}