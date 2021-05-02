#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int N, a[250], dp[250][250], ret;
int main() {
	cin >> N;
	rep(i, 0, N) { cin >> a[i]; dp[i][i] = a[i]; }
	rep(sz, 0, N) {
		rep(i, 0, N - sz) {
			rep(j, i, i + sz) {
				if (dp[i][j] == dp[j + 1][i + sz] && dp[i][j]) {
					dp[i][i + sz] = max(dp[i][i + sz], dp[i][j] + 1);
				}
			}
			ret = max(ret, dp[i][i + sz]);
		}
	}
	cout << ret;
}