#include <bits/stdc++.h>
using namespace std;

int N,M,A[100001],tree[400001],i,j,cmd;
const int MAX=1e9;
int init(int node,int left,int right){
	if(left==right)tree[node]=A[left-1];
	else {
		int mid=(left+right)/2;
		tree[node]=min(init(node*2,left,mid),init(node*2+1,mid+1,right));
	}
	return tree[node];
}
int update(int node,int left,int right,int i,int v){
	if(left<=i and i<=right){
		if(left==right)tree[node]=v;
		else{
			int mid=(left+right)/2;
			tree[node]=min(update(node*2,left,mid,i,v),update(node*2+1,mid+1,right,i,v));
		}
	}
	return tree[node];
}
int query(int node,int left,int right,int i,int j){
	if(i<=left and right<=j)return tree[node];
	if(right<i or left>j)return MAX;
	int mid=(left+right)/2;
	return min(query(node*2,left,mid,i,j),query(node*2+1,mid+1,right,i,j));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	init(1,1,N);
	cin>>M;
	while(M--){
		cin>>cmd>>i>>j;
		if(cmd&1){
			update(1,1,N,i,j);
		}
		else{
			cout<<query(1,1,N,i,j)<<"\n";
		}
	}
}