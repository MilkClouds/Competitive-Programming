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
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 40;
ll N, M, T, A[MAX], B[MAX], ans;
set<ll> S1, S2;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> T;
    rep(i, 0, N) cin >> A[i];
    if(N == 1){
        cout << (A[0] <= T ? A[0] : 0) << endl;
        return 0;
    }
    M = N / 2;
    rep(i, 0, M) B[i] = A[i + (N + 1) / 2];
    N = (N + 1) / 2;
    rep(i, 0, 1 << N){
        ll tmp = 0;
        rep(j, 0, 20) if(i & (1 << j)) tmp += A[j];
        S1.insert(tmp);
    }
    rep(i, 0, 1 << M){
        ll tmp = 0;
        rep(j, 0, 20) if(i & (1 << j)) tmp += B[j];
        S2.insert(tmp);
    }
    for(auto i: S1){
        auto pos = S2.upper_bound(T - i);
        if(pos == S2.begin()) continue;
        pos--;
        ans = max(ans, (*pos) + i);
    }
    cout << ans;
}
