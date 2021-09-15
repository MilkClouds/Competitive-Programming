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

const int MAX = 3e5 + 111;
int N, M, K, Q;
map<string, pl> ans;
string s;
struct ABC{
    int x, y; char c;
    int nxt[4];
    ABC(): ABC(0,0,0){}
    ABC(int x, int y, char c): x(x), y(y), c(c){rep(i, 0, 4) nxt[i] = -1;}
};
vector<ABC> A;
vector<pi> R[MAX], C[MAX];
pl answer(int r, int c, int dir, string s){
    int u = lower_bound(all(R[r]), pi(c, 0))->y;
    if(ans.find(s) != ans.end()) return ans[s];
    ll dist = 0;
    ans[s].x = ans[s].y = 0;
    while(1) {
        int v = A[u].nxt[dir];
        if(A[v].c == 0) break;
        dist += abs(A[u].x - A[v].x) + abs(A[u].y - A[v].y);
        if(A[v].c == '!') {
            ans[s].x++;
            ans[s].y += dist;
        }
        if(A[v].c == '/') dir = (5 - dir) % 4;
        else if(A[v].c == '\\') dir = 3 - dir;
        u = v;
    }
    return ans[s];
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> K >> Q;
    A.resize(K + (N + M) * 2);
    rep(i, 0, K) cin >> A[i].x >> A[i].y >> A[i].c;
    rep(j, 1, M + 1){
        A[K++] = ABC(N + 1, j, 0);
        A[K++] = ABC(0, j, 0);
    }
    rep(i, 1, N + 1){
        A[K++] = ABC(i, 0, 0);
        A[K++] = ABC(i, M + 1, 0);
    }
    rep(i, 0, K){
        R[A[i].x].eb(A[i].y, i);
        C[A[i].y].eb(A[i].x, i);
    }
    rep(i, 0, N + 2) sort(all(R[i]));
    rep(i, 0, M + 2) sort(all(C[i]));
    rep(i, 0, N + 2){
        rep(j, 0, R[i].size() - 1){
            int u = R[i][j].y, v = R[i][j + 1].y;
            A[u].nxt[1] = v;
            A[v].nxt[3] = u;
        }
    }
    rep(j, 0, M + 2){
        rep(i, 0, C[j].size() - 1){
            int u = C[j][i].y, v = C[j][i + 1].y;
            A[u].nxt[2] = v;
            A[v].nxt[0] = u;
        }
    }
    while(Q--){
        cin >> s;
        pl ans;
        if(s[0] == 'D'){
            ans = answer(N + 1, stoi(s.substr(1)), 0, s);
        } else if(s[0] == 'L'){
            ans = answer(stoi(s.substr(1)), 0, 1, s);
        } else if(s[0] == 'R'){
            ans = answer(stoi(s.substr(1)), M + 1, 3, s);
        } else {
            ans = answer(0, stoi(s.substr(1)), 2, s);
        }
        cout << ans.x << " " << ans.y << "\n";
    }
}
