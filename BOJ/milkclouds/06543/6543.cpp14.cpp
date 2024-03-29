# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const int MAX=5e3+1;

int N, M, u, v, finished[MAX], visit[MAX], sccN[MAX], cnt, scc_cnt, outdegree[MAX];
vector<int> adj[MAX];
stack<int> S;

int DFS_SCC(int u){
	if(visit[u]) return 0;
	visit[u] = ++cnt;
	S.push(u);
	int ret = visit[u];
	for(auto v: adj[u]){
		if(!visit[v]) ret = min(ret, DFS_SCC(v));
		else if(!finished[v]) ret = min(ret, visit[v]);
	}
	if(visit[u] == ret){
		while(S.top() ^ u){
			sccN[S.top()] = scc_cnt;
			finished[S.top()] = 1;
			S.pop();
		}
		sccN[u] = scc_cnt++; S.pop();
		finished[u] = 1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while((cin >> N) && N){
		rep(i, 0, N) adj[i+1].clear();
		fill(finished, finished+N+1, 0);
		fill(visit, visit+N+1, 0);
		fill(outdegree, outdegree+N+1, 0);
		cnt = scc_cnt = 0;

		cin >> M;
		rep(i, 0, M){
			cin >> u >> v;
			adj[u].pb(v);
		}
		rep(i, 0, N) DFS_SCC(i+1);
		rep(u, 1, N + 1)
			for(auto v : adj[u]) if(sccN[u]^sccN[v]) outdegree[sccN[u]]++;
		rep(i, 1, N + 1) if(outdegree[sccN[i]]==0) cout << i << " ";
		cout << "\n";
	}
}