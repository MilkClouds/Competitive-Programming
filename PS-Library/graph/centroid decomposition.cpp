#include<bits/stdc++.h>
#define y second
using namespace std;

typedef pair<int, int> pi;

const int MAXN = 200010;

vector<pi> adj[MAXN];
int sz[MAXN];
bool vis[MAXN];

int getSize(int u, int p) {				// 서브트리들의 크기를 구한다
	sz[u] = 1;
	for(auto e : adj[u]) if(!vis[e.y] && e.y != p) {
		sz[u] += getSize(e.y, u);
	}
	return sz[u];
}

void solve(int u) {
	int s = getSize(u, -1);
	while(1) {
		bool b = false;
		for(auto e : adj[u]) if(!vis[e.y] && sz[e.y] < sz[u] && 2 * sz[e.y] >= s) {
			u = e.y;
			b = true;
			break;
		}
		if(!b) break;
	}
	vis[u] = true;
	for(auto e : adj[u]) if(!vis[e.y]) solve(e.y);	// 나누어진 서브트리에서 문제 해결
}
