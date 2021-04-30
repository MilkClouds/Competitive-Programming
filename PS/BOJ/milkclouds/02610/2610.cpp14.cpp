#include <bits/stdc++.h>
#define pb push_back
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const int MAX = 1e3+1, INF=1e9;

int V,E,a,b,cnt;
vector<int> adj[MAX],ans;

int f(int S){
	vector<int> visit(V+1, 0);
	queue<pi> Q; visit[S] = 1;
	int M=0;
	Q.push({S,0});
	while(!Q.empty()){
		int u=Q.front().x, i=Q.front().y; Q.pop(); M=max(M,i);
		for(auto v:adj[u]){
			if(visit[v])continue;
			visit[v]=1;
			Q.push({v,i+1});
		}
	}
	return M;
}

vector<int> vv,vis(MAX);
bool dfs(int u){
	if(vis[u])return 0;
	vv.pb(u); vis[u]=1;
	for(auto v:adj[u]) dfs(v);
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> V >> E;
	rep(i, 0, E){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,1,V+1){
		vv.clear();
		if(dfs(i)){
			int m=1e9,aa=0;cnt++;
			for(auto u:vv){
				int t=f(u);
				if(t<m){
					m=t;aa=u;
				}
			}
			ans.pb(aa);
		}
	}
	cout<<cnt<<endl;
	sort(ans.begin(), ans.end());
	for(auto i:ans) cout<<i<<"\n";
}