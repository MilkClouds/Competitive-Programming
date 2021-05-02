#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
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

ll N;
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 666, (ll)1 << 31) {
		ll j = i, cnt = 0, flag = 0;
		while (j) { if (j % 10 == 6)cnt++; else cnt = 0; if (cnt >= 3)flag = 1; j /= 10; }
		if (flag) {
			N--;
			if (N == 0) {
				cout << i;
				break;
			}
		}
	}
}