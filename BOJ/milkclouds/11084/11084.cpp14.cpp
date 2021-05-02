#include <bits/stdc++.h>
using namespace std;
int r,c,dp[500][500];
bool visit[500][500];
const int dx[]={2,2,1,1,-1,-1,-2,-2};
const int dy[]={1,-1,2,-2,2,-2,1,-1}, MOD=1e9+9;
typedef pair<int,int> pii;
inline bool can(int x,int y){
	return 0<=x && x<r && 0<=y && y<c;
}
string BFS(){
	queue<pii> Q;
	Q.push({0,0});
	visit[0][0]=dp[0][0]=1;
	int idx=0,flag=0;
	for(;!Q.empty();idx++){
		int sz=Q.size();
		for(int p=0;p<sz;p++){
			auto [x,y]=Q.front();Q.pop();
			if(x==r-1&&y==c-1){flag=1;break;}
			for(int i=0;i<8;i++){
				int nx=x+dx[i],ny=y+dy[i];
				if(!can(nx,ny))continue;
				if(!flag) dp[nx][ny] = (dp[nx][ny] + dp[x][y])%MOD;
				if(visit[nx][ny])continue;
				visit[nx][ny]=1;
				Q.push({nx,ny});
			}
		}
		if(flag)break;
	}
	if(!flag) return "None";
	return to_string(idx)+" "+to_string(dp[r-1][c-1]);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >>r >> c;
	fill(visit[0],visit[max(r,c)],0);
	cout<<BFS()<<'\n';
}