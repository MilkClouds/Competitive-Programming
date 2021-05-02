#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a,b,c;
ll dist[1010],visit[1010],pre[1010];
priority_queue<pair<ll,ll> > pq;
ll adj[1001][1001];
const ll MAX=1234567891;
int main()
{
	int start,end;
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){dist[i]=MAX;for(int j=1;j<=n;j++)adj[i][j]=MAX;}
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		adj[a][b]=min(adj[a][b],c);
	}
	cin>>start>>end;
	dist[start]=0;
	pq.push({0,start});
	while(!pq.empty()){
		auto t=pq.top();
		pq.pop();
		int dis=-t.first,city=t.second;
		if(visit[city])continue;
		visit[city]=1;
		for(int i=1;i<=n;i++)
		{
			if(dist[i]>dist[city]+adj[city][i]){
				dist[i]=dist[city]+adj[city][i];pre[i]=city;
				if(visit[i])continue;
				pq.push({-dist[i],i});
			}
		}	
	}
	cout<<dist[end]<<"\n";
	int i = end,cnt=0;
	stack<int> Q;
	while(i^start){Q.push(i);i=pre[i];cnt++;}
	cout<<cnt+1<<"\n";
	cout<<start<<" ";
	while(!Q.empty()){cout<<Q.top()<<" ";Q.pop();}
	return 0;
}