#include <bits/stdc++.h>
using namespace std;

inline void conv(int& n){
	n=n<0? -n*2 : n*2-1;
}
inline int nai(int n){return n&1?n+1:n-1;}
int N,M,u,v,dist[50][50];
const int INF=1e9;
// vector<int> adj[1000];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	int limit=N*2+1;
	for(int i=0;i<M;i++){
		cin>>u>>v;
		conv(u);conv(v);
		dist[nai(u)][v]=1;
		dist[nai(v)][u]=1;
	}
	for(int m=1;m<limit;m++)
		for(int s=1;s<limit;s++)
			for(int e=1;e<limit;e++){
				if(dist[s][m]==1&&1==dist[m][e]){
					dist[s][e]=1;
				}
			}
	for(int i=1;i<limit;i+=2){
		if(dist[i][nai(i)]==1&&dist[nai(i)][i]==1){cout<<0;return 0;}
	}
	cout<<1;
}