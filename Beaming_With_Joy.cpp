# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <atcoder/twosat>
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

const pi dd[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int dd1[] = {3, 2, 1, 0};
const int dd2[] = {2, 3, 0, 1};
int N, M, flag;
string S[51];
struct ABC{
    ABC(): ABC(-1, -1, 0){}
    ABC(int x, int y, int d): x(x), y(y), d(d){}
    int x, y, d;
    bool operator != (const ABC& o) const {
        return !(x == o.x && y == o.y && d == o.d);
    }
    inline int conv(){
        return N * M * (d / 2) + M * x + y;
    }
};

inline bool valid(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;
}
inline bool isV(ABC a){
    return !(a.x == -1 && a.y == -1);
}
ABC dfs(int i, int j, int d){
    if(S[i][j] == '/') d = dd1[d];
    if(S[i][j] == '\\') d = dd2[d];
    if(S[i][j] == '-' || S[i][j] == '|') return {i, j, d};
    if(S[i][j] == '#') return ABC();

    int ni = i + dd[d].x, nj = j + dd[d].y;
    if(!valid(ni, nj)) return ABC();

    return dfs(ni, nj, d);
}
void dfs2(int i, int j, int d){
    if(S[i][j] == '/') d = dd1[d];
    if(S[i][j] == '\\') d = dd2[d];
    if((S[i][j] == '-' || S[i][j] == '|') && flag == 0) {
        flag = 1;
        return;
    }
    flag = 0;
    if(S[i][j] == '#') return;

    int ni = i + dd[d].x, nj = j + dd[d].y;
    if(!valid(ni, nj)) return;

    dfs2(ni, nj, d);
}
void solve(){
    cin >> N >> M;
    atcoder::two_sat ts(N * M * 2);
    rep(i, 0, N) cin >> S[i];
    rep(i, 0, N) rep(j, 0, M){
        if(S[i][j] != '.') continue;
        vector<ABC> tmp(4);
        rep(k, 0, 4) {
            tmp[k] = dfs(i, j, k);
        }
        if((isV(tmp[0]) && isV(tmp[1])) || (isV(tmp[2]) && isV(tmp[3]))){
            cout << "IMPOSSIBLE\n";
            return;
        }
        
        if(!isV(tmp[0])) tmp[0] = tmp[1];
        if(!isV(tmp[2])) tmp[2] = tmp[3];
        int ud = isV(tmp[0]);
        int lr = isV(tmp[2]);
        if(!ud && !lr){
            cout << "IMPOSSIBLE\n";
            return;
        }
        if(ud && lr){
            ts.add_clause(tmp[0].conv(), 1, tmp[2].conv(), 1);
        } else {
            if(ud) ts.add_clause(tmp[0].conv(), 1, tmp[0].conv(), 1);
            else ts.add_clause(tmp[2].conv(), 1, tmp[2].conv(), 1);
        }
    }
    rep(i, 0, N) rep(j, 0, M){
        if(S[i][j] != '-' && S[i][j] != '|') continue;
        rep(k, 0, 4){
            flag = 1;
            dfs2(i, j, k);
            if(flag){
                int tmp = ABC(i, j, k).conv();
                ts.add_clause(tmp, 0, tmp, 0);
            }
        }
        ts.add_clause(ABC(i, j, 0).conv(), 1, ABC(i, j, 2).conv(), 1);
    }
    if(!ts.satisfiable()){
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << "POSSIBLE\n";
    auto&& ans = ts.answer();
    // rep(i, 0, N){
    //     rep(j, 0, M){
    //         cout << ans[ABC(i, j, 0).conv()] << ans[ABC(i, j, 2).conv()];
    //     }
    //     cout<<endl;
    // }
    rep(i, 0, N){
        rep(j, 0, M){
            if(S[i][j] != '|' && S[i][j] != '-') cout << S[i][j];
            else{
                if(ans[ABC(i, j, 0).conv()]) cout << "|";
                else cout << "-";
            }
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}

