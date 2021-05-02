#include <iostream>
#include <vector>
using namespace std;

const int MAX=100001;
int n,m,t,in[MAX],out[MAX],c,i,w,tree[MAX];
vector<int> child[MAX];

int cnt;
int dfs(int v){
	in[v]=++cnt;
	for(auto u:child[v]) dfs(u);
	out[v]=cnt;
}

int sum(int v){
	int ret=0;
	for(int i=v;i;i^=i&-i){
		ret+=tree[i];
	}
	return ret;
}
void update(int i,int v){
	for(int j=i; j<=n ; j+=j&-j){
		tree[j]+=v;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(i==1)continue;
		child[t].push_back(i);
	}
	dfs(1);
	while(m--){
		cin>>c;
		if(c==1){
			cin>>i>>w;
			update(in[i],w);
			update(out[i]+1,-w);
		}
		else{
			cin>>i;
			cout<<sum(in[i])<<'\n';
		}
	}
	return 0;
}