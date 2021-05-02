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

int TC, N, K, A[101];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> TC;
	while (TC--) {
		cin >> N >> K;
		rep(i, 0, N) cin >> A[i];
		int flag = 0, save = 0;
		rep(_, 0, K) {
			rep(i, 0, N) {
				if (i == N - 1) { flag = 1; break; }
				if (A[i] >= A[i + 1]) continue;
				A[i]++;
				save = i;
				break;
			}
			if (flag)break;
		}
		if (flag) cout << "-1\n";
		else cout << save + 1 << "\n";
	}
}

