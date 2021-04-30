#include <bits/stdc++.h>
using namespace std;

int N,M,s,a,b,degree[1001],visit[1001];
vector<int> adj[1001],stk,ans;

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>s;
		b=0;
		while(s--){
			cin>>a;
			if(b){
				adj[b].push_back(a);
				degree[a]++;
			}
			b=a;
		}
	}
	for(int i=1;i<=N;i++){
		if(degree[i]==0)stk.push_back(i);
	}
	while(!stk.empty()){
		int u=stk.back();
		visit[u]=1;
		ans.push_back(u);
		stk.pop_back();
		for(auto v:adj[u]){
			degree[v]--;
			if(degree[v]==0 and not visit[v])stk.push_back(v);
		}
	}
	for(int i=1;i<=N;i++)if(not visit[i]){cout<<0;return 0;}
	for(auto i:ans)cout<<i<<'\n';
}