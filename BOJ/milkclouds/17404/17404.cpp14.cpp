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
const ll MAX = 1e3 + 5, INF = 1e12;

ll N, A[MAX][3], dp[MAX][3], ans = 1e12;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 0, N) cin >> A[i][0] >> A[i][1] >> A[i][2];
	rep(k, 0, 3){
		fill(dp[0], dp[N], INF);
		dp[0][k] = A[0][k];
		rep(i, 1, N){
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + A[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + A[i][1];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + A[i][2];
		}
		rep(i, 0, 3) if(i ^ k) ans = min(ans, dp[N - 1][i]);
	}
	cout << ans << endl;
}