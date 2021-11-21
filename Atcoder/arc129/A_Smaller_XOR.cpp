#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
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

ll solve(ll N, ll L, ll R){
    if(L >= R) return 0;
    rep2(i, 0, 61){
        if(N & (1LL << i)){
            return max(0LL, min(1LL << (i + 1), R) - max(1LL << i, L)) + solve(N ^ (1LL << i), L, min(R, 1LL << i));
        }
    }
    return 0;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    ll N, L, R;
    cin >> N >> L >> R; R++;
    cout << solve(N, L, R);
}
