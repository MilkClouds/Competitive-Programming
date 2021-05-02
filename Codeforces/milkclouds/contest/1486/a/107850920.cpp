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



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	ll T, n, C, rem, flag;
	cin >> T;
	while (T--) {
		cin >> n;
		rem = flag = 0;
		rep(i, 0, n) {
			cin >> C;
			if(C > i)rem += C - i;
			else {
				rem -= i - C;
			}
			if (rem < 0)flag = 1;
		}
		cout << (flag ? "NO\n" : "YES\n");
	}
}