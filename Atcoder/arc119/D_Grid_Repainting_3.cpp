# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using pii = pair<int, int>;
using ld = long double;

struct ABC{
    char a; int b, c;
};
vector<ABC> ans;

bool vis[5001];
int R, C, r, c;
string S[2501];
vector<int> adj[5001];
void dfs(int u){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(vis[v]) continue;
        dfs(v);
        u < R ? ans.pb({'Y', u, v - R}) : ans.pb({'X', v, u - R});
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> R >> C;
    r = R; c = C;
    rep(i, 0, R) cin >> S[i];
    rep(i, 0, R) rep(j, 0, C){
        if(S[i][j] == 'R'){
            if(adj[i].size() == 0) r--;
            if(adj[j + R].size() == 0) c--;
            adj[i].pb(j + R);
            adj[j + R].pb(i);
        }
    }
    int s = r < c ? R : 0;
    int e = r < c ? R + C : R;
    rep(i, s, e){
        if(!vis[i]) dfs(i);
    }
    cout << ans.size() << endl;
    for(auto [a, b, c]: ans) cout << a << " " << b + 1 << " " << c + 1 << "\n";
}