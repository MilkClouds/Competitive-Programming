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
using pi = pair<int, int>;
using ld = long double;

const int MAX = 2e3 + 5;
int N, dp[MAX][MAX], A[MAX], B[MAX], C[MAX];
map<int, int> m;

int solve(int i, int v) {
	if (i == N)return 0;
	if (~dp[i][v])return dp[i][v];
	if (i == 0) return dp[i][v] = solve(i + 1, 0);
	if(v == 0) return dp[i][v] = min(solve(i + 1, v) + abs(A[i - 1] - A[i]), solve(i + 1, B[i - 1]));
	return dp[i][v] = min(solve(i + 1, v) + abs(A[i - 1] - A[i]), solve(i + 1, B[i - 1]) + abs(C[v - 1] - A[i]));
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	fill(dp[0], dp[N + 1], -1);
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) C[i] = A[i];
	sort(C, C + N);
	rep(i, 0, N) m[C[i]] = i + 1;
	rep(i, 0, N) B[i] = m[A[i]];
	cout << solve(0, 0);
}
