#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+1;
typedef long long ll;
int N,M,A[MAX],c,x,y,k;
ll lazy[MAX*4],tree[MAX*4];
void init(int node,int l,int r){
	if(l==r)tree[node]=A[l];
	else{
		int m=l+r>>1;
		init(node*2,l,m);
		init(node*2+1,m+1,r);
	}
}
void propagation(int node,int l,int r){
	if(lazy[node]==0)return;
	if(l==r)tree[node]+=lazy[node];
	else{
		int m=l+r>>1;
		lazy[node*2]+=lazy[node];
		lazy[node*2+1]+=lazy[node];
	}
	lazy[node]=0;
}
ll query(int node,int l,int r,int x){
	propagation(node,l,r);
	if(l<=x and x<=r){
		if(l==r)return tree[node];
		int m=l+r>>1;
		return query(node*2,l,m,x)+query(node*2+1,m+1,r,x);
	}
	return 0;
}
void update(int node,int l,int r,int i,int j,int k){
	propagation(node,l,r);
	if(r<i or j<l)return;
	if(i<=l and r<=j){
		lazy[node]+=k;
		propagation(node,l,r);
	} else {
		int m=l+r>>1;
		update(node*2,l,m,i,j,k);
		update(node*2+1,m+1,r,i,j,k);
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i+1];
	init(1,1,N);
	cin>>M;
	while(M--){
		cin>>c;
		if(c&1){
			cin>>x>>y>>k;
			update(1,1,N,x,y,k);
		}else{
			cin>>x;
			cout<<query(1,1,N,x)<<"\n";
		}
	}
}