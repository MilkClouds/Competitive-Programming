#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int K,N,F,u,v;
bool adj[901][901];
vector<int> save;

bool solve(int u){
	save.push_back(u);
	if(save.size()==K)return 1;
	if(u==N)return 0;
	bool flag = 0;
	for(int v=u+1;v<=N;v++){
		flag = 0;
		for(auto t:save){
			if(!adj[v][t]){flag=1;break;}
		}
		if(!flag and solve(v))return 1;
	}
	save.pop_back();
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>K>>N>>F;
	for(int i=0;i<F;i++){cin>>u>>v;adj[u][v]=adj[v][u]=1;}
	for(int i=1;i<=N;i++){
		if(solve(i)){
			for(auto u:save)cout<<u<<"\n";
			return 0;
		}
		save.clear();
	}
	cout<<-1;
}