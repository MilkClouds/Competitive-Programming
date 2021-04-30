#include <iostream>
#include <algorithm>
using namespace std;

int n,a[505][505],dp[505][505],ret;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int dfs(int x,int y){
	if (dp[x][y]) return dp[x][y];
	dp[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if (a[x][y]<a[nx][ny])
		dp[x][y]=max(dp[x][y],dfs(nx,ny)+1);
		}
		return dp[x][y];
	}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++)
		cin>>a[i][j];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++)
		ret=max(ret,dfs(i,j));
	cout<<ret;
	return 0;
}