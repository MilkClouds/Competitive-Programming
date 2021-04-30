#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+1,INF=1e9;
typedef pair<int,int> pii;
int N,S,E,u,v,d;
vector<pii> adj[MAX];
int Dijkstra(){
	vector<int> M(MAX);
	vector<int> d(MAX);
	vector<bool> visit(MAX);
	fill(d.begin(), d.end(), INF);d[S]=0;
	priority_queue<pii> PQ;
	PQ.push({0,S});
	while(!PQ.empty()){
		u=0;
		while(!PQ.empty()){
			v=PQ.top().second;PQ.pop();
			if(!visit[v]){u=v;break;}
		}
		if(u==0&&PQ.empty())break;
		visit[u]=1;
		for(auto [v,s]:adj[u]){
			if(d[u]+s<d[v]){
				M[v]=max({M[v],M[u],s});
				d[v]=d[u]+s;
				PQ.push({-d[v],v});
			}
		}
	}
	return d[E]-M[E];
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>S>>E;
	for(int i=1;i<N;i++){cin>>u>>v>>d;
		adj[u].push_back({v,d});
		adj[v].push_back({u,d});
	}
	cout<<Dijkstra();
}