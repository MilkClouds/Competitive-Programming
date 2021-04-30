#include<bits/stdc++.h>
using namespace std;

const int MAX=100005;
int N,M,u[MAX],v[MAX],w[MAX],par[MAX],last[MAX],cnt[MAX],a,b,c,idx[MAX],tree[MAX*4];
vector<int> adj[MAX];

int count(int u,int prev){
	for(auto v:adj[u])prev^v and (cnt[u]+=count(v,u));
	return ++cnt[u];
}
void build(int u,int prev){
	int h=0;
	for(auto v:adj[u])if(prev^v && cnt[v]>cnt[h])h=v;
	for(auto v:adj[u])if(v^h && v^prev)build(v,u);
	if(!last[u])last[u]=u;
	if(h)last[h]=last[u],build(h,u);
	par[u]=prev;
	idx[u]=++c;
}
void update(int node,int l,int r,int i,int c){
	if(i<l or r<i)return;
	if(l==r){
		tree[node]=c;
		return;
	}
	int m=l+r>>1;
	update(node*2,l,m,i,c);
	update(node*2+1,m+1,r,i,c);
	tree[node]=max(tree[node*2],tree[node*2+1]);
}
int query(int node,int l,int r,int u,int v){
	if(r<u or l>v)return 0;
	if(u<=l and r<=v)return tree[node];
	int m=l+r>>1;
	return max(query(node*2,l,m,u,v),query(node*2+1,m+1,r,u,v));
}
int LCA(int u,int v){
	int ret=0;
	while(last[u]^last[v]){
		if(cnt[last[u]]>cnt[last[v]])swap(u,v);
		ret=max(ret,query(1,1,N,idx[u],idx[last[u]]));
		u=par[last[u]];
	}
	if(cnt[u]>cnt[v])swap(u,v);
	return max(ret,query(1,1,N,idx[u],idx[v]-1));
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i=1;i<N;i++){
		cin>>u[i]>>v[i]>>w[i];
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}
	count(1,0);
	build(1,0);
	for(int i=1;i<N;i++){
		if(par[v[i]]==u[i])swap(u[i],v[i]);
		update(1,1,N,idx[u[i]],w[i]);
	}
	cin>>M;
	while(M--){
		cin>>a>>b>>c;
		if(a&1)update(1,1,N,idx[u[b]],c);
		else cout<<LCA(b,c)<<'\n';
	}
}