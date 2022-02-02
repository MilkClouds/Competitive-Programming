#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

void solve(){
    int N, K;
    cin >> N >> K;
    vector<int> A(K), vis(N), deg(N);
    vector<vector<int>> adj(N, vector<int>());
    rep(i, 0, K) cin >> A[i], A[i]--;
    rep(i, 1, N){
        int u, v;
        cin >> u >> v; u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
        deg[u]++;
        deg[v]++;
    }
    queue<int> ban, go;
    rep(i, 0, K) ban.push(A[i]), vis[A[i]] = -A[i];
    go.push(0), vis[0] = 1;
    // vis 0: not yet, 1: possible, -1: impossible
    do{
        int tmp = ban.size();
        rep(_, 0, tmp){
            int u = ban.front(); ban.pop();
            for(auto v: adj[u]){
                if(vis[v] == 0){
                    ban.push(v);
                    vis[v] = -u;
                }
            }
        }
        tmp = go.size();
        rep(_, 0, tmp){
            int u = go.front(); go.pop();
            for(auto v: adj[u]){
                if(vis[v] == 0){
                    go.push(v);
                    vis[v] = 1;
                }
            }
        }
    }while(!go.empty());
    bool flag = 0;
    rep(i, 1, N) if(deg[i] == 1 && vis[i] == 1) flag = 1;
    if(flag) cout << "-1\n";
    else{
        go.push(0); vis[0] = 2;
        set<int> bans;
        while(!go.empty()){
            int u = go.front(); go.pop();
            for(auto v: adj[u]){
                if(vis[v] == 1) go.push(v), vis[v] = 2;
                else if(vis[v] < 0){
                    bans.insert(-vis[v]);
                }
            }
        }
        cout << bans.size() << "\n";
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--) solve();
}
