#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define FOR(i,j,k) for(ll i=j;i<k;i++)
#define FORD(i,j,k) for(ll i=j;i>=k;i--)
#define REP(i,n) for(ll i=0;i<n;i++)
const ll N=1e6+7;
const ld eps=1e-6;
const ll mod=1e9+7;
const ld PI = 3.14159265358979323846;
void printv(vector<ll>&v,ll s, ll e){
	FOR(i,s,e){
		if(i==e-1) cout<<v[i];
		else cout<<v[i]<<" ";
	}
	cout<<"\n";
}
// *******************************************************************************************



void solve(){
	ll a,b,n;
	cin>>a>>b>>n;
	if(a==b){
		cout<<0<<endl;
		return;
	}
	ll c=a^b;
	if(c<n){
		cout<<1<<endl;
		return;
	}else{
		ll ct=0;
		while(c){
			ct++;
			c>>=1;
		}
		ll d=1<<(ct-1);
		if(d<n){
			cout<<2<<endl;
			return;
		}else{
			cout<<-1<<endl;
			return;
		}
	}
}



// *******************************************************************************************
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    ll tc;
    cin>>tc;
    for(ll t=1;t<=tc;t++){
    	solve();
    }
    return 0;
}
