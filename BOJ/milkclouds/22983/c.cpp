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

const int MAX = 3005;
int N, M, L[MAX][MAX], U[MAX][MAX], T[MAX][MAX];
ll ans;
string S[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, N) cin >> S[i];
    rep(i, 0, N) rep(j, 1, M){
        if(S[i][j] ^ S[i][j - 1]) L[i][j] = L[i][j - 1];
        else L[i][j] = j;
    }
    rep(j, 0, M) rep(i, 1, N){
        if(S[i][j] ^ S[i - 1][j]) U[i][j] = U[i - 1][j];
        else U[i][j] = i;
    }
    rep(i, 0, N) rep(j, 0, M){
        T[i][j] = 1;
        if(i && j){
            if(S[i][j] == S[i - 1][j - 1]) T[i][j] += min({i - U[i][j], j - L[i][j], T[i - 1][j - 1]});
        }
        ans += T[i][j];
    }
    cout << ans << endl;
}
