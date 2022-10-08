#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=1; i<n; i++){
        //cout<<"\ni= "<<i;
        int current=a[i];

        //cout<<"\ncurrent1 "<<current;
        int j=i-1;
        //cout<<"\nj="<<j;

        while(a[j]>current && j>=0){
            a[j+1]=a[j];
            //cout<<"\na[j+1]="<<a[j+1];
            j--;
            //cout<<"\nj--= "<<j;

        }
        a[j+1]=current;
        //cout<<"\n a[j+1]=current= "<<a[j+1];

    }

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;
    return 0;
}

// Give direct input- first enter number of elements, then enter the elements.
//------Time Complexity-----
// O(n)
