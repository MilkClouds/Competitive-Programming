#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define rep2(i,a,b) for(ll i = (b) - 1; i >= (a); i--)
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
    int N, M, u, v, T = 0, cnt = 0, flip = 0;
    cin >> N >> M;
    vector<vector<int>> adj(N, vector<int>()), h(N);
    vector<int> vin(N), vout(N), clr(N, -1);
    vector<array<int, 2>> A(N);
    rep(i, 0, M){
        cin >> u >> v; u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    function<void(int)> dfs = [&](int u){
        vin[u] = T++;
        for(auto v: adj[u]) {
            if(-1 == clr[v]) h[u].eb(v), clr[v] = clr[u] ^ 1, dfs(v);
            else if(vin[u] > vin[v]){
                int diff = clr[u] ^ clr[v];
                if(!diff){
                    flip = clr[u] ^ 1;
                    cnt++;
                }
                A[u][diff]++;
                A[v][diff]--;
            }
        }
        vout[u] = T;
    };
    clr[0] = 0;
    dfs(0);
    if(cnt <= 1){cout << "YES\n"; rep(i, 0, N) cout << (clr[i] ^ flip); cout << "\n"; return;}
    int sv = -1;
    dfs = [&](int u){
        for(auto v: h[u]){
            dfs(v);
            if(A[v][0] == cnt && A[v][1] == 1){
                sv = v;
                flip = clr[u] ^ 1;
            }
            rep(k, 0, 2) A[u][k] += A[v][k];
        }
    };
    dfs(0);
    if(sv == -1){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        rep(i, 0, N) cout << (clr[i] ^ flip ^ (vin[sv] <= vin[i] && vout[i] <= vout[sv]));
        cout << "\n";
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--) solve();
}
