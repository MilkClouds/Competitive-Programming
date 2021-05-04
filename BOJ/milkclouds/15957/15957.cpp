# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ld = long double;


struct query{
    int T, S, P;
    bool operator < (const query& o) const {
        return T < o.T;
    }
};

const int MAX = 1e5 + 3;
// N <= 1e5, K <= 1e5, J <= 1e8
int N, K, J, par[MAX], song_to_singer[MAX], sz[MAX], T, S, P, l[MAX], r[MAX], dfsS[MAX], dfsE[MAX], cnt;
__int128 tree[MAX];
vector<query> QQ;
vector<int> adj[MAX], songs[MAX];
int dfs(int u){
    dfsS[u] = ++cnt;
    for(auto v: adj[u]){
        sz[u] += dfs(v);
    }
    dfsE[u] = cnt;
    return ++sz[u];
}
void tree_update(int i, int x){
    for(;i <= N; i += i & -i) tree[i] += x;
}
__int128 tree_query(int i){
    __int128 ret = 0;
    for(; i; i ^= i & -i) ret += tree[i];
    return ret;
}
void update(int S, int P){
    tree_update(dfsS[S], P);
    tree_update(dfsE[S] + 1, -P);
}
__int128 sum(int singer){
    __int128 ret = 0;
    for(auto song: songs[singer]) {
        ret += tree_query(dfsS[song]);
    }
    return ret;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K >> J;
    rep(i, 2, N + 1){
        cin >> par[i];
        adj[par[i]].pb(i);
    }
    dfs(1);
    rep(i, 1, N + 1) {
        cin >> song_to_singer[i];
        songs[song_to_singer[i]].pb(i);
    }
    rep(i, 0, K){
        cin >> T >> S >> P;
        QQ.pb({T, S, P / sz[S]});
    }
    sort(all(QQ));
    fill(l, l + N + 1, 0);
    fill(r, r + N + 1, K + 1);
    while(1){
        vector<vector<int>> event(K + 1, vector<int>()); // time to singer
        fill(tree, tree + N + 1, 0);
        cnt = 0;
        rep(i, 1, N + 1){
            if(r[i] - l[i] == 1) continue;
            event[l[i] + r[i] >> 1].pb(i);
            cnt++;
        }
        if(cnt == 0) break;
        int i = 1;
        for(auto tmp: QQ){
            T = tmp.T; S = tmp.S; P = tmp.P;
            update(S, P);
            for(auto singer: event[i]){
                if(sum(singer) > (__int128) J * songs[singer].size()) r[singer] = i;
                else l[singer] = i;
            }
            i++;
        }
    }
    rep(i, 1, N + 1){
        int tmp = r[song_to_singer[i]];
        cout << (tmp <= K ? QQ[tmp - 1].T : -1) << "\n";
    }
}
