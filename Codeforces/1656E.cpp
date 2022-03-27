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

const int MAX = 1e5 + 1;
int N, TC, u, v;
vector<int> adj[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N;
        vector<int> deg(N + 1);
        rep(i, 1, N + 1) adj[i].clear();
        rep(i, 1, N){
            cin >> u >> v;
            deg[u]++; deg[v]++;
            adj[u].eb(v);
            adj[v].eb(u);
        }
        function<void(int, int, int)> dfs = [&](int u, int par, int c){
            deg[u] *= c;
            for(auto v: adj[u]){
                if(v == par) continue;
                dfs(v, u, -c);
            }
        };
        dfs(1, 0, 1);
        rep(i, 1, N + 1) cout << deg[i] << " ";
        cout << "\n";
    }
}
