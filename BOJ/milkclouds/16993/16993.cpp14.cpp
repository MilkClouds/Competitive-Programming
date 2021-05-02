#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int MAX=1e5+5, INF=1e9, inf=1e9;

int N,A[MAX],pSum[MAX],M,i,j;

struct NODE{
	int mmax, lmax, rmax;
	NODE(int mmax,int lmax,int rmax):mmax(mmax),lmax(lmax),rmax(rmax){}
	NODE(int u):NODE(u,u,u){}
	NODE():NODE(0,0,0){}
} tree[MAX*4];

NODE& init(int node,int l,int r){
	if(l==r){
		return tree[node]=NODE(A[l]);
	}
	int m=l+r>>1, lsum=0, rsum=0;
	NODE& left=init(node*2,l,m), right=init(node*2+1,m+1,r);
	int lmax=-INF,rmax=-INF,mmax=max(max(left.mmax,left.rmax+right.lmax),right.mmax);
	for(int i=l;i<=r;i++){
		lsum+=A[i];
		lmax=max(lmax,lsum);
	}
	for(int i=r;i>=l;i--){
		rsum+=A[i];
		rmax=max(rmax,rsum);
	}
	return tree[node]=NODE(mmax,lmax,rmax);
}
NODE _query(int node,int l,int r,int s,int e){
	if(s<=l && r<=e){
		return tree[node];
	}
	if(r<s || e<l)return NODE(-INF);
	int m=l+r>>1;
	NODE left=_query(node*2,l,m,s,e), right=_query(node*2+1,m+1,r,s,e);
	int mmax=max({left.mmax,left.rmax+right.lmax, right.mmax});
	
	int lmax=max(left.lmax, pSum[m]-pSum[l-1]+right.lmax);
	int rmax=max(right.rmax, pSum[r]-pSum[m]+left.rmax);
	return NODE(mmax,lmax,rmax);
}
int query(int s,int e){
	NODE ans=_query(1,1,N,s,e);
	return ans.mmax;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++){cin>>A[i];pSum[i]=pSum[i-1]+A[i];}
	init(1,1,N);
	cin>>M;
	while(M--){
		cin>>i>>j;
		cout<<query(i,j)<<"\n";
	}
}