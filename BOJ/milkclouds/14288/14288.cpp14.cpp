#include <iostream>
#include <vector>
using namespace std;

const int MAX=100011;
int n,m,t,in[MAX],out[MAX],c,i,w,mode;
long long tree[2][MAX];
vector<int> child[MAX];

int cnt;
int dfs(int v){
	in[v]=++cnt;
	for(auto u:child[v]) dfs(u);
	out[v]=cnt;
}

int sum(int v,int mode){
	int ret=0;
	for(int i=v;i;i^=i&-i){
		ret+=tree[mode][i];
	}
	return ret;
}
void update(int i,int v){
	for(int j=i; j<=n ; j+=j&-j){
		tree[mode][j]+=v;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
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
			if(mode)update(in[i],w);
			else{
				update(in[i],w);
				update(out[i]+1,-w);
			}
		}
		else if(c==2){
			cin>>i;
			cout<<sum(in[i],0)+sum(out[i],1)-sum(in[i]-1,1)<<'\n';
		}
		else{
			mode^=1;
		}
	}
	return 0;
}