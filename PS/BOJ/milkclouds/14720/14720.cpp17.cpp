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

const int MAX = 1e3 + 1, d[3] = { 1, 2, 0 };
int N, A[MAX], c, ans;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	c = 2;
	rep(i, 0, N) {
		cin >> A[i];
		if (d[c] == A[i]) {
			c = d[c];
			ans++;
		}
	}
	cout << ans;
}