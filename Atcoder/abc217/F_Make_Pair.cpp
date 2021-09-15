#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MOD = 998244353;
int N, M, u, v, can[500][500];
ll dp[500][500], binom[500][500];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
	binom[0][0] = 1;
	rep(i, 1, N + 1){
		binom[i][0] = binom[i][i] = 1;
		rep(j, 1, i) binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
	}
    rep(i, 0, M){
        cin >> u >> v; u--; v--;
        can[u][v] = can[v][u] = 1;
    }
	rep(i, 0, 2 * N + 1) dp[i][0] = 1;
	rep(j, 1, N + 1){
		rep(i, 0, 2 * (N - j) + 1){
			rep(k, 0, j){
				if(can[i][i + 2 * k + 1]){
					dp[i][j] += (dp[i + 1][k] * dp[i + 2 * (k + 1)][j - k - 1]) % MOD * binom[j][k + 1] % MOD;
					dp[i][j] %= MOD;
				}
			}
		}
	}
	cout << dp[0][N] << endl;
}
