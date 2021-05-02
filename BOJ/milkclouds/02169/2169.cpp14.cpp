#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const ll MAX=1e3+5,INF=1e12;
const int dx[]={0,0,-1}, dy[]={1,-1,0};

ll N,M,A[MAX][MAX],dist[MAX][MAX][3];
ll solution(int x,int y,int last){
	if(!(1<=x&&x<=N&&1<=y&&y<=M))return -INF;
	ll& ret=dist[x][y][last];
	if(ret>-INF)return ret;
	rep(i,0,3){
		if((last==1&&i==0)||(last==0&&i==1))continue;
		ret=max(ret,solution(x+dx[i],y+dy[i],i)+A[x][y]);
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	rep(i,0,N)rep(j,0,M)cin>>A[i+1][j+1];
	fill(dist[0][0],dist[N+2][M+2],-INF);
	dist[1][1][0]=dist[1][1][1]=dist[1][1][2]=A[1][1];
	cout<<solution(N,M,2);
}