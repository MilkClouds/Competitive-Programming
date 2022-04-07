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

const int MAX = 1001, INF = 1e9;
int N, A, B, u, v, d, dist[MAX];
vector<ti> edges;
bool relax(){
    bool ret = 0;
    for(auto& [u, v, d]: edges){
        if(dist[u] + d < dist[v]){
            dist[v] = dist[u] + d;
            ret = 1;
        }
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> A >> B;
    rep(i, 1, N) edges.eb(i + 1, i, 0);
    rep(i, 0, A){
        cin >> u >> v >> d;
        edges.eb(u, v, d);
    }
    rep(i, 0, B){
        cin >> u >> v >> d;
        edges.eb(v, u, -d);
    }
    fill(dist + 2, dist + N + 1, INF);
    rep(i, 1, N) relax();
    if(relax()){cout << "-1\n";}
    else if(dist[N] == INF){cout << "-2\n";}
    else cout << dist[N] << "\n";
}
