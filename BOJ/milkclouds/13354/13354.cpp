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

const int MAX = 1111;
int N, M, Q, a, b, c, d, cnt, C, ans[11111], par[MAX * MAX], sz[MAX * MAX], R[MAX * MAX];
vector<pi> V[11111];
bool A[MAX][MAX];
int find(int u){return par[u] = u == par[u] ? u : find(par[u]);}
int merge(int u, int v){
    if(R[v] == 0 || 0 == R[u]) return 0;
    u = R[u], v = R[v];
    u = find(u); v = find(v);
    if(u == v) return 0;
    cnt--;
    if(sz[u] > sz[v]) swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
    return 1;
}
void Merge(int x, int y){
    R[x * (M + 1) + y] = ++C;
    cnt++;
    merge(x * (M + 1) + y, (x - 1) * (M + 1) + y);
    merge(x * (M + 1) + y, (x + 1) * (M + 1) + y);
    merge(x * (M + 1) + y, x * (M + 1) + y - 1);
    merge(x * (M + 1) + y, x * (M + 1) + y + 1);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> Q;
    rep(i, 0, (N + 1) * (M + 1) + 1) par[i] = i, sz[i] = 1;
    rep(i, 0, Q){
        cin >> a >> b >> c >> d;
        if(a == c){
            rep(j, b, d + 1){
                if(A[a][j] == 0){
                    A[a][j] = 1;
                    V[i].eb(a, j);
                }
            }
        } else {
            rep(j, a, c + 1){
                if(A[j][b] == 0){
                    A[j][b] = 1;
                    V[i].eb(j, b);
                }
            }
        }
    }
    rep(i, 1, N + 1) rep(j, 1, M + 1) if(A[i][j] == 0) V[Q].eb(i, j);
    rep2(i, 0, Q + 1){
        for(auto [x, y]: V[i]) {
            Merge(x, y);
        }
        ans[i] = cnt;
    }
    rep(i, 1, Q + 1) cout << ans[i] << "\n";
}


