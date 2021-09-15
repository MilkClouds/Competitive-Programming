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

const int MAX = 1e5 + 3;

int TC, N, M, a[MAX], b[MAX], c[MAX], ans[MAX], flag;
vector<int> v[MAX], v2[MAX];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> TC;
	while (TC--) {
		cin >> N >> M;
		flag = 0;
		rep(i, 1, N + 1) { v[i].clear(); v2[i].clear(); }
		fill(ans, ans + M, 0);
		rep(i, 0, N) cin >> a[i];
		rep(i, 0, N) cin >> b[i];
		rep(i, 0, M) cin >> c[i];
		rep(i, 0, N) {
			if (a[i] ^ b[i]) v[b[i]].push_back(i);
			v2[b[i]].push_back(i);
		}
		rep(i, 0, M) {
			int sz = v[c[i]].size();
			int sz2 = v2[c[i]].size();
			if (sz) {
				ans[i] = v[c[i]][sz - 1] + 1;
				v[c[i]].pop_back();
			}
			else if (sz2) {
				ans[i] = v2[c[i]][sz2 - 1] + 1;
			}
			else if (i == M - 1) {
				flag = 1;
				break;
			}
		}
		rep(i, 0, N) if (v[i + 1].size()) flag = 1;
		if (flag) { cout << "NO\n"; continue; }
		cout << "YES\n";
		rep(i, 0, M) {
			if (ans[i]) cout << ans[i] << " ";
			else cout << ans[M - 1] << " ";
		}
		cout << "\n";
	}
}

