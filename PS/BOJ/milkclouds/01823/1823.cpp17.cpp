#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MAX = 2e3 + 3;

ll N, v[MAX], dp[MAX][MAX];

ll solve(ll i, ll j){
	if(i == j) return 0;
	if(dp[i][j]) return dp[i][j];
	ll k = N - j + i + 1;
	ll ret = max(solve(i + 1, j) + v[i] * k, solve(i, j - 1) + v[j - 1] * k);
	return dp[i][j] = ret;
}

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) cin >> v[i];
	cout << solve(0, N);
}