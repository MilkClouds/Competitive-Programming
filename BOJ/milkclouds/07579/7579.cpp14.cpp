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
const ll INF = 3e9, MOD = 1e9 + 7, MAX = 1003;

ll N, M, m[MAX], c[MAX], dp[105][10005], ans = INF;
ll f(ll pos,ll cost){
	if(cost<0)return -INF;
	if(pos==N)return 0;
	ll& ret = dp[pos][cost];
	if(ret) return ret;
	ret = max(f(pos + 1, cost - c[pos]) + m[pos], f(pos + 1, cost));
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M;
	rep(i, 0, N) cin >> m[i];
	rep(i, 0, N) cin >> c[i];
	dp[N-1][c[N-1]]=m[N-1];
	rep(cost, 0, 10001){
		if(f(0, cost) >= M) ans = min(ans, cost);
	}
	cout << ans << endl;
}