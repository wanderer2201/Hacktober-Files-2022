#include<stdio.h>
int main()
{
    int i,j,n,temp;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array:");
    for ( i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);    }
    for ( i = 1; i<=n; i++)
    {
        for (j = i+1; j<=n; j++)
        {
            if(a[i]>a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp; }
           
        }
        
    }
    printf("The array after sorting is = ");
    for ( i = 1; i <=n; i++)
    {
        printf("%d ",a[i]);
    }
    
    
    
    return 0;
}
