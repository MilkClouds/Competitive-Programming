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
const ll INF = 1e9;
const int MAX_N = 1000;
const int MAX_S = 101;
const int MAX_V = MAX_N * MAX_S + 2;
const int SuperSource = MAX_V - 1;
const int SuperSink = MAX_V - 2;


struct Edge{
	int u,v,c,f;
	Edge *dual;
	Edge():Edge(0,0,0){}
	Edge(int u,int v,int c):Edge(u,v,c,0){}
	Edge(int u,int v,int c,int f):u(u),v(v),c(c),f(f),dual(nullptr){}
	int spare(){return c - f;}
	void run(int x){
		f += x;
		dual -> f -= x;
	}
};
void link(Edge* A,Edge* B){
	A -> dual = B;
	B -> dual = A;
}
vector<Edge*> adj[MAX_V];
void build(int u,int v,int cap,int cap2){
	Edge *e = new Edge(u, v, cap), *e2 = new Edge(v, u, cap2);
	link(e, e2);
	adj[u].pb(e);
	adj[v].pb(e2);
}

int solve(){
	int N, Source, SinkNum, S, people, E, u, v, c, d, ans = 0;
	cin >> N >> Source >> people >> S >> SinkNum;
	rep(i, 0, MAX_V) adj[i].clear();
	Source--;

	// SuperSource to Source
	build(SuperSource, Source * MAX_S, people, 0);

	// Sink to SuperSink
	rep(_, 0, SinkNum){
		cin >> u; u--;
		rep(j, 0, S + 1){
			build(u * MAX_S + j, SuperSink, INF, 0);
		}
	} 
	cin >> E;
	rep(i, 0, E){
		cin >> u >> v >> c >> d; u--; v--;
		for(int j = 0; j + d <= S; j++)
			build(u * MAX_S + j, v * MAX_S + j + d, c, 0);
	}
	// past to future Wow!
	rep(i, 0, N){
		rep(j, 0, S){
			build(i * MAX_S + j, i * MAX_S + j + 1, INF, 0);
		}
	}
	while(1){
		vector<int> prev(MAX_V, -1);
		Edge *path[MAX_V] = {0};
		queue<int> Q;
		Q.push(SuperSource);

		while(!Q.empty() && prev[SuperSink] == -1){
			u = Q.front(); Q.pop();
			for(Edge *e : adj[u]){
				v = e -> v;
				if(e->spare()>0 && prev[v] == -1){
					prev[v] = u;
					path[v] = e;
					Q.push(v);
				}
			}
		}
		if(prev[SuperSink] == -1)break;
		int flow = INF;
		for(u = SuperSink; u ^ SuperSource; u = prev[u])
			flow = min(flow, path[u] -> spare());
		for(u = SuperSink; u ^ SuperSource; u = prev[u])
			path[u]->run(flow);
		ans += flow;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int TC;
	cin >> TC;
	rep(i, 0, TC) cout << solve() << "\n";
}