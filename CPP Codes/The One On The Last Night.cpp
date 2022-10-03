#include "bits/stdc++.h"
#define tc int t; cin >> t; while(t--)
#define ll long long int
#define pb push_back
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define N 1e6
#define M 1000000007
#define endl '\n'

using namespace std;

void solve(){
    int n,k; cin >> n >> k;
    ll ans = 1;
    vector<int> v;
    while(n){
        v.pb(n%10);
        n/=10;
    }
    for(int i = 0; i<k; ++i){
        int a = min_element(v.begin(),v.end()) - v.begin();
        if(v[a] == 9) continue;
        v[a]++;
    }
    for(auto &it : v){
        ans*=it;
    } cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    tc{
        solve();    
    }

return 0;
}
