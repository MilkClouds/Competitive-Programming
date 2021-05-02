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

ll N,a,b,ans;
map<ll, ll> x, y;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) { cin >> a >> b; x[a]++; y[b]++; }
	for (auto p : x) if (p.y > 1) ans++;
	for (auto p : y) if (p.y > 1) ans++;
	cout << ans;
}