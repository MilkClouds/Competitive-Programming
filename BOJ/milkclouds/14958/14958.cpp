#include <bits/stdc++.h>
#include <atcoder/convolution>
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

ll ans = 0;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    reverse(all(T));
    rep(i, 0, M){
        if(T[i] == 'R') T[i] = 'S';
        else if(T[i] == 'S') T[i] = 'P';
        else T[i] = 'R';
    }
    vector<ll> ret(N + M - 1, 0);
    for(auto k: "RPS"){
        vector<ll> A(N, 0), B(M, 0);
        rep(i, 0, N) if(S[i] == k) A[i] = 1;
        rep(i, 0, M) if(T[i] == k) B[i] = 1;
        auto&& tmp = atcoder::convolution_ll(A, B);
        rep(i, 0, N + M - 1) ret[i] += tmp[i];
    }
    rep(i, M - 1, N + M - 1) ans = max(ans, ret[i]);
    cout << ans << endl;
}
