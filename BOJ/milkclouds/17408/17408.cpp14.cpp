#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
const int MAX=1e5+2;
int N,A[MAX],M,op,a,b;

struct NODE{
	int M,M2;
	NODE():NODE(0,0){}
	NODE(int M,int M2):M(M),M2(M2){}
} tree[MAX*4];

int sum(NODE a){return a.M+a.M2;}

NODE f(NODE a,NODE b){
	vector<int> v={a.M,a.M2,b.M,b.M2};
	sort(v.begin(), v.end());
	return NODE(v[3],v[2]);
}

NODE init(int node,int l,int r){
	if(l==r) return tree[node]={A[l],0};
	int m=l+r>>1;
	return tree[node]=f(init(node*2,l,m), init(node*2+1,m+1,r));
}

void update(int node,int l,int r,int i,int v){
	if(r<i || i<l)return;
	if(l==r){
		tree[node]={v,0};
		return;
	}
	int m=l+r>>1;
	update(node*2,l,m,i,v); update(node*2+1,m+1,r,i,v);
	tree[node]=f(tree[node*2],tree[node*2+1]);
}

NODE query(int node,int l,int r,int s,int e){
	if(e<l || r<s)return NODE(0,0);
	if(s<=l && r<=e)return tree[node];
	int m=l+r>>1;
	return f(query(node*2,l,m,s,e), query(node*2+1,m+1,r,s,e));
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	rep(i,0,N)cin>>A[i];
	init(1,0,N-1);
	cin>>M;
	while(M--){
		cin>>op>>a>>b;
		if(op&1)update(1,0,N-1,a-1,b);
		else{
			cout<<sum(query(1,0,N-1,a-1,b-1))<<"\n";
		}
	}
}