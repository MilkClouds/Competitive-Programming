#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

int TC, N, M, a, p,q;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> TC;
	while (TC--) {
		cin >> N >> M;
		p = q = 0;
		rep(i, 0, M) {
			cin >> a;
			p = max(p, min(a, abs(a - N)));
			q = max(q, max(a, abs(a - N)));
		}
		cout << p << " " << q << "\n";
	}
}