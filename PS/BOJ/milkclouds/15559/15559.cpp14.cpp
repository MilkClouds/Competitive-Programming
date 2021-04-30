#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
const int MAX = 1e3 + 1;
const int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};

bool visit[MAX][MAX], finished[MAX][MAX];
int N, M, cnt;
string S[MAX];
queue<pi> Q;

int conv(char S){
	if(S=='N')return 0;
	if(S=='S')return 1;
	if(S=='W')return 2;
	return 3;
}

bool dfs(int u,int v){
	if(finished[u][v]) return 0;
	if(visit[u][v]) return 1;
	Q.push({u, v});
	visit[u][v] = 1;
	int t = conv(S[u][v]);
	return dfs(u + dx[t], v + dy[t]);
}
int main(){
	cin >> N >> M;
	rep(i, 0, N) cin >> S[i];
	rep(i,0,N)rep(j,0,M){
		if(finished[i][j])continue;
		cnt += dfs(i,j);
		while(!Q.empty()){
			finished[Q.front().x][Q.front().y] = 1;
			Q.pop();
		}
	}
	cout << cnt;
}