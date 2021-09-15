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

int TC, x, y, l, r, u, d;
string S;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> TC;
	while (TC--) {
		cin >> x >> y >> S;
		l = r = d = u = 0;
		if (x > 0) rep(i, 0, x) r++;
		else rep(i, 0, -x) l++;
		if (y > 0)rep(i, 0, y) u++;
		else rep(i, 0, -y) d++;
		for (auto s : S) {
			if (s == 'R' && r>0) r--;
			if (s == 'L' && l > 0) l--;
			if (s == 'U' && u > 0) u--;
			if (s == 'D' && d > 0) d--;
		}
		if (r == 0 && l == 0 && u == 0 && d == 0)cout << "YES\n";
		else cout << "NO\n";
	}
}

