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

const ll MAX = 2e8 + 1;
const ll dx[] = {-3, -3, -1, 1, 3, 3, 1, -1};
const ll dy[] = {-1, 1, 3, 3, 1, -1, -3, -3};
ll K;
vector<ll> v(8), bx(8), by(8);
pl A[8];
ll mydiv(ll x, ll y){
    if((x % y) * 2 >= y) return x / y + 1;
    return x / y;
}
void solve(){
    cin >> K;
    ll xx = 0, yy = 0, ans = MAX * 1234567;
    rep(i, 0, 8) cin >> A[i].x >> A[i].y, A[i].x <<= 1, A[i].y <<= 1;
    rep(i, 0, 8) xx += A[i].x, yy += A[i].y;
    rep(i, 0, 8) A[i].x -= mydiv(xx, 8), A[i].y -= mydiv(yy, 8);

    rep(i, 0, 8) v[i] = i;
    do {
        ll tmp = 0;
        rep(i, 0, 8) bx[i] = A[i].x - K * dx[v[i]];
        rep(i, 0, 8) by[i] = A[i].y - K * dy[v[i]];
        nth_element(bx.begin(), bx.begin() + 3, bx.end());
        nth_element(by.begin(), by.begin() + 3, by.end());
        rep(i, 0, 8) tmp += abs(bx[3] + K * dx[v[i]] - A[i].x) + abs(by[3] + K * dy[v[i]] - A[i].y);
        ans = min(ans, tmp);
    } while(next_permutation(all(v)));

    cout << ans / 2 << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << '\n';
        solve();
    }
}
