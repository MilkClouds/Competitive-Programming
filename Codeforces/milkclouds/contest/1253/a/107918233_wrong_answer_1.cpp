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

const int MAX = 1e5 + 5;
int TC, N, a[MAX], b[MAX];
void solve() {
	cin >> N;
	set<int> S;
	rep(i, 0, N)cin >> a[i];
	rep(i, 0, N)cin >> b[i];
	rep(i, 0, N)if (a[i] ^ b[i]) {
		if (a[i] > b[i]) {
			cout << "NO\n"; return;
		}
		S.insert(b[i] - a[i]);
	}
	cout << (S.size() <= 1 ? "YES" : "NO") << "\n";
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> TC;
	while (TC--)solve();
}