#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tll = tuple<ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;

const int MAX = 5e5 + 5;
ll N, A[MAX], dp[MAX], l[MAX], r[MAX], f[MAX];
map<ll, ll> m;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 1, N + 1) cin >> A[i];
	rep(i, 1, N + 1) {
		if (!l[A[i]]) l[A[i]] = i;
		r[A[i]] = i;
		f[A[i]]++;
	}
	rep2(i, 1, N + 1) {
		m[A[i]]++;
		dp[i] = dp[i + 1];
		if (l[A[i]] == i) dp[i] = max(dp[i], dp[r[A[i]] + 1] + f[A[i]]);
		else dp[i] = max(dp[i], m[A[i]]);
	}
	cout << N - dp[1];
}