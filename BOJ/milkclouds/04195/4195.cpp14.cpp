#include <iostream>
#include <map>

using namespace std;

int T,F;
char a[21],b[21];
int parent[200010];
int ranks[200010];
int friends[200010];

void init(int n){while(n--){parent[n]=n;ranks[n]=1;friends[n]=1;}}

int find(int u){
	if(u==parent[u])return u;
	return parent[u]=find(parent[u]);
}

int merge(int u,int v){
	u=find(u);v=find(v);
	if(u==v)return friends[u];
	if(ranks[u]>ranks[v])swap(u,v);
	parent[u]=v;
	if(ranks[u]==ranks[v])ranks[v]++;
	friends[v]+=friends[u];
	return friends[v];
}

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>F;
		init(F*2);
		map<string,int> m;
		int idx=0;
		while(F--){
			cin>>a>>b;
			if(m.count(a)==0){m[a]=idx;idx++;}
			if(m.count(b)==0){m[b]=idx;idx++;}
			cout<<merge(m[a],m[b])<<"\n";
		}
	}
}