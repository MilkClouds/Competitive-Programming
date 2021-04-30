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


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	ll N, ans =0;
	cin >> N;
	rep(i, 1, N + 1) {
		ll j = i;
		while (j) {
			if(j % 10)ans += (j % 10) % 3 == 0;
			j /= 10;
		}
	}
	cout << ans;
}
