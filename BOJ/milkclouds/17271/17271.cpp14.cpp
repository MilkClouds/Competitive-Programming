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
const ll MOD = 1e9 + 7;

ll N, M, dp[10005];

ll f(ll N){
	if(N < 0) return 0;
	if(N == 0)return 1;
	ll& ret = dp[N];
	if(ret) return ret;
	return ret = (f(N-1) + f(N-M)) % MOD;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M;
	cout << f(N) << endl;
	return 0;
}
	