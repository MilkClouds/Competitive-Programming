#include <iostream>

using namespace std;

int n,m,cmd,a,b;
int parent[1000001];
int ranks[1000001];

void init(int n){while(n--){parent[n]=n;ranks[n]=1;}}

int find(int u){
	if(u==parent[u])return u;
	return parent[u]=find(parent[u]);
}

void merge(int u,int v){
	u=find(u);v=find(v);
	if(u==v)return;
	if(ranks[u]>ranks[v])swap(u,v);
	parent[u]=v;
	if(ranks[u]==ranks[v])ranks[v]++;
}

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>n>>m;
	init(n+1);
	while(m--){
		cin>>cmd>>a>>b;
		if(cmd)
			cout<<(find(a)==find(b)?"YES":"NO")<<"\n";
		else
			merge(a,b);
	}
}