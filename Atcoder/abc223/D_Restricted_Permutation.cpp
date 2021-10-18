#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 2e5 + 1;
int N, M, deg[MAX];
vector<int> adj[MAX], ans;
set<int> rem;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, M){
        int u, v;
        cin >> u >> v;
        adj[u].eb(v);
        deg[v]++;
    }
    rep(i, 1, N + 1) if(deg[i] == 0) rem.insert(i);
    while(!rem.empty()){
        int u = *rem.begin(); rem.erase(u);
        ans.eb(u);
        for(auto v: adj[u]){
            deg[v]--;
            if(deg[v] == 0) rem.insert(v);
        }
    }
    if(ans.size() < N) cout << -1;
    else for(auto i: ans) cout << i << " ";
}
