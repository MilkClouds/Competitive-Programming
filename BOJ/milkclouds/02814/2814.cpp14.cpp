# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int MAX=sqrt(1e9);
ll N,P,arr[MAX],cnt,pos;
vector<ll> pn={2};
void sieve(){
	for(ll i=3;i<MAX;i+=2){
		if(arr[i])continue;
		pn.pb(i);arr[i]=1;
		for(ll j=i*i;j<MAX;j+=i)arr[j]=1;
	}
}
ll recursive(ll x,ll p,ll div){
	if(x<div)return 0;
	ll ret=x/div;
	rep(i,p,pos){
		ret-=recursive(x,i+1,div*pn[i]);
	}
	return ret;
}
ll calculate(ll x){
	return recursive(x,0,P);	
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	sieve();
	cin>>N>>P;
	pos=lower_bound(all(pn),P)-pn.begin();
	if(pos==pn.size()){
		if(N==1)cout<<P;
		else cout<<0;
		return 0;
	}
	if(N==1){
		cout<<P;
		return 0;
	}
	ll lo=P, hi=((double)1e9)/P+1, end=hi;
	while(lo<hi){
		ll m=lo+hi>>1;
		if( calculate(m*P) >= N ) hi=m;
		else lo=m+1;
	}
	cout<<(hi==end?0:hi*P);
}
	