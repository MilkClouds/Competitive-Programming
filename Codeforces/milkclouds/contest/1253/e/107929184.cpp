#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b; a < c; a++)
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

const int INF = 1e9, MAX = 81;
int N, M, X[MAX], S[MAX], dp[100005];
pi A[MAX];



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	rep(i, 0, N) cin >> A[i].x >> A[i].y;
	sort(A, A + N);
	rep(i, 0, N) { X[i] = A[i].x; S[i] = A[i].y; }
	dp[M] = 0;
	rep2(i, 0, M) {
		dp[i] = M - i;
		rep(ant, 0, N) {
			int l = X[ant] - S[ant], r = X[ant] + S[ant];
			if (l <= i + 1 && i + 1 <= r)dp[i] = min(dp[i], dp[i + 1]);
			else if (i + 1 < l) {
				int tmp = l - i - 1;
				dp[i] = min(dp[i], dp[min(M, r + tmp)] + tmp);
			}
		}
	}
	cout << dp[0];
}