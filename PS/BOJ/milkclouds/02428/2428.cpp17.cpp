#include <bits/stdc++.h>
#pragma warning(suppress : 4996)
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

const int MAX = 1e5 + 1;
ll N, A[MAX], ans;
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	sort(A, A + N);
	rep(i, 0, N) {
		ans += A + i - lower_bound(A, A + i, 0.9 * A[i]);
	}
	cout << ans;
}