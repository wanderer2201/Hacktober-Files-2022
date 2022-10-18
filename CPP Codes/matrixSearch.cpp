#include<iostream>
#include<climits>
using namespace std;
int main()
{
int n,m,target;
cin>>n>>m>>target;
int arr[n][m];

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
        cin>>arr[i][j];
}

int r=0,c=m-1;
while(r<n && c>=0)
{
    if(arr[r][c]==target)
    {
        cout<<"element found";
        return 0;
    }    
    if(arr[r][c]>target)
    c--;
    else
    r++;

       

}

cout<<"The element is not found";
return 0;
}
