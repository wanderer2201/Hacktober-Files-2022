// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long prod=1;
	    long long ans=INT_MIN;
	    long long ans1=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        prod*=arr[i];
	        ans=max(prod,ans);
	        if(arr[i]==0)
	        {
	            prod=1;
	        }
	    }
	    
	    prod=1;
	    for(int i=n-1;i>0;i--)
	    {
	        prod*=arr[i];
	        ans1=max(prod,ans1);
	        if(arr[i]==0)
	        {
	            prod=1;
	        }
	    }
	    long long final=INT_MIN;
	    final=max(ans,ans1);
	    
	    return final;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends