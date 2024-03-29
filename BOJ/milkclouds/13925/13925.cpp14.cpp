#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,MAX=4e5+5;
struct lazynode{
	int w,b;
	lazynode():w(1),b(0){}
	lazynode(int w,int b):w(w),b(b){}
	void operator +=(lazynode o){
		if(o.w==0){
			w=0;
			b=o.b;
			return;
		}
		w=1LL*w*o.w%MOD; b=1LL*o.w*b%MOD;
		b=(o.b+b)%MOD;
	}
};
int tree[MAX],N,M,x,y,v,A[MAX],a;
lazynode lazy[MAX];
void prop(int node,int l,int r){
	int w=lazy[node].w, b=lazy[node].b;
	if(w==1 && b==0)return;
	tree[node]=(1LL*tree[node]*w+1LL*b*(r-l+1))%MOD;
	if(l!=r){
		lazy[node*2]+=lazy[node];
		lazy[node*2+1]+=lazy[node];
	}
	lazy[node]={1,0};
}
void update(int node,int l,int r,int s,int e,int a,int b){
	prop(node,l,r);
	if(e<l || r<s)return;
	if(s<=l && r<=e){
		lazy[node]+=lazynode{a,b};
		prop(node,l,r);
		return;
	}
	int m=l+r>>1;
	update(node*2,l,m,s,e,a,b);
    update(node*2+1,m+1,r,s,e,a,b);
    tree[node]=((long long)tree[node*2]+tree[node*2+1])%MOD;
}
int query(int node,int l,int r,int s,int e){
	prop(node,l,r);
	if(e<l || r<s)return 0;
	if(s<=l && r<=e){
		return tree[node];
	}
	int m=l+r>>1;
	return (query(node*2,l,m,s,e)+query(node*2+1,m+1,r,s,e))%MOD;
}
int init(int node,int l,int r){
	if(l==r)return tree[node]=A[l];
	else{
		int m=l+r>>1;
		return tree[node]=(init(node*2,l,m)+init(node*2+1,m+1,r))%MOD;
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++)cin>>A[i];
	init(1,1,N);
	cin>>M;
	int idx=0;
	while(M--){
		cin>>a>>x>>y;
		if(a==4){
			cout<<query(1,1,N,x,y)<<"\n";
		}
		else{
			cin>>v;
			if(a==1)update(1,1,N,x,y,1,v);
			if(a==2)update(1,1,N,x,y,v,0);
			if(a==3)update(1,1,N,x,y,0,v);
		}
	}
}