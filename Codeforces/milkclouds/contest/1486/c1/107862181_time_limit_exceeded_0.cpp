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
	cout << "! " << l << " " << r << "\n";
	cout.flush();
	cin >> C;
	M[{ l, r }] = C;
	return C;
}



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	total_C = get(1, N);
	l = 1; r = N;
	while (l < r) {
		m = l + r >> 1;
		if (r - l == 1) {
			if (get(l, r) == l) l = r;
			else r = l;
			break;
		}
		if (total_C <= m) {
			if (get(total_C, r) == total_C) l = total_C;
			else { r = total_C - 1; total_C = get(l, r); }
		}
		else {
			if (get(l, total_C) == total_C) r = total_C;
			else {
				l = total_C + 1; total_C = get(l, r);
			}
		}
	}
	cout << l;
}