#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, MAX = 501;

struct ABC{
	ll x,y,z;
	bool operator < (ABC o) const {
		return z < o.z;
	}
};

ll N, M, ans = 1e9;
char C[MAX][MAX];
vector<vector<ll> > dist(MAX, vector<ll>(MAX, -1)), vis(MAX, vector<ll>(MAX, 0));
pi S, E;
queue<pi> tree;
priority_queue<ABC> pq;
inline bool valid(ll x, ll y){return 0 <= x && x < N && 0 <= y && y < M;}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	rep(i, 0, N) rep(j, 0, M){
		cin >> C[i][j];
		if(C[i][j] == '+'){
			tree.push({i, j});
			dist[i][j] = 0;
		}
		else if (C[i][j] == 'V') S = {i, j};
		else if (C[i][j] == 'J') E = {i, j}; 
	}
	while(!tree.empty()){
		pi cur = tree.front(); tree.pop();
		ll x = cur.x, y = cur.y;
		rep(i, 0, 4){
			ll nx = x + dx[i], ny = y + dy[i];
			if(valid(nx, ny)){
				if(~dist[nx][ny]) continue;
				dist[nx][ny] = dist[x][y] + 1;
				tree.push({nx, ny});
			}
		}
	}
	pq.push({S.x, S.y, dist[S.x][S.y]});
	vis[S.x][S.y] = 1;
	while(!pq.empty()){
		ll x,y;
		x = pq.top().x, y = pq.top().y; ans = min(ans, pq.top().z);
		pq.pop();
		if(x == E.x && y == E.y) break;
		rep(i, 0, 4){
			ll nx = x + dx[i], ny = y + dy[i];
			if(!valid(nx, ny) || vis[nx][ny]) continue;
			vis[nx][ny] = 1;
			pq.push({nx, ny, dist[nx][ny]});
		}
	}
	cout << ans << endl;
}