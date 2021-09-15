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

const int MAX = 2e5 + 10;
int N, M, K[MAX];
vector<int> A[MAX];
struct ABC{
    ABC(): ABC(0, 0, 0){}
    ABC(int color, int i, int j): color(color), i(i), j(j) {}
    int color, i, j;
    bool operator < (const ABC& o) const {
        return color == o.color ? i < o.i : color < o.color;
    }
};
set<ABC> S;
set<ABC>::iterator pos;
void insert(int color, int i, int j){
    if(!S.empty() && (pos = S.lower_bound({color, 0, 0})) -> color == color){
        S.erase(pos);
        if(pos->j) insert(A[pos -> i][pos -> j - 1], pos -> i, pos -> j - 1);
        if(j) insert(A[i][j - 1], i, j - 1);
    } else {
        S.emplace(color, i, j);
        return;
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, M) {
        cin >> K[i];
        A[i].resize(K[i], 0);
        rep(j, 0, K[i]) cin >> A[i][j];
        insert(A[i][K[i] - 1], i, K[i] - 1);
    }
    cout << (S.empty() ? "Yes" : "No") << endl;
}
