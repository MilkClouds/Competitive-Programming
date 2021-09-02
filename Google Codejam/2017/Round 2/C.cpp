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

const pi dd[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int dd1[] = {3, 2, 1, 0};
const int dd2[] = {2, 3, 0, 1};
int N, M;
vector<pi> P[51][51];
string S[51];

pair<bool, vector<pi>> go(int i, int j, int d){
    set<pi> covered;
    auto&& rec = [&](int i, int j, int d){
        while(1){
            i += dd[d].x;
            j += dd[d].y;

            if(i < 0 || i >= N) return 1;
            if(j < 0 || j >= M) return 1;
            if(S[i][j] == '#') return 1;
            if(S[i][j] == '|' || S[i][j] == '-') return 0;
            covered.em(i, j);
            if(S[i][j] == '/') d = dd1[d];
            if(S[i][j] == '\\') d = dd2[d];
        }
    };
    if(!rec(i, j, d * 2) || !rec(i, j, d * 2 + 1)) return {0, vector<pi>()};
    return {1, vector<pi>(all(covered))};
}
void solve(){
    cin >> N >> M;
    atcoder::two_sat ts(N * M);
    rep(i, 0, N) rep(j, 0, M) P[i][j].clear();
    rep(i, 0, N) cin >> S[i];
    rep(i, 0, N) rep(j, 0, M){
        if(S[i][j] == '|' || S[i][j] == '-'){
            int flag = 1;
            for(auto&& ret : {go(i, j, 0), go(i, j, 1)}){
                if(ret.x){
                    for(auto it: ret.y){
                        P[it.x][it.y].eb(i * M + j, flag);
                    }
                } else ts.add_clause(i * M + j, flag ^ 1, i * M + j, flag ^ 1);
                flag ^= 1;
            }
        }
    }
    rep(i, 0, N) rep(j, 0, M){
        if(S[i][j] == '.'){
            if(P[i][j].empty()){
                cout << "IMPOSSIBLE\n";
                return;
            }
            if(P[i][j].size() == 1) ts.add_clause(P[i][j][0].x, P[i][j][0].y, P[i][j][0].x, P[i][j][0].y);
            else {
                ts.add_clause(P[i][j][0].x, P[i][j][0].y, P[i][j][1].x, P[i][j][1].y);
            }
        }
    }
    if(!ts.satisfiable()){
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << "POSSIBLE\n";
    auto&& ans = ts.answer();
    rep(i, 0, N){
        rep(j, 0, M){
            if(S[i][j] != '|' && S[i][j] != '-') cout << S[i][j];
            else{
                if(ans[M * i + j]) cout << "-";
                else cout << "|";
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

