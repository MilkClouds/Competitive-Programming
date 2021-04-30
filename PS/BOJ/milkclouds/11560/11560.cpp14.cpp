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
const ll INF = 3e9, MOD = 1e9 + 7, MAX = 1e6, LIM=1e17;

// dp[k][n] : 1+x+..x^k항까지 곱했을때 x^0,x^1,..x^n 계수 합
struct bigint{
	ll a,b;
	bigint():bigint(0,0){}
	bigint(ll x):bigint(0,x){}
	bigint(ll a,ll b):a(a),b(b){}
	ll toll(){
		return a * LIM + b;
	}
	bigint operator + (bigint o){
		if(b + o.b > LIM){
			return {a + o.a + 1, b + o.b - LIM};
		}
		return {a + o.a, b + o.b};
	}
	bigint operator - (bigint o){
		if(b - o.b < 0){
			return {a - o.a - 1, LIM + b - o.b};
		}
		return {a - o.a, b - o.b};
	}
} dp[21][211];
ll T, k, N;
bigint range(bigint* a, ll l, ll r){ l--;
	if(l<0)return a[r];
	return a[r] - a[l];
}
void f(ll k){
	rep(i, 0, k * (k + 1) / 2 + 1){
		if(i) dp[k][i] = dp[k][i - 1] + range(dp[k - 1], i - k, i);
		else dp[k][i] = range(dp[k - 1], i - k, i);
	}
	rep(i, k * (k + 1) / 2 + 1, 211) dp[k][i] = dp[k][k * (k + 1) / 2];
	if(k<20) f(k + 1);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> T;
	dp[1][0] = 1;
	rep(i, 1, 211) dp[1][i] = 2;
	f(2);
	while(T--){
		cin >> k >> N;
		if(N) cout << (dp[k][N] - dp[k][N - 1]).toll() << "\n";
		else cout << dp[k][N].toll() << "\n";
	}
}
	