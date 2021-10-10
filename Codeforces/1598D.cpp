#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 2e5;
int TC, N;
pi A[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        ll ans = 0;
        map<int, ll> X, Y;
        cin >> N;
        rep(i, 0, N) {
            cin >> A[i].x >> A[i].y;
            X[A[i].x]++;
            Y[A[i].y]++;
        }
        ans = (ll) N * (N - 1) * (N - 2) / 6;
        rep(i, 0, N){
            ans -= (X[A[i].x] - 1) * (Y[A[i].y] - 1);
        }
        cout << ans << '\n';
    }
}
