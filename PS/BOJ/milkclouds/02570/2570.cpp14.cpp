#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,M,a,b,board[101][101],id[101][101][2],cnt[2],match[10000],rev[10000];
vector<int> adj[10000];
vector<bool> visit;
const int dx[]={1,1},dy[]={1,-1};
void make(int dir){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(board[i][j]||id[i][j][dir])continue;
			int x=i,y=j;cnt[dir]++;
			while(1){
				id[x][y][dir]=cnt[dir];
				x+=dx[dir];y+=dy[dir];
				if(!(0<x&&0<y&&x<=N&&y<=N)||board[x][y])break;
			}
		}
	}
}
bool dfs(int u){
	if(visit[u])return 0;
	visit[u]=1;
	for(auto v:adj[u]){
		if(!rev[v] or dfs(rev[v])){
			rev[v]=u;
			return 1;
		}
	}
}
int bipartiteMatch(){
	int ret=0;
	for(int i=1;i<=cnt[0];i++){
		visit.assign(cnt[0],0);
		ret+=dfs(i);
	}
	return ret;
}
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		board[a][b]=1;
	}
	make(0);make(1);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(board[i][j])continue;
			adj[id[i][j][0]].push_back(id[i][j][1]);
		}
	}
	cout<<bipartiteMatch();
}