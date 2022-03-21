#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;


int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    ll L, R, ans = 0;
    cin >> L >> R;
    rep(i, L, min(R, L + 1000) + 1) rep(j, max(i + 1, max(L, R - 1000)), R + 1) if(gcd(i, j) == 1) ans = max(ans, j - i);
    cout << ans << endl;
}
