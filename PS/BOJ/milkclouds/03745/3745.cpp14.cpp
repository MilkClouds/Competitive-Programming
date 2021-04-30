#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

const int MAX = 1e6+3;

int a[MAX], dp[MAX], n, ans; // dp[i] : length i's lcs's last num
int main() 
{
    while(~scanf("%d", &n)){
	ans = 0;
        rep(i, 0, n) cin >> a[i];
        fill(dp, dp + n, 1e9);
        rep(i, 0, n){
	    if(dp[ans] < a[i]) {dp[++ans] = a[i]; continue;}
            auto pos = lower_bound(dp, dp + i, a[i]);
	    *pos = a[i];
	    ans = max(ans, (int)(pos - dp));
        }
	cout << ans + 1 << "\n";
    }
}