#include <bits/stdc++.h>
using namespace std;
int TC,N,a,b,c,d;
bool visit[501][501];
const int dx[]={-2,-2,0,0,2,2};
const int dy[]={1,-1,-2,2,-1,1};
typedef pair<int,int> pii;
inline bool can(int x,int y){
	return 0<=x && x<N && 0<=y && y<N;
}
int BFS(){
	queue<pii> Q;
	Q.push({a,b});
	visit[a][b]=1;
	int idx=0,flag=0;
	for(;!Q.empty();idx++){
		int sz=Q.size();
		for(int p=0;p<sz;p++){
			auto [x,y]=Q.front();Q.pop();
			if(x==c&&y==d){flag=1;break;}
			for(int i=0;i<6;i++){
				int nx=x+dx[i],ny=y+dy[i];
				if(!can(nx,ny)||visit[nx][ny])continue;
				visit[nx][ny]=1;
				Q.push({nx,ny});
			}
		}
		if(flag)break;
	}
	return flag?idx:-1;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	TC=1;
	while(TC--){
		cin>>N>>a>>b>>c>>d;
		for(int i=0;i<N;i++)fill(visit[i],visit[i]+N,0);
		cout<<BFS()<<'\n';
	}
}