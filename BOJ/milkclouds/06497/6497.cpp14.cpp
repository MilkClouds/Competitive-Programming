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
const int MAX=2e5+1;

priority_queue<ti> Edges;
int N, M, u, v, w, par[MAX], total;

int find(int u){return u ^ par[u] ? par[u] = find(par[u]) : u;}
bool merge(int u, int v){
	u=find(u); v=find(v);
	if(u ^ v){
		if(rand()&1) swap(u, v);
		par[u] = v;
		return 1;
	}
	return 0;
}

ll MST(){
	rep(i,0,N) par[i] = i;
	ll ret = 0, cnt = 1;
	while(!Edges.empty()) {
		tie(w,u,v) = Edges.top(); Edges.pop(); w=-w;
		if(merge(u, v)){
			ret += w;
			if(++cnt == N) break;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while((cin >> N >> M) && N){
		total = 0;
		while(!Edges.empty())Edges.pop();
		rep(i, 0, M){
			cin >> u >> v >> w;
			Edges.push({-w, u, v});
			total += w;
		}
		cout << total - MST() << "\n";
	}
}