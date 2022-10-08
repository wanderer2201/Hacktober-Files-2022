#include<stdio.h>
int temp[10] , k=0;
void topo(int n , int indegree[10] , int a[10][10])
{
    int i , j;    
    for(int i=1 ; i<=n  ; i++)
    {
        if(indegree[i]==0)
        {
            indegree[i]=1;
            temp[++k]=i;
            for(int j=1 ; j<=n ; j++)
            {
                if(a[i][j]==1 && indegree[j]!=-1)
                {
                    indegree[j]--;
                }
            }
             i=0;
        }
    }
}
int main()
{
    int i , j ,n ,  indegree[10] ,a[10][10];
    printf("\nENTER THE NUMBER OF VERTICES");
    scanf("%d" , &n);

    for(int i=1 ; i<=n ; i++) indegree[i]=0;

    printf("\nENTER THE ADJACENT MATRIX ; \n");
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            scanf("%d" , &a[i][j]);
            if(a[i][j]==1)
            {
                indegree[j]++;
            }

        }
    }
    topo(n , indegree , a);
            if(k!=n)
            {
                printf("\nNOT POSSIBLE");
            }
            else
            {
                printf("\nORDERING IS : \n");
                for(int i=1 ; i<=k ; i++)
                {
                    printf("%Vd   " , temp[i]);
                }
            }

}
