#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,m[101][101],ret,N,M,K,visit[101][101];
vector<int> ans;
const int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
inline bool can(int x,int y){
	return 0<=x&&x<N&&0<=y&&y<M;
}
int dfs(int x,int y){
	int ret=0;
	if(m[x][y]==1||visit[x][y])return 0;
	visit[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=dx[i]+x,ny=dy[i]+y;
		if(can(nx,ny))ret+=dfs(nx,ny);
	}
	return ret+1;
}
int main(){
	cin>>M>>N>>K;
	while(K--){
		cin>>a>>b>>c>>d;
		for(int i=a;i<c;i++)for(int j=b;j<d;j++)m[i][j]=1;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int t=dfs(i,j);
			if(t)ret++,ans.push_back(t);
		}
	}
	cout<<ret<<endl;sort(ans.begin(),ans.end());
	for(auto i:ans)cout<<i<<" ";
}
