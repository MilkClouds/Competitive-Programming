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
using ld = long double;

ll N, M, K, ans = 1, C[2001][2001];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> K >> M;
	rep(i, 0, 2001) C[i][0] = C[i][i] = 1;
	rep(i, 1, 2001) rep(j, 1, i + 1) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
	while (N) {
		ans *= C[N % M][K % M];
		ans %= M;
		N /= M;
		K /= M;
	}
	cout << ans;
}