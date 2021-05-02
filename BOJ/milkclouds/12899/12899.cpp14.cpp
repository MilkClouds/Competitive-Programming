#include <bits/stdc++.h>
using namespace std;
const int MAX=2e6+5;
typedef long long ll;

int tree[MAX],N,T,X;

void update(int u,int v){
	for(;u<=MAX;u+=u&-u)tree[u]+=v;
}
int lowerbound(int x){
	int res=0;
	int max=20;
	for(int k=max;~k;--k){
		int p=res+(1<<k);
		if(p<MAX && tree[p]<x){
			x-=tree[p];
			res+=1<<k;
		}
	}
	return res+1;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	while(N--){
		cin>>T>>X;
		if(T&1)update(X,1);
		else {
			int p=lowerbound(X);
			cout<<p<<"\n";
			update(p,-1);
		}
	}
}