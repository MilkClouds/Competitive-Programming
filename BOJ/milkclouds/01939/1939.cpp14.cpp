#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N,M,A,B,C,S,E;
ll ans,lo,hi;
vector<bool> visit;
unordered_map<int,ll> adj[10005];

bool dfs(int u,ll m){
	if(u==E)return 1;
	visit[u]=1;
	bool ret=0;
	for(auto &p:adj[u]){
		ll v=p.first,limit=p.second;
		if(limit<m or visit[v])continue;
		if(dfs(v,m))ret=1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>A>>B>>C;
		adj[A][B]=max(adj[A][B],C);
		adj[B][A]=adj[A][B];
		hi=max(hi,adj[A][B]);
	}
	hi++;
	cin>>S>>E;
	while(lo<hi-1){
		visit.assign(N+1,0);
		ll mid=lo+hi>>1;
		if(dfs(S,mid))lo=mid;
		else hi=mid;
	}
	cout<<lo;
}