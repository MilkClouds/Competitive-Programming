#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int N,K,world[2010][2010],x,y,i,ans,ranks[100010],parent[100010];
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
queue<pii> q,qq;

void init(){for(int n=0;n<=100000;n++){ranks[n]=1;parent[n]=n;}}
int find(int v){
	if(parent[v]==v)return v;
	return parent[v]=find(parent[v]);
}
bool merge(int u,int v){
	u=find(u);v=find(v);
	if(u==v)return 1;
	if(ranks[u]<ranks[v])swap(u,v);
	parent[v]=u;
	if(ranks[u]==ranks[v])ranks[u]++;
	return 0;
}
inline bool can(int x,int y){
	return (0<x and x<=N and 0<y and y<=N);
}
void bfs_union(){
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		qq.push(q.front());
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(!can(nx,ny))continue;
			if(world[nx][ny] and world[nx][ny]!=world[x][y])
				if(!merge(world[nx][ny],world[x][y]))
					K--;
		}
	}
}
void bfs_propagation(){
	while(!qq.empty()){
		int x=qq.front().first;
		int y=qq.front().second;
		qq.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(!can(nx,ny))continue;
			if(!world[nx][ny]){
				world[nx][ny]=world[x][y];
				q.push({nx,ny});
			}
		}		
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>K;
	for(int i=1;i<=K;i++){
		cin>>x>>y;
		world[x][y]=i;
		q.push({x,y});
	}
	init();
	while(K>1){
		bfs_union();
		if(1==K)break;
		ans++;
		bfs_propagation();
	}
	cout<<ans;
}