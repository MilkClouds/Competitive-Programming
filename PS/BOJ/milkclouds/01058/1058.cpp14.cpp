#include <bits/stdc++.h>
#define pb push_back
using namespace std;
// 10:49~11:03

int N,indegree[51],m;
vector<int> adj[51];
string G[51];

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>G[i];
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(G[i][j]=='Y')adj[i].pb(j);
	for(int i=0;i<N;i++){
		int t=0;
		vector<bool> chk(100,0);chk[i]=1;
		for(auto u:adj[i]){
			if(!chk[u])chk[u]=1,t++;
			for(auto v:adj[u]){
				if(chk[v])continue;
				chk[v]=1;t++;
			}
		}
		m=max(m,t);
	}
	cout<<m;
}