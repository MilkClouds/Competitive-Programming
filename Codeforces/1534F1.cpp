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
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;
using ti = tuple<int, int, int>;

const int MAX = 4e5, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1}, UP = 1, DOWN = 0, LEFT = 2, RIGHT = 3;
int N, M; 
string S[MAX];
vector<int> adj[MAX], adj2[MAX], deg;
inline bool valid(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}
int conv(int x, int y){
    return x * M + y;
}
void make(int p, int q, int x, int y, int dir){
    int nx = x + dx[dir], ny = y + dy[dir];
    if(!valid(nx, ny)) return;
    if(S[nx][ny] == '.') return;
    adj[conv(p, q)].pb(conv(nx, ny));
}
struct scc_graph {
    scc_graph() : scc_graph(0) {}
    scc_graph(int N) : dfsn(N), sn(N), finished(N), N(N){}

    int cnt = 0, SN = 0, N;
    vector<int> dfsn, sn, finished;
    vector<vector<int>> SCC;
    stack<int> S;

    int scc(int u) {
        dfsn[u] = ++cnt;
        S.push(u);
        int result = dfsn[u];
        for (int v : adj[u]) {
            if (dfsn[v] == 0) result = min(result, scc(v));
            else if (!finished[v]) result = min(result, dfsn[v]);
        }
        if (result == dfsn[u]) {
            vector<int> currSCC;
            while (1) {
                int t = S.top();
                S.pop();
                currSCC.push_back(t);
                finished[t] = true;
                sn[t] = SN;
                if (t == u) break;
            }
            sort(currSCC.begin(), currSCC.end());
            SCC.push_back(currSCC);
            SN++;
        }
        return result;
    }
};
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, 0, N) cin >> S[i];
    rep(j, 0, M) {
        int chk = -1;
        rep(i, 0, N) {
            if(S[i][j] == '.' && chk == -1) continue;
            if(S[i][j] == '#'){
                chk = i;
                make(i, j, i, j, UP);
            }
            make(chk, j, i, j, DOWN);
            make(chk, j, i, j, LEFT);
            make(chk, j, i, j, RIGHT);
        }
    }
    scc_graph SCC(N * M);
    rep(i, 0, N * M) if(S[i / M][i % M] == '#' && !SCC.dfsn[i]) SCC.scc(i);
    deg.assign(SCC.SN, 0);
    rep(u, 0, N * M){
        for(auto v: adj[u]){
            if(SCC.sn[u] ^ SCC.sn[v]) {
                adj2[SCC.sn[u]].pb(SCC.sn[v]);
                deg[SCC.sn[v]]++;
            }
        }
    }
    int ans = 0;
    rep(i, 0, SCC.SN) ans += deg[i] == 0;
    cout << ans;
}
