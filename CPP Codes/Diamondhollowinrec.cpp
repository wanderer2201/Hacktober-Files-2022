#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter row";
    cin>>n;
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j<=n-1-i){
            cout<<"*";
            }
        }
        for(int j=0;j<(2*i)-1;j++)
        {
                cout<<" ";
        }
         for(int j=0;j<n;j++)
        {
            if(i==0&&j==0)
            {
                continue;
            }
            if(j<=n-1-i){
            cout<<"*";
            }
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j<=i){
            cout<<"*";
            }else{
                cout<<" ";
            }
        }
        for(int j=0;j<(2*n-2)/2;j++)
        {
            if(n-i-2<=j)
            {
                 cout<<"*";
            }else
            {
                cout<<" ";
            }
        }
        cout<<"\n";
    }

    return 0;
}
