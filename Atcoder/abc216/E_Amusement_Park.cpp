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

const int MAX = 1e5 + 10;
ll N, K, A[MAX], j, S, ans, divv, mod;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    rep(i, 1, N + 1) cin >> A[i];
    sort(A, A + N + 1);
    S = A[N];
    rep2(i, 1, N + 1){
        if(K <= S - (N - i + 1) * (A[i - 1] - 1)){
            K -= S - (N - i + 1) * (A[i] - 1);
            divv = K / (N - i + 1), mod = K % (N - i + 1);
            j = i;
            break;
        }
        S += A[i - 1];
    }
    if(j == 0){
        rep2(i, 1, N + 1){
            ans += A[i] * (A[i] + 1) / 2;
        }
        cout << ans << endl;
        return 0;
    }
    rep2(i, j, N + 1){
        ll tmp = A[j] - divv;
        ans += (A[i] + 1) * A[i] / 2 - tmp * (tmp - 1) / 2;
    }
    ans += (A[j] - divv - 1) * mod;
    cout << ans << endl;
}
