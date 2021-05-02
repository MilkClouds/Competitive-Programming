#include <bits/stdc++.h>
using namespace std;

struct edge{
	int u,v,d;
	bool operator < (edge o) const{
		return d<o.d;
	}
};
int n,m,u,v,d,par[100001],cnt,ret;
priority_queue<edge> pq;

int find(int u){
	return u^par[u]?par[u]=find(par[u]):u;
}
void merge(int u,int v){
	u=find(u);v=find(v);
	if(rand()&1)swap(u,v);
	par[u]=v;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)par[i]=i;
	while(m--){
		cin>>u>>v>>d;
		pq.push({u,v,-d});
	}
	while(cnt<n-2){
		auto [u,v,d]=pq.top();pq.pop();
		u=find(u);v=find(v);
		if(u!=v)merge(u,v),cnt++,ret+=-d;
	}
	cout<<ret;
	return 0;
}