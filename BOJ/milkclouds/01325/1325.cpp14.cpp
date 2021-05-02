#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
vector<int> adj[10001];
pair<int,vector<int> > ans;
bool visit[10001];
int dfs(int i){
	int ret=1;
	for(auto j:adj[i]){
		if(visit[j]) continue;
		visit[j]=1;
		ret+=dfs(j);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){cin>>a>>b;adj[b].push_back(a);}
	for(int i=1;i<=n;i++){
		memset(visit,0,sizeof(visit));
		visit[i]=1;
		int j=dfs(i);
		visit[i]=0;
		if(ans.first<j){ans.first=j;ans.second={i};}
		else if(ans.first==j)ans.second.push_back(i);
	}
	for(auto i:ans.second) cout<<i<<' ';
	return 0;
}