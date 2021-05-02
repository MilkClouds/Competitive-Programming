#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;
const ll MAX = 5e3 + 3, MOD = 1e9 + 7;

ll N, M, u, v, par[MAX], cnt;

ll find(ll x){
	if(x == par[x]) return x;
	ll p = find(par[x]);
	par[x] = p;
	return p;
}
void merge(ll x, ll y){
	x = find(x); y = find(y);
	if(x ^ y) {
		par[y] = x;
		cnt--;
	}
}
ll pow2(ll x, ll n){
	if(n == 0)return 1;
	if(n == 1)return x;
	ll temp = pow2(x, n / 2);
	temp = (temp * temp) % MOD;
	if(n & 1) return (temp * x) % MOD;
	return temp;
}
ll fact[MAX], fact_inv[MAX], dp[MAX];
ll comb(ll n, ll k){
	return ((fact[n] * fact_inv[n - k]) % MOD) * fact_inv[k] % MOD;
}
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	fact[0] = fact_inv[0] = 1;
	rep(i, 1, MAX) fact[i] = (i * fact[i - 1]) % MOD;
	rep(i, 1, MAX) fact_inv[i] = pow2(fact[i], MOD - 2);
	dp[0] = dp[1] = 1; dp[2] = 2;
	rep(n, 2, MAX){
		rep(k, 0, n + 1) dp[n + 1] = (dp[n + 1] + comb(n, k) * dp[n - k] % MOD) % MOD;
	}
	cin >> N >> M;
	rep(i, 0, N + 1) par[i] = i;
	cnt = N;
	while(M--){
		cin >> u >> v;
		merge(u, v);
		cout << dp[cnt] << "\n";
	}
}