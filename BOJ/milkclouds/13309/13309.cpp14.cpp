#include <bits/stdc++.h>
using namespace std;
const int MAX=200001;
int N,Q,a,b,c,d,cnt[MAX],last[MAX],idx[MAX],par[MAX];
bool tree[4*MAX];
vector<int> adj[MAX];

int count(int u,int root){
	for(auto v:adj[u])root^v and (cnt[u]+=count(v,u));
	return ++cnt[u];
}
void build(int u,int root){
	int heavy=0;
	for(auto v:adj[u])if(v^root && cnt[heavy]<cnt[v])heavy=v;
	for(auto v:adj[u])if(v^root && v^heavy)build(v,u);
	if(!last[u])last[u]=u;
	if(heavy)last[heavy]=last[u],build(heavy,u);
	idx[u]=++a;
}
void update(int node,int l,int r,int i,bool v){
	if(i<l or r<i)return;
	if(l==r)tree[node]=v;
	else{
		int m=l+r>>1;
		update(node*2,l,m,i,v);
		update(node*2+1,m+1,r,i,v);
		tree[node]=tree[node*2]||tree[node*2+1];
	}
}
bool query(int node,int l,int r,int u,int v){
	if(u<=l and r<=v) return tree[node];
	if(r<u or v<l)return 0;
	int m=l+r>>1;
	return query(node*2,l,m,u,v)||query(node*2+1,m+1,r,u,v);
}
bool exist(int u,int v){
	while(last[u]^last[v]){
		if(cnt[last[u]]>cnt[last[v]])swap(u,v);
		if(query(1,1,N,idx[u],idx[last[u]]))return 0;
		u=par[last[u]];
	}
	if(cnt[u]>cnt[v])swap(u,v);
	return !query(1,1,N,idx[u],idx[v]-1);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>Q;
	for(int i=2;i<=N;i++){cin>>par[i];adj[par[i]].push_back(i);}
	count(1,0);build(1,0);
	while(Q--){
		cin>>b>>c>>d;
		if(d){
			if(exist(b,c)){
				cout<<"YES\n";
				update(1,1,N,idx[b],1);
			}
			else{
				cout<<"NO\n";
				update(1,1,N,idx[c],1);
			}
		}
		else{
			cout<<(exist(b,c)?"YES":"NO")<<"\n";
		}
	}
}