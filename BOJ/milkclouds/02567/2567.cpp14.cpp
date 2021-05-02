#include <bits/stdc++.h>
using namespace std;
int x,y,m[101][101],ret,N;
const int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
inline bool can(int x,int y){
	return 0<x&&x<=100&&0<y&&y<=100;
}
int main(){
	cin>>N;
	while(N--){
		cin>>x>>y;
		for(int i=0;i<10;i++)for(int j=0;j<10;j++)m[x+i][y+j]=1;
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(m[i][j]==0)continue;
			int r=4;
			for(int k=0;k<4;k++){
				int nx=i+dx[k],ny=j+dy[k];
				if(can(nx,ny))r-=m[nx][ny];
			}
			ret+=r;
		}
	}
	cout<<ret;
}
