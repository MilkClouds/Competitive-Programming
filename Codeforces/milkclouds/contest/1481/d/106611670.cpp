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

const int MAX = 2e3;

ll N, M, TC;
bool adj[MAX][MAX];
string s;

void solution() {
	cin >> N >> M;
	rep(i, 0, N) {
		cin >> s;
		rep(j, 0, N) {
			if (i == j)continue;
			adj[i][j] = s[j] == 'a';
		}
	}
	rep(i, 0, N) rep(j, i + 1, N) {
		if (adj[i][j] == adj[j][i]) {
			cout << "YES\n";
			rep(k, 0, M + 1) cout << (k % 2 ? i : j) + 1 << " ";
			cout << "\n";
			return;
		}
	}
	if (M % 2) {
		cout << "YES\n";
		rep(k, 0, M + 1) cout << (k % 2 ? 1 : 2) << " ";
		cout << "\n";
		return;
	}
	if (M % 4 == 0) {
		rep(i, 0, N) rep(j, 0, N) {
			if (i == j)continue;
			rep(kk, 0, N) {
				if (kk == j)continue;
				if (adj[i][j] == adj[j][kk]) {
					cout << "YES\n";
					rep(k, 0, M / 2 + 1) cout << (k % 2 ? i : j) + 1 << " ";
					rep(k, 0, M / 2) cout << (k % 2 ? j : kk) + 1 << " ";
					return;
				}
			}
		}
		cout << "NO\n";
		return;
	}
	if (1) {
		rep(i, 0, N) rep(j, 0, N) {
			if (i == j)continue;
			rep(kk, 0, N) {
				if (kk == i)continue;
				if (adj[j][i] == adj[i][kk]) {
					cout << "YES\n";
					rep(k, 0, M / 2 + 1) cout << (k % 2 ? i : j) + 1 << " ";
					rep(k, 0, M / 2) cout << (k % 2 ? i : kk) + 1 << " ";
					return;
				}
			}
		}
		cout << "NO\n";
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> TC;
	while (TC--) {
		solution();
	}
}

