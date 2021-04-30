#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

const int MAXM = 26, MAXN = 1e5 + 1;
const ll INF = 1e15;

int N, M, K;
ll a[MAXM][MAXM], ans = INF, trans[MAXN][MAXM], sum[MAXN][MAXM], dp[MAXN][MAXM];
string S;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> M >> K >> S;
	rep(i, 0, M) rep(j, 0, M) cin >> a[i][j];
	rep(m, 0, M) rep(i, 0, M) rep(j, 0, M) a[i][j] = min(a[i][j], a[i][m] + a[m][j]);
	rep(i, 0, N) rep(j, 0, M) trans[i][j] = a[S[i] - 'a'][j];
	rep(i, 0, N) rep(j, 0, M) sum[i + 1][j] = sum[i][j] + trans[i][j];
	rep(i, 0, K) rep(j, 0, M) dp[i][j] = INF;
	rep(i, 0, M) dp[K - 1][i] = sum[K - 1 + 1][i];
	rep(i, K, N) {
		rep(j, 0, M) {
			dp[i][j] = dp[i - 1][j] + trans[i][j];
			rep(j2, 0, M) {
				dp[i][j] = min(dp[i][j], dp[i - K][j2] + sum[i + 1][j] - sum[i - K + 1][j]);
			}
		}
	}
	rep(i, 0, M) ans = min(ans, dp[N - 1][i]);
	cout << ans;
}