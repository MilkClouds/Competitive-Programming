# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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
int TC, N, A[MAXN], B[MAXN], Q, rec[10000001];
ll w;
vector<int> pn, ppn;
bool arr[MAX];

void eratos() {
	pn.push_back(2);
	for (int i = 3; i < MAX; i += 2) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i * i; j < MAX; j += i) arr[j] = 1;
	}
}

int f(int x) {
	if (rec[x] == 0) return x;
	return f(x / rec[x]);
}

void solve() {
	cin >> N;
	map<int, int > m;
	int ans = 0, ans2 = 0, tmp = 0;
	rep(i, 0, N) {
		cin >> A[i];
		A[i] = f(A[i]);
	}
	rep(i, 0, N) {
		m[A[i]]++;
	}
	for (auto i : m) ans = max(ans, i.y);
	tmp = m[1];
	for (auto i : m) {
		if (i.y % 2 == 0) {
			tmp += i.y;
			ans2 = max(ans2, tmp);
		}
	}
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
	for (auto i : pn) ppn.pb(i * i);
	for (auto i : ppn) {
		for (ll j = i; j < 1000001; j += i) rec[j] = i;
	}
	while (TC--)solve();
}
