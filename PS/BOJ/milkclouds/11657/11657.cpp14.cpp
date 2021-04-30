#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N,M,a,b,c;
bool cycle;
vector<pair<int,int> > route[501];
ll dist[501];
const ll INF=1e16;

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		route[a].push_back({b,c});
	}
	fill(dist,dist+N+1,INF);
	dist[1]=0;
	for(int i=0;i<N-1;i++){
		for(int a=1;a<=N;a++){
			for(auto x:route[a]){
				b=x.first,c=x.second;
				if(dist[a]!=INF && dist[b]>dist[a]+c) dist[b]=dist[a]+c;
			}
		}
	}
	for(int a=1;a<=N;a++){
		for(auto x:route[a]){
			b=x.first,c=x.second;
			if(dist[a]!=INF && dist[b]>dist[a]+c) {cycle=1;break;}
		}
	}
	if(cycle)
		cout<<-1;
	else
	{
		for(int i=2;i<=N;i++)
		cout<<(dist[i]==INF?-1:dist[i])<<"\n";
	}
}