#include <bits/stdc++.h>
#define pb push_back
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const int MAX = 1e3+1, INF=1e9;

int V,E,a,b;
vector<pi> adj[MAX],ans;

void f(){
	vector<int> d(V+1,INF),visit(V+1,0);
	priority_queue<pair<int,pi> > pq;
	pq.push({0,{1,0}}); d[1]=0;
	while(!pq.empty()){
		int u=pq.top().y.x,p=pq.top().y.y; pq.pop();
		if(visit[u])continue;
		visit[u]=1;
		if(p) ans.pb({p,u});
		for(auto [v,dd]:adj[u]){
			if(d[v]<=d[u]+dd) continue;
			d[v]=d[u]+dd;
			if(!visit[v]){pq.push({-d[v],{v,u}});}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> V >> E;
	rep(i, 0, E){
		int u,v,d;
		cin >> u >> v >> d;
		adj[u].pb({v,d});
		adj[v].pb({u,d});
	}
	f();
	cout<<ans.size()<<endl;
	for(auto [u,v]:ans) cout<<u<<" "<<v<<"\n";
}