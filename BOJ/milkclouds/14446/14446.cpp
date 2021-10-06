#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
using pi = pair<int, int>;
using ti = tuple<int, int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e5;
int N, A[MAX], par[MAX], S[MAX], E[MAX], cnt, ans[MAX];
vector<int> adj[MAX];
priority_queue<ti> events;
ll tree[MAX + 2];
void update(int i, int x){ i++;
    for(; i <= MAX + 1; i += i & -i) tree[i] += x;
}
ll query(int i){ i++;
    ll ret = 0;
    for(; i; i &= i - 1) ret += tree[i];
    return ret;
}
void dfs(int u){
    S[u] = ++cnt;
    for(auto v: adj[u]){
        if(par[u] == v) continue;
        dfs(v);
    }
    E[u] = cnt;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 1, N) {
        cin >> par[i], par[i]--;
        adj[par[i]].eb(i), adj[i].eb(par[i]);
    }
    dfs(0);
    rep(i, 0, N){
        events.em(A[i], S[i], E[i], i);
    }
    while(!events.empty()){
        auto [a, s, e, i] = events.top(); events.pop();
        ans[i] = query(e) - query(s - 1);
        update(s, 1);
    }
    rep(i, 0, N) cout << ans[i] << "\n";
}
