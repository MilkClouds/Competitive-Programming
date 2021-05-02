#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll>;
using pl = pair<ll, ll>;

int TC, N;
ll dp[61][61];

int main() {
	cin.tie(0); cout.tie(0); //ios_base::sync_with_stdio(false);
	while (~scanf("%d", &N) && N) {
		fill(dp[0], dp[N + 1], 0);
		dp[0][0] = 1;
		rep(i, 1, N * 2 + 1) {
			rep(j, i % 2 + i / 2, i + 1) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
		cout << dp[N * 2][N] << "\n";
	}
}