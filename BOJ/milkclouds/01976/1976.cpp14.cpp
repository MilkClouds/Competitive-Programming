#include <bits/stdc++.h>
using namespace std;

int N,M,T,l,err;
int par[201],ranks[201];

void init(){for(int i=1;i<=N;i++){par[i]=i;ranks[i]=1;}}
int find(int u){
	if(par[u]==u)return u;
	return par[u]=find(par[u]);
}
void merge(int u,int v){
	u=find(u);v=find(v);
	if(ranks[u]<ranks[v])swap(u,v);
	par[v]=u;
	if(ranks[u]==ranks[v])ranks[u]++;
}

int main(){
	cin>>N>>M;
	init();
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++){cin>>T;if(T)merge(i,j);}
	for(int i=0;i<M;i++){
		l=T;
		cin>>T;
		if(i==0)continue;
		if(find(l)!=find(T))err=1;
	}
	cout<<(err?"NO":"YES");
}