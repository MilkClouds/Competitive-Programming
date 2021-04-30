#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using p=pair<int,int>;
const int MAX=1e3+5, dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int n,m,A[MAX][MAX],dist[MAX][MAX];
p S;
void BFS(p S){
	queue<pair<p,int> > Q;
	Q.push({S,0});
	dist[S.x][S.y]=0;
	while(!Q.empty()){
		p cur=Q.front().x;
		int x=cur.x, y=cur.y;
		int d=Q.front().y; Q.pop();
		rep(i,0,4){
			int nx=x+dx[i], ny=y+dy[i];
			if( 0<=nx && nx<n && 0<=ny && ny<m){
				if(A[nx][ny]==0) continue;
				if(~dist[nx][ny]) continue;
				dist[nx][ny]=d+1;
				Q.push({{nx,ny}, d+1});
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	fill(dist[0],dist[m+1],-1);
	rep(i,0,n)rep(j,0,m){cin>>A[i][j];if(A[i][j]==2)S={i,j};if(A[i][j]==0)dist[i][j]=0;}
	BFS(S);
	rep(i,0,n){rep(j,0,m)cout<<dist[i][j]<<" ";cout<<"\n";}
}