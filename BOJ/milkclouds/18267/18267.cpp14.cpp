
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

const int MAX = 1e5 + 5;

struct AB{
	ll x,y;
	AB operator + (AB o){
		return {x + o.x, y + o.y};
	}
	AB operator - (AB o){
		return {x - o.x, y - o.y};
	}
};

ll N, M, u, v, depth[MAX], par[MAX][18];
string S;
vector<ll> adj[MAX];
char c;

AB dp[MAX];
void dfs(ll u, ll prev){
	par[u][0] = prev;
	depth[u] = depth[prev] + 1;
	if(S[u-1]=='G') dp[u].x++;
	else dp[u].y++;
	for(auto v: adj[u]){
		if(v == prev) continue;
		dp[v] = dp[v] + dp[u];
		dfs(v, u);
	}
}
int LCA(int u,int v){
	if(depth[u]^depth[v]){
		if(depth[u]>depth[v])swap(u,v); //v가 깊게
		int t=depth[v]-depth[u];
		rep(k,0,18){
			if(t&(1<<k)){
				v=par[v][k];
			}
		}
	}
	if(u==v)return u;
	rep(k,0,18){
		if(par[u][17-k]^par[v][17-k]){
			u=par[u][17-k];
			v=par[v][17-k];
		}
	}
	return par[u][0];
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M >> S;
	rep(i, 0, N - 1){
		cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1, 0);
	rep(k, 1, 18) rep(u, 1, N + 1) par[u][k] = par[par[u][k - 1]][k - 1];
	rep(_, 0, M){
		cin >> u >> v >> c;
		ll p = LCA(u, v);
		AB t;
		if(p == 0) t = dp[u] + dp[v] - dp[1];
		else t = dp[u] + dp[v] - dp[par[p][0]] - dp[p];

		if(c=='G') cout << (t.x>0);
		else cout << (t.y>0);
	}
}
