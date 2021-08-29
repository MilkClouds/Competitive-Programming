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

const int MOD1 = 1e9 + 7;
int N, M;
string S[1001];
ll gcd(ll x, ll y){
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
int solve(bool rev = 0){
    set<int> SSS;
    rep(i, 0, N) {
        int cnt = 1;
        set<int> SS;
        rep(j, 1, M){
            if(rev ? S[j][i] == S[j - 1][i] : S[i][j] == S[i][j - 1]){
                cnt++;
            } else {
                SS.insert(cnt);
                cnt = 1;
            }
        }
        SS.insert(cnt);
        int tmp = *SS.begin();
        for(auto i: SS) tmp = gcd(tmp, i);
        SSS.insert(tmp);
    }
    int tmp = *SSS.begin();
    for(auto i: SSS) tmp = gcd(tmp, i);
    return tmp;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, N) cin >> S[i];
    int c = solve();
    swap(N, M);
    int r = solve(1);
    swap(N, M);
    cout << N / r << " " << M / c << "\n";
    rep(i, 0, N / r) {rep(j, 0, M / c) cout << S[i * r][j * c]; cout << "\n";}
}
