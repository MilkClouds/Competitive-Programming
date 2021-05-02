#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
 
using namespace std;
typedef long long ll;
 
int TC, n, m, a[105], b[105], p, q, c[105], d[105];
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> TC;
	while(TC--){
		p = q = 0;
		cin >> n;
		rep(i, 0, n) cin >> a[i];
		cin >> m;
		rep(i, 0, m) cin >> b[i];
		c[0] = d[0] = 0;
		rep(i, 1, n + 1) c[i] = c[i - 1] + a[i - 1];
		rep(i, 1, m + 1) d[i] = d[i - 1] + b[i - 1];
		rep(i, 0, n + 1) p = max(p, c[i]);
		rep(i, 0, m + 1) q = max(q, d[i]);
		cout << max(0, p + q) << "\n";
	}
}
