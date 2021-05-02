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
const ll INF = 1e9, MOD = 1e9 + 7, MAX = 15e6 + 10;

bool arr[MAX];
vector<ll> pn;
void erato(){
	for(ll i = 2; i < MAX; i++){
		if(arr[i])continue;
		pn.pb(i);
		for(ll j = i * i; j < MAX; j += i){
			arr[j] = 1;
		}
	}
}
ll pow(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b&1) ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1; 
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	erato();
	ll N, M, ans = 1;
	cin >> N >> M;
	if(N > M) swap(N, M);
	rep(i, 2, N + 1) if(!arr[i])
		for(ll j = i; j <= N; j *= i){
			ans = (ans * pow(i, (N / j) * (M / j))) % MOD;
		}
	cout << ans;
}
	