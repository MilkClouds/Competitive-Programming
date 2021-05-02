# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const ll MAX = 2e5+1, INF=1e9;

ll n, dp[MAX], ans[MAX], res, k, pre[MAX];
pi a[MAX];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	rep(i, 0, n) { cin >> a[i].x; a[i].y = i; }
	sort(a, a+n);
	fill(dp, dp+n+1, INF);
	dp[0]=0;
	rep(i, 0, n){
		if(dp[i + 3] > dp[i] + a[i + 2].x - a[i].x){
			dp[i + 3] = dp[i] + a[i + 2].x - a[i].x;
			pre[i + 3] = 3;
		}
		if(dp[i + 4] > dp[i] + a[i + 3].x - a[i].x)
		{
			dp[i + 4] = dp[i] + a[i + 3].x - a[i].x;
			pre[i + 4] = 4;
		}		
		if(dp[i + 5] > dp[i] + a[i + 4].x - a[i].x)
		{
			dp[i + 5] = dp[i] + a[i + 4].x - a[i].x;
			pre[i + 5] = 5;
		}
	}
	int cur = n;
	while(cur > 0){
		k++;
		rep(t,cur - pre[cur], cur) ans[a[t].y] = k;
		cur -= pre[cur];
	}
	cout << dp[n] << " " << k << "\n";
	rep(i,0,n)cout<<ans[i]<<" ";
}