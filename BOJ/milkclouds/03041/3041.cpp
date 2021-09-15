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

map<char, pi> M, N;
string S[4] = {"ABCD", "EFGH", "IJKL", "MNO."}, E[4];
int ans;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    rep(i, 0, 4) cin >> E[i];
    rep(i, 0, 4) rep(j, 0, 4){
        M[S[i][j]] = {i, j};
        N[E[i][j]] = {i, j};
    }
    for(auto p: M){
        if(p.x == '.') continue;
        ans += abs(N[p.x].x - p.y.x) + abs(N[p.x].y - p.y.y);
    }
    cout << ans << endl;
}
