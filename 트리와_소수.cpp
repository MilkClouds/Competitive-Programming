#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;


int n;
const int MAXN = 50010;

vector<pi> adj[MAXN];
int sz[MAXN];
bool vis[MAXN];

void dfs(int x, int p) {				// 서브트리들의 크기를 구한다
	sz[x] = 1;
	for(auto a : adj[x]) if(!vis[a.y] && a.y != p) {
		dfs(a.y, x);
		sz[x] += sz[a.y];
	}
}

void solve(int x) {					// x를 포함하는 서브트리에서 문제 해결
	dfs(x, -1);					// x를 루트로 하는 트리에서 각 서브트리의 크기 구함
	int s = sz[x];
	while(1) {					// x <- centroid
		bool b = false;
		for(auto a : adj[x]) if(!vis[a.y] && sz[a.y] < sz[x] && 2 * sz[a.y] >= s) {
			x = a.y;
			b = true;
			break;
		}
		if(!b) break;
	}
	//TODO
	vis[x] = true;					// x를 보았다고 확인
	for(auto a : adj[x]) if(!vis[a.y]) solve(a.y);	// 나누어진 서브트리에서 문제 해결
}



int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> n;
    rep(i, 1, n){
        int u, v;
        cin >> u >> v;
        adj[u].eb(1, v);
        adj[v].eb(1, u);
    }
    solve(1);
}
