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
using pi=pair<int,int>;
const ll INF = 1e9;
const int MAX = 1e5 + 1;

// 12:18

int N,M,X,u,v;
vector<int> adj[MAX], rev[MAX];

int bfs(int X,vector<int>* adj){
	vector<bool> vis(N,0);
	queue<int> Q; Q.push(X); vis[X]=1;
	int i = 0;
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		for(auto v : adj[u]){
			if(vis[v])continue;
			vis[v] = 1;
			Q.push(v); i++;
		}
	}
	return i;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M >> X; X--;
	rep(i, 0, M){
		cin >> u >> v; u--; v--;
		rev[u].pb(v);
		adj[v].pb(u);
	}
	cout << 1 + bfs(X, adj) << " " << N - bfs(X, rev);
}