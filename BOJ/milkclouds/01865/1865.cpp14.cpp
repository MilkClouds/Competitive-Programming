#include <bits/stdc++.h>
using namespace std;

int TC,N,M,W,S,E,T;
const int INF=INT_MAX;

int main(){
	cout.tie(0);cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>TC;
	while(TC--){
		cin>>N>>M>>W;
		vector<pair<int,int> > adj[501];
		int dist[501],nCycle=0;
		fill(dist,dist+500,INF);
		for(int i=0;i<M;i++){
			cin>>S>>E>>T;
			adj[S].push_back({E,T});
			adj[E].push_back({S,T});
		}
		for(int i=0;i<W;i++){
			cin>>S>>E>>T;
			adj[S].push_back({E,-T});
		}
		for(int idx=1;idx<=N;idx++){
			if(dist[idx]==INF)dist[idx]=0;
			for(int S=1;S<=N;S++){
				for(auto i:adj[S]){
					E=i.first,T=i.second;
					if(dist[S]!=INF && dist[E]>dist[S]+T){
						if(idx==N){nCycle=1;break;}
						dist[E]=dist[S]+T;
					}
				}
				if(nCycle)break;
			}
		}
		cout<<(nCycle?"YES":"NO")<<"\n";
	}
}