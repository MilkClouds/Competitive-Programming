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
const int MAX=2e3+1, MOD=1e9+7;
int n,m,psumX[MAX][MAX],psumY[MAX][MAX];
string a[MAX];

unordered_map<int,ll> dp[MAX][MAX];

ll solution(int x,int y,int Rx,int Ry){
	if(x>=n || y>=m)return 0;
	if(x==n-1 && y==m-1)return 1;
	if(dp[x][y].find(Rx*2000+Ry) != dp[x][y].end())return dp[x][y][Rx*2000+Ry];
	//printf("%d %d %d %d\n", x,y,Rx,Ry);
	ll ret = 0;
	if( n - x - 1 > Rx && x + 1 < n)
		ret += solution(x + 1, y, Rx, psumY[x + 2][m] - psumY[x + 2][y + 1]);
	if( m - y - 1 > Ry && y + 1 < m)
		ret += solution(x, y + 1, psumX[n][y + 2] - psumX[x + 1][y + 2], Ry);
	return dp[x][y][Rx*2000+Ry] = ret % MOD;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) rep(j, 0, m) psumY[i + 1][j + 1] = psumY[i + 1][j] + (a[i][j] == 'R');
	rep(j, 0, m) rep(i, 0, n) psumX[i + 1][j + 1] = psumX[i][j + 1] + (a[i][j] == 'R');
	cout << solution(0,0,psumX[n][1], psumY[1][m]);
}