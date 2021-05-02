#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	vector<vector<int>> dp(n, vector<int>({-INF, INF}));
	vector<vector<int>> p(n, vector<int>(2, -1));
	dp[0][0] = INF;
	dp[0][1] = -INF;
	
	for (int i = 1; i < n; ++i) {
		{
			if (a[i] > a[i - 1] && dp[i][0] < dp[i - 1][0]) {
				dp[i][0] = dp[i - 1][0];
				p[i][0] = 0;
			}
			if (a[i] < dp[i - 1][0] && dp[i][1] > a[i - 1]) {
				dp[i][1] = a[i - 1];
				p[i][1] = 0;
			}
		}
		{
			if (a[i] < a[i - 1] && dp[i][1] > dp[i - 1][1]) {
				dp[i][1] = dp[i - 1][1];
				p[i][1] = 1;
			}
			if (a[i] > dp[i - 1][1] && dp[i][0] < a[i - 1]) {
				dp[i][0] = a[i - 1];
				p[i][0] = 1;
			}
		}
	}
	
	int pos = -1;
	if (dp[n - 1][0] != -INF) {
		pos = 0;
	}
	if (dp[n - 1][1] != INF) {
		pos = 1;
	}
	
	if (pos == -1) {
		cout << "NO" << endl;
		return 0;
	}
	
	vector<int> inInc(n);
	for (int i = n - 1; i >= 0; --i) {
		if (pos == 0) {
			inInc[i] = 1;
		}
		pos = p[i][pos];
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) {
		cout << !inInc[i] << " ";
	}
	cout << endl;
	
	return 0;
}