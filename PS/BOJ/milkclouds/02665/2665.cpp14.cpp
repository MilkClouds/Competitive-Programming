#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,visit[51][51],dist[51][51];
string maze[51];
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
list<pii> deq;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>maze[i];
	deq.push_back({0,0});
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)dist[i][j]=1e9;
	dist[0][0]=0;
	while(!deq.empty()){
		auto [x,y]=deq.front();deq.pop_front();
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(0>nx or nx>=n or 0>ny or ny>=n)continue;
			if(dist[x][y]+(maze[nx][ny]=='0')>=dist[nx][ny])continue;
			dist[nx][ny]=dist[x][y]+(maze[nx][ny]=='0');
			if(visit[nx][ny])continue;
			visit[nx][ny]=1;
			if(maze[nx][ny]=='1')deq.push_front({nx,ny});
			else deq.push_back({nx,ny});
		}
	}
	cout<<dist[n-1][n-1];
	return 0;
}