#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;
const int MAX = 2e5 + 1;

ll TC, n, a[MAX], dp[MAX], ans;

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> TC;
	while(TC--){
		cin >> n;
		ans = 0;
		rep(i, 0, n) {cin >> a[i]; dp[i] = a[i];}
		rep(i, 0, n) {
			if(a[i] + i >= n) continue;
			dp[a[i] + i] = max(dp[a[i] + i], dp[i] + a[a[i] + i]);
		}
		rep(i, 0, n) ans = max(dp[i], ans);
		cout << ans << "\n";
	}
}