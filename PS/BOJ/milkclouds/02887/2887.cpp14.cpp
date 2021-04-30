# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const int MAX=1e5;

priority_queue<ti> Edges;
ti coord[MAX];

int N, par[MAX], u, v, w;
pi x[MAX], y[MAX], z[MAX];
int find(int u){return u ^ par[u] ? par[u] = find(par[u]) : u;}
bool merge(int u, int v){
	u=find(u); v=find(v);
	if(u ^ v){
		if(rand() & 1) swap(u, v);
		par[u] = v;
		return 1;
	}
	return 0;
}

ll MST(){
	rep(i, 0, N) par[i] = i;
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

int dist(ti a,ti b){
	ll ret = 1e9;
	ret = min(ret, abs(get<0>(a) - get<0>(b)));
	ret = min(ret, abs(get<1>(a) - get<1>(b)));
	ret = min(ret, abs(get<2>(a) - get<2>(b)));
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 0, N){
		cin >> x[i].f >> y[i].f >> z[i].f;
		coord[i] = {x[i].f, y[i].f, z[i].f};
		x[i].s = y[i].s = z[i].s = i;
	}
	sort(x, x + N); sort(y, y + N); sort(z, z + N);
	rep(i, 1, N){
		for(auto arr: {x, y, z}){
			u = arr[i].s, v = arr[i-1].s;
			Edges.push({-dist(coord[u], coord[v]), u, v});
		}
	}
	cout << MST();
}