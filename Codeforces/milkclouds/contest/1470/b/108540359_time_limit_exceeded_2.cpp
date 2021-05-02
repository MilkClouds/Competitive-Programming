#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())  
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAXN = 3e5, MAX = 1e3 + 1;
int TC, N, A[MAXN], B[MAXN], Q, w;
vector<int> pn;
bool arr[MAX];

void eratos() {
	pn.push_back(2);
	for (int i = 3; i < MAX; i += 2) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i * i; j < MAX; j += i) arr[j] = 1;
	}
}

void solve() {
	cin >> N;
	map<int, int > m;
	int ans = 0, ans2 = 0;
	rep(i, 0, N) {
		cin >> A[i];
		for (auto p : pn) while (A[i] % (p * p) == 0) A[i] /= p * p;
	}
	rep(i, 0, N) {
		m[A[i]]++;
	}
	for (auto i : m) ans = max(ans, i.y);
	for (auto i : m) {
		if (i.y % 2 == 0) {
			m[1] += i.y;
			i.y = 0;
		}
	}
	for (auto i : m) ans2 = max(ans2, i.y);
	cin >> Q;
	while (Q--) {
		cin >> w;
		if (w >= 1) cout << ans2 << "\n";
		else cout << ans << "\n";
	}
}



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> TC;
	eratos();
	while (TC--)solve();
}
