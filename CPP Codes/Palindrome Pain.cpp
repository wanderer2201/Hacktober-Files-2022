// Stay Strong 
#include<bits/stdc++.h>
typedef long long ll;
#define vi vector<ll>
#define vpi vector<pair<ll,ll>>
#define pi pair<ll,ll>
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define rrep(i,a,b) for (ll i=b;i>=a;i--)
#define fi first
#define se second
#define pb emplace_back
#define mp make_pair
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace  __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order , order_of_key

int main(){
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t;
	while(t--) {
	    ll a,b;
	    cin>>a>>b;
	    if (a%2 && b%2) cout<<-1<<"\n";
	    else if (a==1 || b==1) cout<<-1<<"\n";
	    else {
	        ll i = 0;
	        ll j = a+b-1;
	        ll a1=a;
	        ll b1=b;
	        string ans1(a+b,'$');
	        string ans2(a+b,'$');
	        while (i<j) {
	            if (a>1) {
	                ans1[i] = 'a';
	                ans1[j] = 'a';
	                i++;
	                j--;
	                a-=2;
	            }
	            else if (b>1) {
	                ans1[i] = 'b';
	                ans1[j] = 'b';
	                i++;
	                j--;
	                b-=2;
	            }
	        }
	        if (a) ans1[j]='a';
	        if (b) ans1[j]='b';
	        i=0,j=a1+b1-1;
	        while (i<j) {
	            if (b1>1) {
	                ans2[i] = 'b';
	                ans2[j] = 'b';
	                i++;
	                j--;
	                b1-=2;
	            }
	            else if (a1>1) {
	                ans2[i] = 'a';
	                ans2[j] = 'a';
	                i++;
	                j--;
	                a1-=2;
	            }
	        }
	        if (a1) ans2[j] = 'a';
	        if (b1) ans2[j] = 'b';
	        cout<<ans1<<"\n";
	        cout<<ans2<<"\n";
	    }
	}
}
