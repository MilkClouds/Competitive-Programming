#include <bits/stdc++.h>
using namespace std;

int N,M,T,t,visit[1005],rev[1005],TC,chk[1005],acnt,bcnt,b[1005];
vector<int> adj[1005];

bool dfs(int u){
	if(visit[u]==TC)return 0;
	visit[u]=TC;
	for(auto v:adj[u]){
		if(rev[v]==0 || dfs(rev[v])){
			rev[v]=u;
			return 1;
		}
	}
	return 0;
}
int bipartite(){
	int ret=0;
	for(TC=1;TC<=N;TC++){
		if(dfs(TC)){
			ret++;
			chk[TC]=1;
		}
	}
	return ret;
}
void dfs2(int u){
	if(visit[u]==0)return;
	visit[u]=0;
	acnt++;
	for(auto v:adj[u])bcnt+=!b[v]++, dfs2(rev[v]);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>T;
		while(T--){
			cin>>t;
			adj[i].push_back(t);
		}
	}
	int tmp=bipartite();
	for(int i=1;i<=N;i++)if(!chk[i])dfs2(i);
	cout<<tmp<<"\n"<<N-acnt<<" ";
	for(int i=1;i<=N;i++)if(visit[i]!=0)cout<<i<<" ";
	cout<<'\n'<<bcnt<<" ";
	for(int i=1;i<=M;i++)if(b[i])cout<<i<<" ";
}