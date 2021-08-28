#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define rep2(i,a,b) for(ll i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pl = pair<ll, ll>;
typedef pair<ll, ll> Line;

const ll MAX = 1e5 + 100;
ll N, u, v, d, S[MAX], V[MAX];
vector<pl> adj[MAX];
ll dist[MAX], ans[MAX];
struct ABC{
    ll top, idx;
    Line line;
};
struct CHT{
	vector<Line> lines;
	vector<int> idx;
    CHT(): CHT(0){}
    CHT(int N): lines(N), idx(N) {}
	int top = 0;

	ll f(Line line, ll x){
		return line.x * x + line.y;
	}
	ld intersect(Line a, Line b){ // aware div-by-0
		return (ld) (b.y - a.y) / (a.x - b.x);
	}

	int nth(Line line){
		// 기울기가 전과 같아서 평행한 경우는 안 구현함. stritly increasing 가정
		int l = 0, r = top;
		while (l < r)
		{
			int m = l + r >> 1;
			if(intersect(line, lines[m - 1]) < intersect(lines[m - 1], lines[m])) r = m;
			else l = m + 1;
		}
		return l;
	}
	void insert(Line line, int i, ABC& rem){
		top = nth(line);
        rem.idx = top;
        rem.line = lines[top];
		lines[top] = line;
		idx[top] = i;
		top++;
	}

	pl get(ll x){
		int l = 0, r = top;
		while(l + 1 < r){
			int m = l + r >> 1;
			if(intersect(lines[m], lines[m - 1]) < x) l = m;
			else r = m;
		}
		return {f(lines[l], x), idx[l]};
	}
} cht;
void dfs(ll u, ll par){
    ABC rem = {cht.top};
    ans[u] = -cht.get(V[u]).x + dist[u] * V[u] + S[u];
    cht.insert({dist[u], -ans[u]}, u, rem);
    for(auto& [v, d]: adj[u]){
        if(v == par) continue;
        dist[v] = dist[u] + d;
        dfs(v, u);
    }
    cht.top = rem.top;
    cht.lines[rem.idx] = rem.line;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cht = CHT(N + 1);
    rep(i, 1, N){
        cin >> u >> v >> d;
        adj[u].eb(v, d);
        adj[v].eb(u, d);
    }
    rep(i, 2, N + 1){
        cin >> S[i] >> V[i];
    }
    dfs(1, 0);
    rep(i, 2, N + 1) cout << ans[i] << " ";
}
