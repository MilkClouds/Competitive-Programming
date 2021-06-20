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
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 10002;
int R, C, ans;
vector<int> vis[MAX];
string S[MAX];
bool dfs(int i, int j){
    if(j == C - 1) return 1;
    if(i < 0 || i >= R) return 0;
    if(vis[i][j]) return 0;
    vis[i][j] = 1;
    return dfs(i - 1, j + 1) || dfs(i, j + 1) || dfs(i + 1, j + 1);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> R >> C;
    rep(i, 0, R) vis[i].assign(C, 0);
    rep(i, 0, R) cin >> S[i];
    rep(i, 0, R) rep(j, 0, C) if(S[i][j] == 'x') vis[i][j] = 1;
    rep(i, 0, R) ans += dfs(i, 0);
    cout << ans;
}
