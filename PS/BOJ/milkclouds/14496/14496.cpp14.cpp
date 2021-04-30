#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
int a,b,N,M,u,v;
bool visit[1005];
vector<int> adj[1005];
int BFS(int S,int E){
	queue<pii> Q; Q.push({S,0}); visit[S]=1;
	while(!Q.empty()){
		int u=Q.front().x, d=Q.front().y; Q.pop();
		if(u==E)return d;
		for(auto v:adj[u]){
			if(visit[v])continue;
			Q.push({v,d+1});visit[v]=1;
		}
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b>>N>>M;
	rep(i,0,M){
		cin>>u>>v;
		adj[u].pb(v);adj[v].pb(u);
	}
	cout<<BFS(a,b);
}