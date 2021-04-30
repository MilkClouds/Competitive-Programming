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
const int MAX = 2e3 + 3;

//16 min, 1 WA

ll x, m, n, A[MAX], B[MAX], S_A[MAX], S_B[MAX], ans;
map<ll, ll> mm_A, mm_B;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> x >> m >> n;
	rep(i, 0, m) {
		cin >> A[i]; A[i + m] = A[i];
	}
	rep(i, 0, n) {
		cin >> B[i];
		B[i + n] = B[i];
	}
	rep(i, 0, m * 2) S_A[i + 1] = S_A[i] + A[i];
	rep(i, 0, n * 2) S_B[i + 1] = S_B[i] + B[i];
	mm_A[0]++; mm_B[0]++;
	rep(i, 0, m) rep(j, i, m * 2) {
		if (j - i >= m) continue;
		mm_A[S_A[j + 1] - S_A[i]]++;
	}
	mm_A[S_A[m]] = 1;
	rep(i, 0, n) rep(j, i, n * 2) {
		if (j - i >= n) continue;
		mm_B[S_B[j + 1] - S_B[i]]++;
	}
	mm_B[S_B[n]] = 1;
	for (auto p : mm_A) {
		ans += mm_B[x - p.x] * p.y;
	}
	cout << ans;
}