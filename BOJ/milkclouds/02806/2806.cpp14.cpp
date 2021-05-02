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
const ll MOD = 1e9 + 7, MAX = 1e6 + 3;

ll N, dp[MAX][2];
string S;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> S;
	dp[0][0] = (S[0] == 'B'); dp[0][1] = !dp[0][0];
	rep(i, 1, N){
		dp[i][0] = dp[i][1] = MOD;
		dp[i][0] = min(dp[i - 1][0] + (S[i]=='B'), dp[i - 1][1] + 1);
		dp[i][1] = min(dp[i - 1][1] + (S[i]=='A'), dp[i - 1][0] + 1);
	}
	cout << dp[N-1][0];
}
	