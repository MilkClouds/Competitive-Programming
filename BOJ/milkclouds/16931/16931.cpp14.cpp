#include <bits/stdc++.h>
using namespace std;

const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int N,M,ans,p[101][101];
inline bool can(int i,int j){return 0<=i && i<N && 0<=j && j<M;}
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)cin>>p[i][j];
	for(int i=0;i<N;i++)for(int j=0;j<M;j++){
		ans+=4*p[i][j]+2;
		for(int k=0;k<4;k++){
			int nx=i+dx[k],ny=j+dy[k];
			if(can(nx,ny))ans-=min(p[i][j],p[nx][ny]);
		}
	}
	cout<<ans;
}