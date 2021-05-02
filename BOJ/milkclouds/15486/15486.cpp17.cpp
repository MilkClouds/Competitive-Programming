#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b; a < c; a++)
#define rep2(a,b,c) for(int a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 15e5 + 2;
int N, T[MAX], P[MAX], dp[MAX];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 1, N + 1) cin >> T[i] >> P[i];
	rep2(i, 1, N + 1) {
		dp[i] = dp[i + 1];
		if (i + T[i] - 1 > N)continue;
		dp[i] = max(dp[i], P[i] + dp[i + T[i]]);
	}
	cout << dp[1];
}