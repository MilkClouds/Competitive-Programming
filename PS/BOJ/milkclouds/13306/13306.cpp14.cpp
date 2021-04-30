#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int parent[200001],N,Q,x,u,v,par[200001],ans[200000],cnt;
pii query[400001];

int find(int u){
	return u==par[u]?u:par[u]=find(par[u]);
}
void merge(int u,int v){
	u=find(u);v=find(v);
	if(rand()&1)swap(u,v);
	par[u]=v;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>Q;
	for(int i=1;i<=N;i++)par[i]=i;
	for(int i=2;i<=N;i++)cin>>parent[i];
	for(int i=0;i<N-1+Q;i++){
		cin>>x;
		if(x){
			cin>>u>>v;
			query[i]={u,v};
		}
		else{
			cin>>u;
			query[i]={u,-1};
		}
	}
	for(int i=N-1+Q-1;~i;i--){
		auto [u,v]=query[i];
		if(~v){
			ans[cnt++]=find(u)==find(v);
		}
		else merge(u,parent[u]);
	}
	for(int i=Q;i;i--)cout<<(ans[i-1]?"YES":"NO")<<"\n";
}