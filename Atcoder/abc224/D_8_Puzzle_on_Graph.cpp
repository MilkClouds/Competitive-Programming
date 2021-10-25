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
using ab = array<int, 9>;
int M, ii;
ab S, END;
queue<ab> Q;
set<ab> SS;
bool adj[11][11];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> M;
    rep(i, 0, M){
        int u, v;
        cin >> u >> v; u--; v--;
        adj[u][v] = adj[v][u] = 1;
    }
    rep(i, 0, 8){
        int t;
        cin >> t; t--;
        S[t] = i + 1;
    }
    rep(i, 0, 8) END[i] = i + 1;
    Q.push(S);
    while(1){
        bool flag = 0;
        int cnt = Q.size();
        if(cnt == 0) break;
        rep(_, 0, cnt){
            ab u = Q.front(); Q.pop();
            if(u == END) {flag = 1; break;}
            int blank;
            rep(i, 0, 9) if(u[i] == 0) blank = i;
            rep(i, 0, 9){
                if(i != blank){
                    if(adj[blank][i]){
                        swap(u[blank], u[i]);
                        if(SS.count(u) == 0){
                            Q.push(u);
                            SS.emplace(u);
                        }
                        swap(u[blank], u[i]);
                    }
                }
            }
        }
        if(flag){
            cout << ii << endl;
            return 0;
        }
        ii++;
    }
    cout << "-1\n";
}
