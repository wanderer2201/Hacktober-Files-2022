class Solution {
public:
    int nthUglyNumber(int n) {
     vector<int> ans(n);
    int x=0,y=0,z=0;
    ans[0]=1;
    for(int i=1;i<n;i++)
    {
        ans[i]=min(ans[x]*2,min(ans[y]*3,ans[z]*5));
        if(ans[i]==2*ans[x])x++;
        if(ans[i]==3*ans[y])y++;
        if(ans[i]==5*ans[z])z++;
    }
    return ans[n-1];   
    }
};
