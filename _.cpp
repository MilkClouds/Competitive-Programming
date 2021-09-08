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
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e5;
int N, M, u, v;
vector<int> adj[MAX];

int S[MAX], cycles;
bool isCut[MAX];
int dfs(int u, int nth = 0){
    S[u] = ++nth;
    int ret = S[u], childs = 0;
    for(auto v: adj[u]){
        if(S[v] == 0){
            childs++;
            int child = dfs(v, nth);
            if(nth > 1 && S[u] <= child) isCut[u] = ;
            ret = min(ret, child);
        }
        else ret = min(ret, S[v]);
    }
    if(nth == 1 && childs >= 2) isCut[u] = 1;
    return ret;
}
int solve(int u, int )
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, M){
        cin >> u >> v; u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    rep(i, 0, N) if(S[i] == 0) dfs(i); 
    rep(i, 0, N) cout << isCut[i];
}
