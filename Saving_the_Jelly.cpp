# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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

inline ll dist(pl A, pl B){
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}
int N;
vector<pl> A, B, ans, C[11];
vector<int> chk;
bool dfs(vector<int>& PERM, int i){
    if(i == N) return 1;
    auto&& close = C[PERM[i]];
    ll td = -1;
    for(auto [d, j]: close){
        if(chk[j]) continue;
        //cout << i << " " << j << " " << PERM[i] << " " << td << " " << d << endl;
        if(td == -1) td = d;
        else if(td < d) break;
        if(j == 0) continue;
        chk[j] = 1;
        ans.eb(PERM[i], j);
        if(dfs(PERM, i + 1)) return 1;
        chk[j] = 0;
        ans.pop_back();
    }
    return 0;
}
void solve(){
    cin >> N;
    A.resize(N); B.resize(N + 1); chk.assign(N + 1, 0); ans.clear();
    // vector<int> U(N, -1), V(N, -1);
    // vector<vector<int>> adj(N, vector<int>());
    rep(i, 0, N){
        cin >> A[i].x >> A[i].y;
    }
    rep(i, 0, N + 1){
        cin >> B[i].x >> B[i].y;
    }
    rep(u, 0, N){
        C[u].clear();
        rep(v, 0, N + 1){
            C[u].eb(dist(A[u], B[v]), v);
        }
        sort(all(C[u]));
    }
    vector<int> PERM(N); rep(i, 0, N) PERM[i] = i;
    do{
        if(dfs(PERM, 0)){
            cout << "POSSIBLE\n";
            for(auto [i, j]: ans) cout << i + 1 << " " << j + 1 << "\n";
            return;
        }
    }while(next_permutation(all(PERM)));
    cout << "IMPOSSIBLE\n";
    return;
    rep(i, 0, N){
        vector<pl> C;
        rep(j, 0, N + 1){
            C.eb(dist(A[i], B[j]), j);
        }
        sort(all(C));
        while(C.size() > 1 && C.back().x != C[0].x) C.pop_back();
        if(C.size() == 1 && C[0].y == 0){
            cout << "IMPOSSIBLE\n";
            return;
        }
        // for(auto [d, j]: C){
        //     if(j == 0) continue;
        //     adj[i].eb(j - 1);
        // }
    }
    // function<bool(int)> dfs = [&](int u){
    //     vis[u] = 1;
    //     for(auto v: adj[u]){
    //         if(V[v] == -1 || !vis[V[v]] && dfs(V[v])){
    //             U[u] = v;
    //             V[v] = u;
    //             return 1;
    //         }
    //     }
    //     return 0;
    // };
    // int cnt = 0;
    // rep(u, 0, N){
    //     if(U[u] == -1){
    //         vector<bool> vis(N);
    //         if(dfs(u)) cnt++;
    //     }
    // }
    // if(cnt < N){
    //     cout << "IMPOSSIBLE\n";
    //     return;
    // }
    // cout << "POSSIBLE\n";
    // rep(i, 0, )
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}

