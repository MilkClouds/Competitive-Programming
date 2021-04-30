#include <bits/stdc++.h>
using namespace std;

int N,u,v;
vector<int> adj[100001];
vector<bool> visit(100001);
vector<int> parent(100001);
void dfs(int u){
	visit[u]=1;
	for(auto v:adj[u]){
		if(visit[v])continue;
		parent[v]=u;
		dfs(v);
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=1;i<N;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for(int i=2;i<=N;i++)cout<<parent[i]<<'\n';
}