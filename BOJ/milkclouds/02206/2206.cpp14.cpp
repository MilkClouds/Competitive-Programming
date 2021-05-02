#include <bits/stdc++.h>
using namespace std;
const int INF=1e9,dx[]={1,-1,0,0},dy[]={0,0,-1,1};
int N,M,K,dist[1002][1002][11],visit[1002][1002][11];
string a[1002];
struct node{
	int dist,x,y,cnt;
	bool operator < (node o) const {
		return dist>o.dist;
	}
};
int BFS(){
	queue<node> Q;
	Q.push({0,0,0,0});
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)for(int k=0;k<=K;k++)dist[i][j][k]=INF;
	dist[0][0][0]=1;
	while(!Q.empty()){
		node top=Q.front();Q.pop();
		int x=top.x,y=top.y,cnt=top.cnt;
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<0||ny<0||nx>=N||ny>=M)continue;
			int block=a[nx][ny]=='1';
			if(cnt+block>K)continue;
			if(dist[nx][ny][cnt+block]==INF){
				dist[nx][ny][cnt+block]=dist[x][y][cnt]+1;
				Q.push({dist[nx][ny][cnt+block],nx,ny,cnt+block});
			}
		}
	}
	int ret=INF;
	for(int i=0;i<=K;i++)ret=min(ret,dist[N-1][M-1][i]);
	return ret^INF?ret:-1;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;K=1;
	for(int i=0;i<N;i++)cin>>a[i];
	cout<<BFS();
}