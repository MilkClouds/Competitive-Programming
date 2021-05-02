#include <iostream>
using namespace std;

int N,a[101][101],comp,ret=1;
bool visit[101][101];
const int dx[]={0,0,-1,1},dy[]={1,-1,0,0};

bool dfs(int x,int y,int level){
	if(visit[x][y] or a[x][y]<=level)return 0;
	visit[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0 or nx>=N or ny<0 or ny>=N)continue;
		dfs(nx,ny,level);
	}
	return 1; 
}

int main()
{
	cin>>N;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>a[i][j];
	for(int l=1;l<101;l++){
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)visit[i][j]=0;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)comp+=dfs(i,j,l);
		ret=max(ret,comp);
		comp=0;
	}
	cout<<ret;
	return 0;
}