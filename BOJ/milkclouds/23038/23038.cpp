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

const int MAX = 300 * 3;
const array<pi, 4> actions = {pi(1, 0), pi(-1, 0), pi(0, 1), pi(0, -1)};
int N, M;
string S[MAX];
inline bool valid(int i, int j){
    return 0 <= i && i < N * 3 && 0 <= j && j < M * 3;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, N * 3) cin >> S[i];
    rep(i, 0, N) rep(j, 0, M){
        for(auto [dx, dy]: actions){
            auto [nx, ny] = pi(i * 3 + 1 + dx, j * 3 + 1 + dy);
            if(S[nx][ny] == '.') continue;
            auto [nx2, ny2] = pi(nx + dx, ny + dy);
            if(valid(nx2, ny2)) S[nx2][ny2] = '#';
        }
        S[i * 3 + 1][j * 3 + 1] = '#';
    }
    rep(i, 0, N * 3) cout << S[i] << "\n";
}
