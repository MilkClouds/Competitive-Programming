#include <bits/stdc++.h>
using namespace std;

const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int TC,H,W;
bool visit[101][101];
vector<string> arr(101);

inline bool can(int x,int y){return 0<=x and x<H and 0<=y and y<W;}
bool dfs(int x,int y){
	if(visit[x][y] or arr[x][y]=='.')return 0;
	visit[x][y]=1;
	bool ret=0;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		can(nx,ny) && arr[nx][ny]=='#' && dfs(nx,ny);
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>TC;
	while(TC--){
		cin>>H>>W;
		for(int i=0;i<H;i++){cin>>arr[i];memset(visit[i],0,sizeof(visit[i]));}
		int ans=0;
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)ans+=dfs(i,j);
		cout<<ans<<"\n";
	}
}