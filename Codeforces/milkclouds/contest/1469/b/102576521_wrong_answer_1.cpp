#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
 
using namespace std;
typedef long long ll;
 
int TC, n, m, a[105], b[105], p, q;
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> TC;
	while(TC--){
		p = q = 0;
		cin >> n;
		rep(i, 0, n) cin >> a[i];
		cin >> m;
		rep(i, 0, m) cin >> b[i];
		rep(i, 1, n) a[i] += a[i - 1];
		rep(j, 1, m) b[j] += b[j - 1];
		rep(i, 1, n) p = max(p, a[i]);
		rep(i, 1, m) q = max(q, b[i]);
		cout << p + q << "\n";
	}
}
