#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 4003;

ll n, a[MAX][4], ret, save, j;
vector<ll> v, v2;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n;
	rep(i, 0, n)rep(j, 0, 4) cin >> a[i][j];
	rep(i, 0, n)rep(j, 0, n) v.pb(- a[i][0] - a[j][1]);
	rep(i, 0, n)rep(j, 0, n) v2.pb(a[i][2] + a[j][3]);
	sort(all(v)); sort(all(v2));
	rep(i, 0, n*n) {
		if (i > 0 && v[i] == v[i - 1]) {
			ret += save; continue;
		}
		while (j < n*n && v2[j] < v[i]) j++;
		save = 0;
		while (j < n*n && v2[j] == v[i]) { j++; save++; }
		ret += save;
	}
	cout << ret;
}