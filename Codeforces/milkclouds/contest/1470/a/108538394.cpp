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

const int MAX = 3e5;
const ll INF = 1e16;
int TC, N, M, K[MAX], C[MAX], cur, A[MAX];
ll ans;

void solve() {
	cin >> N >> M;
	rep(i, 0, N) {
		cin >> K[i]; K[i]--;
	}
	rep(i, 0, M) cin >> C[i];
	sort(K, K + N);
	ans = cur = 0;
	rep(i, 0, N) A[i] = C[K[i]];
	rep2(i, 0, N) {
		if (A[i] > C[cur]) A[i] = C[cur++];
	}
	rep(i, 0, N) ans += A[i];
	cout << ans << "\n";
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> TC;
	while (TC--)solve();
}
