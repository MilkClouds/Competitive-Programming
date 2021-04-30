#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
const int MAX = 1e3 + 1;
const int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

int N, M, K, A[MAX][MAX];

bool f(int D){
	vector<vector<bool> > visit(N, vector<bool>(M,0));
	queue<pi> Q;
	int cnt = 0;
	rep(j, 1, M - 1) if(A[0][j] <= D) {
		Q.push({0, j});
		visit[0][j] = 1;
	}
	rep(i, 0, N) {
		if(A[i][0] <= D){
			Q.push({i, 0});
			visit[i][0] = 1;
		}
		if(A[i][M - 1] <= D){
			Q.push({i, M - 1});
			visit[i][M-1] = 1;
		}
	}
	while(!Q.empty()){
		int x = Q.front().x, y = Q.front().y; Q.pop(); cnt++;
		rep(k, 0, 4){
			int nx = x + dx[k], ny = y + dy[k];
			if(0<=nx && nx<N && 0<=ny && ny<M){
				if(visit[nx][ny] || A[nx][ny] > D) continue;
				visit[nx][ny] = 1;
				Q.push({nx, ny});
			}
		}
	}
	return cnt >= K;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	rep(i, 0, N) rep(j, 0, M) cin >> A[i][j];
	int lo = 1, hi = 1e6 + 1;
	while(lo < hi){
		int m = lo + hi >> 1;
		if(f(m)) hi = m;
		else lo = m + 1;
	}
	cout << lo;
}