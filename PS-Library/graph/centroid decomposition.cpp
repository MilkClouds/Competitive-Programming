#include<bits/stdc++.h>
#define y second
using namespace std;

typedef pair<int, int> pi;

const int MAXN = 200010;

vector<int> adj[MAXN];
int sz[MAXN];
bool vis[MAXN];

int getSize(int u, int p) {
	sz[u] = 1;
	for(auto v: adj[u]) if(!vis[v] && v != p) {
		sz[u] += getSize(v, u);
	}
	return sz[u];
}
int _centroid(int u, int s){
	for(auto v: adj[u]) if(!vis[v] && sz[v] < sz[u] && 2 * sz[v] >= s) return _centroid(v, s);
	return u;
}
int centroid(int u){
	int s = getSize(u, -1);
	return _centroid(u, s);
}

// centroid decomposition
void solve(int u) {
	u = centroid(u);
	vis[u] = true;
	for(auto v: adj[u]) if(!vis[v]) solve(v);
}
