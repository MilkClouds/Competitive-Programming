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

ll N, C, total_C, l, r, m;
map<pl, ll> M;

int get(int l, int r) {
	if (M[{l, r}]) return M[{l, r}];
	if (l == r)return -1;
	cout << "? " << l << " " << r << "\n";
	cout.flush();
	cin >> C;
	M[{ l, r }] = C;
	return C;
}



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	total_C = get(1, N);
	if (get(1, total_C) == total_C) {
		l = 1; r = total_C;
		while (l + 1 < r) {
			m = l + r >> 1;
			if (get(m, total_C) == total_C) l = m;
			else r = m;
		}
		cout << "! " << l;
	}
	else {
		l = total_C + 1; r = N;
		while (l < r) {
			m = l + r >> 1;
			if (get(total_C, m) == total_C) r = m;
			else l = m + 1;
		}
		cout << "! " << l;
	}
}