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

ll A, B, C, D, N;
long double a, b, c;

void solve() {
	set<long double> ans;
	cin >> A >> B >> C >> D;
	rep(i, -1000'000, 1000'000 + 1) if (A * i * i * i + B * i * i + C * i + D == 0) N = i;
	ans.insert(N);
	a = A;
	b = B + a * N;
	c = C + b * N;
	long double dis = b * b - 4 * a * c;
	if (dis == 0) ans.insert(-b / (2 * a));
	else if (dis > 0) {
		ans.insert((-b + sqrt(dis)) / (2 * a));
		ans.insert((-b - sqrt(dis)) / (2 * a));
	}
	for (auto i : ans)cout << i << " ";
	cout << "\n";
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int TC;
	cin >> TC;
	while (TC--) {
		solve();
	}
}