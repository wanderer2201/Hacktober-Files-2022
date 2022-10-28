#include<stdio.h>
int main()
{
    int n,k,i,j,maxAND=0,maxOR=0,maxXOR=0;
    printf("Enter the value of integer and threshold:");
    scanf("%d %d",&n,&k);
    for ( i = 1; i <=n; i++)
    {
        for (j = i+1; j <=n; j++)
        {
            if (maxAND<(i&j) && (i&j)<k)
            maxAND=i&j;
            if(maxOR<(i|j) && (i|j)<k)
            maxOR=i|j;
            if(maxXOR<(i^j) && (i^j)<k)
            maxXOR=i^j;
        }
        
    }
    
    printf("%d ",maxAND);
    printf("%d ",maxOR);
    printf("%d",maxXOR);
    return 0;
}