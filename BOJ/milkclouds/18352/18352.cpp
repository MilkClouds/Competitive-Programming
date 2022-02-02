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

const int MAX = 3e5 + 1;
int N, M, K, X, u, v, vis[MAX], cnt;
vector<int> adj[MAX], ans;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> K >> X;
    rep(i, 0, M){
        cin >> u >> v;
        adj[u].eb(v);
    }
    queue<int> Q; Q.push(X); vis[X] = 1;
    while(!Q.empty()){
        int t = Q.size();
        rep(_, 0, t){
            int u = Q.front(); Q.pop();
            if(cnt == K) ans.eb(u);
            for(auto v: adj[u]){
                if(vis[v]) continue;
                vis[v] = 1;
                Q.push(v);
            }
        }
        cnt++;
    }
    sort(all(ans));
    if(ans.empty()) cout << -1;
    else for(auto i: ans) cout << i << "\n";
}
