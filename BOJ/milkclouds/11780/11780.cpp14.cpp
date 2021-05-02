#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N,M,save[101][101],a,b,nex[101],cnt;
ll dist[101][101],c;
const ll INF=10000000000;

void solve(int s,int e){
	int m=save[s][e];
	nex[s]=e;
	if(m==0)return;cnt++;
	nex[s]=m;
	solve(s,m);solve(m,e);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)i==j or (dist[i][j]=INF);
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		dist[a][b]=min(dist[a][b],c);
	}
	for(int m=1;m<=N;m++){
		for(int s=1;s<=N;s++){
			for(int e=1;e<=N;e++){
				if(dist[s][e]>dist[s][m]+dist[m][e]){
					save[s][e]=m;
					dist[s][e]=dist[s][m]+dist[m][e];
				}
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)cout<<(dist[i][j]==INF?0:dist[i][j])<<" ";
		cout<<"\n";
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(dist[i][j]==INF or i==j){cout<<"0\n";continue;}
			cnt=2;solve(i,j);cout<<cnt<<" ";
			int t=i;
			while(t!=j){cout<<t<<" ";t=nex[t];}cout<<j<<"\n";
		}
	}
}