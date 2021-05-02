#include <bits/stdc++.h>
using namespace std;
const int MAX=2004000;
int lazy[MAX],tree[MAX],N,a,b,c,cmd,M;
void prop(int node,int l,int r){
	if(lazy[node]==0)return;
	if((r-l+1)&1)tree[node]^=lazy[node];
	if(l!=r){
		lazy[node*2]^=lazy[node];
		lazy[node*2+1]^=lazy[node];
	}
	lazy[node]=0;	
}
void update(int node,int l,int r,int s,int e,int v){
	prop(node,l,r);
	if( s<=l and r<=e ){
		lazy[node]^=v;
		prop(node,l,r);
		return;
	}
	if(e<l or r<s)return;
	int m=l+r>>1;
	update(node*2,l,m,s,e,v);
	update(node*2+1,m+1,r,s,e,v);
	tree[node]=tree[node*2]^tree[node*2+1];
}
int query(int node,int l,int r,int s,int e){
	prop(node,l,r);
	if( s<=l and r<=e )return tree[node];
	if(e<l or r<s)return 0;
	int m=l+r>>1;
	return query(node*2,l,m,s,e)^query(node*2+1,m+1,r,s,e);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){cin>>a;update(1,0,N-1,i,i,a);}
	cin>>M;
	while(M--){
		cin>>cmd>>a>>b;
		if(a>b)swap(a,b);
		if(cmd==2){
			cout<<query(1,0,N-1,a,b)<<'\n';
		}
		else{
			cin>>c;
			update(1,0,N-1,a,b,c);
		}
	}
}