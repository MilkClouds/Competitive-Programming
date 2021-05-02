#include <iostream>
using namespace std;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m;
bool visit[22][22],chk[150];
string a[22];
int dfs(int x,int y){
	int ret=0;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(!(0<=nx&&nx<n&&0<=ny&&ny<m))continue;
		if(visit[nx][ny] or chk[a[nx][ny]])continue;
		visit[nx][ny]=chk[a[nx][ny]]=1;
		ret=max(ret,dfs(nx,ny));
		visit[nx][ny]=chk[a[nx][ny]]=0;
	}
	return ret+1;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	visit[0][0]=chk[a[0][0]]=1;
	cout<<dfs(0,0);
}