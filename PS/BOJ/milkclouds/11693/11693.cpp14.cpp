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
const ll INF = 1e9, MOD = 1e9 + 7, MAX = 1e5;

bool arr[MAX];
ll tmp = 1;
vector<ll> pn = {2};
// tau(n^m)
ll npow(ll a,ll b){
	if(b==0)return 1;
	if(b==1)return a;
	return ((b%2 ? a : 1LL) * npow(a*a%MOD,b/2)) % MOD;
}
ll geosum(ll a,ll r,ll n){
	tmp = (tmp * (r - 1)) % MOD;
	return npow(r,n)-1;
}
void erato(){
	for(ll i = 3; i < MAX; i++){
		if(arr[i])continue;
		pn.pb(i);
		for(ll j = i * i; j < MAX; j += i) arr[j] = 1;
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	erato();
	ll n, m, ret = 1;
	cin >> n >> m;
	for(auto x : pn){
		if(x > n)break;
		if(n % x)continue;
		ll cnt = 0;
		while(n%x == 0){
			n /= x;
			cnt++;
		}
		ret *= geosum(1, x, m*cnt+1);
		ret %= MOD;
	}
	if(n>1) ret *= geosum(1, n, m + 1); ret%=MOD;
	tmp = npow(tmp, MOD - 2);
	cout << ret * tmp % MOD;
}
	