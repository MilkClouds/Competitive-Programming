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

const int MAX = 2e5;
int TC, N, K, A[MAX], B[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    rep(tc, 1, TC + 1){
        cin >> N >> K;
        int ans = 0;
        rep(i, 0, N) cin >> A[i];
        rep(i, 0, N) cin >> B[i];
        sort(A, A + N);
        sort(B, B + N);
        rep(i, 0, K) ans = max(ans, A[i] + B[K - i - 1]);
        cout << "Case #" << tc << "\n";
        cout << ans << "\n";
    }
}
