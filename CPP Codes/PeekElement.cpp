#include <iostream>
using namespace std;


int peekelement(int a[],int n,int start,int end)
{
    int mid=(start+end)/2;

    if((mid==0 || a[mid-1]<=a[mid])  && (mid==n-1 || a[mid+1]<=a[mid]))
    {
        return mid;
    }
    else if(mid>0 || a[mid-1]>a[mid])
    {
        return peekelement(a,n,start,mid-1);
    }
    else
    {
        return peekelement(a,n,mid+1,end);
    }
}

int main()
{
    int a[]={4,5,9,6,7,8};
    int n=6;

    cout<<peekelement(a,n,0,5);
}