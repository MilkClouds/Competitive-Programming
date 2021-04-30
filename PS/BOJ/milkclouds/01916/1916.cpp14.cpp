#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,c;
int dist[1010],visit[1010];
priority_queue<pair<int,int> > pq;
int adj[1001][1001];
const int MAX=1234567891;
int main()
{
	int start,end;
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){dist[i]=MAX;for(int j=1;j<=n;j++)adj[i][j]=-1;}
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		adj[a][b]=~adj[a][b]?min(adj[a][b],c):c;
	}
	cin>>start>>end;
	dist[start]=0;
	pq.push({0,start});
	while(!pq.empty()){
		auto t=pq.top();
		pq.pop();
		int dis=-t.first,city=t.second;
		visit[city]=1;
		for(int i=1;i<=n;i++)
		{
			if(adj[city][i]==-1) continue;
			if(dist[i]==MAX or dist[i]>dist[city]+adj[city][i]){
				dist[i]=dist[city]+adj[city][i];
				if(visit[i])continue;
				pq.push({-dist[i],i});
			}
		}	
	}
	cout<<dist[end];
	return 0;
}