#include <bits/stdc++.h>

using namespace std;

const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
struct edge{
	int a,b,c;
	bool operator <(edge A) const{return c>A.c;}
};
int n,m,visit[100][100];
int main(){
	char maze[100][101];
	priority_queue<edge> pq;
	cin>>m>>n;
	for(int i=0;i<n;i++)cin>>maze[i];
	pq.push({0,0,0});
	while(!pq.empty()){
		edge top=pq.top();pq.pop();
		if(top.a==n-1 && top.b==m-1){return !printf("%d",top.c);}
		for(int k=0;k<4;k++){
			int nx=top.a+dx[k],ny=top.b+dy[k];
			if(!(0<=nx and nx<n and 0<=ny and ny<m))continue;
			int nd=top.c+(maze[nx][ny]=='1'?1:0);
			if(!visit[nx][ny]){
				pq.push({nx,ny,nd});
				visit[nx][ny]=1;
			}
		}
	}
}