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

const int MAX = 1e6 + 5;
ll N, B, C, A[3][MAX], ans, tmp;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> B >> C;
	rep(i, 0, N) cin >> A[0][i];
	if (B <= C) {
		rep(i, 0, N) ans += A[0][i];
		cout << ans * B;
		return 0;
	}
	rep(i, 1, N) {
		tmp = min(A[0][i], A[0][i - 1]);
		A[0][i] -= tmp; A[0][i - 1] -= tmp;
		A[1][i] += tmp;
		if (i == 1)continue;
		tmp = min(A[0][i], A[1][i - 1]);
		A[0][i] -= tmp; A[1][i - 1] -= tmp;
		A[2][i] += tmp;
	}
	rep(i, 0, N) {
		ans += A[0][i] * B + A[1][i] * (B + C) + A[2][i] * (B + 2 * C);
	}
	cout << ans;
}