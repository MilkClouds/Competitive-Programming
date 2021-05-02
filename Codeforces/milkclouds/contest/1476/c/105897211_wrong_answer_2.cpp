#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >= b; a--)
#define pb push_back
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 1e5 + 3;

ll t, n, c[MAX], b[MAX], a[MAX], S[MAX], d[MAX], last, ans;
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
		ans = 0;
		rep(i, 0, n) cin >> c[i];
		rep(i, 0, n) cin >> a[i];
		rep(i, 0, n) {cin >> b[i]; if(b[i] < a[i]) swap(b[i], a[i]);}
		rep(i, 0, n - 1) d[i] = c[i] - (b[i + 1] - a[i + 1] - 1);
		d[n - 1] = c[n - 1];
		rep(i, 0, n) S[i + 1] = S[i] + d[i];
		last = n;
		rep2(i, 1, n - 1) {
			ans = max(ans, 1 + S[last] - S[i + 1] + c[i]);
			if(a[i] == b[i]) last = i;
		}
		ans = max(ans, b[1] - a[1] + 1 + S[last] - S[1]);
		cout << ans << "\n";
	}
}