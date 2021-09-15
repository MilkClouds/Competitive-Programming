#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define fi first
#define se second

const int MAXN = 200010;

vector<pii> ed[MAXN];
int sz[MAXN];
bool vis[MAXN];

void dfs(int x, int p) {				// 서브트리들의 크기를 구한다
	sz[x] = 1;
	for(auto a : ed[x]) if(!vis[a.se] && a.se != p) {
		dfs(a.se, x);
		sz[x] += sz[a.se];
	}
}

void solve(int x) {					// x를 포함하는 서브트리에서 문제 해결
	dfs(x, -1);					// x를 루트로 하는 트리에서 각 서브트리의 크기 구함
	int s = sz[x];
	while(1) {					// x <- centroid
		bool b = false;
		for(auto a : ed[x]) if(!vis[a.se] && sz[a.se] < sz[x] && 2 * sz[a.se] >= s) {
			x = a.se;
			b = true;
			break;
		}
		if(!b) break;
	}
	//TODO
	vis[x] = true;					// x를 보았다고 확인
	for(auto a : ed[x]) if(!vis[a.se]) solve(a.se);	// 나누어진 서브트리에서 문제 해결
}
