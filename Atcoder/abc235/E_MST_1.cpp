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
using ti = tuple<int, int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 2e5 + 1;
int N, M, Q, ans[MAX], p, q;
priority_queue<ti> pq;

int par[MAX];
int find(int i){
    return i == par[i] ? i : par[i] = find(par[i]);
}
bool merge(int i, int j){
    i = find(i); j = find(j);
    if(i == j) return 0;
    if(rand() & 1){
        swap(i, j);
    }
    par[i] = j;
    p = i, q = j;
    return 1;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> Q;
    rep(i, 1, N + 1) par[i] = i;
    rep(i, 0, M){
        int a, b, c;
        cin >> a >> b >> c;
        // adj[a].eb
        pq.emplace(-c, a, b, -1);
    }
    rep(i, 0, Q){
        int u, v, w;
        cin >> u >> v >> w;
        pq.emplace(-w, u, v, i);
    }
    while(!pq.empty()){
        auto [w, u, v, i] = pq.top(); pq.pop();
        bool s = merge(u, v);
        if(~i && s){
            ans[i] = s;
            par[p] = p;
        }
    }
    rep(i, 0, Q) cout << (ans[i] ? "Yes" : "No") << "\n";
}
