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


const int MAX = 1e3 + 1;
int TC, N, X[MAX], Y[MAX];

void solve() {
	cin >> N;
	vector<int> vx, vy;
	rep(i, 0, N) cin >> X[i] >> Y[i];
	rep(i, 0, N) vx.push_back(X[i]);
	rep(i, 0, N) vy.push_back(Y[i]);
	sort(all(vx));
	sort(all(vy));
	if (N & 1) { cout << "1\n"; return; }
	int lx = vx[(vx.size() - 1) / 2], rx = vx[vx.size() / 2];
	int ly = vy[(vy.size() - 1) / 2], ry = vy[vy.size() / 2];
	cout << (rx - lx + 1) * (ry - ly + 1) << "\n";
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> TC;
	while (TC--)solve();
}