#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 102;

ll t, n, k, p[MAX], S[MAX], add[MAX], ans;
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> k;
		ans = 0;
		fill(S, S + n, 0);
		rep(i, 0, n) cin >> p[i];
		rep(i, 0, n) S[i + 1] = S[i] + p[i];
		rep(i, 0, n - 1) ans = max(ans, p[n - i - 1] * 100 / k + (p[n - i - 1] * 100 % k != 0) - S[n - i - 1]);
		cout << ans << "\n";
	}
}