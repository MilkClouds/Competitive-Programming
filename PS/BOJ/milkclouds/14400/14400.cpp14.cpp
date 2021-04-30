# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const int MAX = 1e5+1;

ll n,x[MAX],y[MAX],a,b,c;
ll cost(ll x[], ll p){
	ll ret = 0;
	rep(i, 0, n) ret += abs(x[i] - p);
	return ret;
}
ll find(ll x[]){
	int lo = -1e6-3, hi = 1e6+3;
	while(lo+2<hi){
		int p = (lo*2+hi)/3, q=(lo+hi*2)/3;
		ll a = cost(x,p), b=cost(x,q);
		if(a<b) hi=q;
		else lo=p;
	}
	ll ans = 1e12;
	rep(i,lo,hi+1) ans = min(ans, cost(x,i));
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	rep(i, 0, n){
		cin >> x[i] >> y[i];
	}
	cout << find(x) + find(y);
}