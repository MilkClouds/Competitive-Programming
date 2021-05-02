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
const ll INF = 1e9, MOD = 1e9 + 7, MAX = 1e5 + 10;

ll N, M, dfsn[MAX], cnt, flag, ans;
vector<ll> adj[MAX];

int dfs(int u,int par){
	int c = 0, f = 0;
	dfsn[u] = ++cnt;
	for(auto v: adj[u]){
		if(v ^ par){
			if(dfsn[v] == 0){
				c += dfs(v, u);
			}
			else if (dfsn[u] > dfsn[v]) c++;
			else f++;
		}
	}
	if(c >= 2) flag = 1;
	return c - f;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M;
	rep(i, 0, M){
		ll u,v;
		cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	rep(i,0,N){
		if(dfsn[i+1])continue;
		flag = 0;
		dfs(i+1,0);
		ans += !flag;
	}
	cout << ans;
}
	