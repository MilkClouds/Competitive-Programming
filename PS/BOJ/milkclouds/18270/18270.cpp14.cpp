# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;

ll N;
string u, v, dummy, cand = "ZZZZZZZZZZZZZZZZZZZZZZZZZZ";
priority_queue<string, vector<string>, greater<string> > pq;
unordered_map<string, vector<string> > adj;
unordered_map<string, bool> visit;
unordered_map<string, ll> degree;

void BFS(string root){
	priority_queue<string> pq;
	pq.push(root); visit[root] = 1;
	while(!pq.empty()){
		string u = pq.top(); pq.pop();
		cout << u << "\n";
		for(string v : adj[u]){
			if(visit[v])continue;
			visit[v] = 1;
			pq.push(v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 0, N){
		cin >> u;
		rep(_, 0, 4) cin >> dummy;
		cin >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		degree[u]++; degree[v]++;
	}
	for(string s : {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"
}) if(degree[s] < 2) pq.push(s);
		// cand = min(cand, it -> first);
	// pq.push(cand);
	while(!pq.empty()){
		u = pq.top(); pq.pop();
		if(visit[u]) continue;
		BFS(u);
	}
}