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
ll N, A[MAX], M, x, y, S;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    sort(A, A + N);
    rep(i, 0, N) S += A[i];
    cin >> M;
    rep(i, 0, M){
        cin >> x >> y;
        ll ans = numeric_limits<ll>::max();
        auto pos = upper_bound(A, A + N, x);
        auto pos2 = pos - 1;
        if(pos != A) ans = min(ans, x - *pos2 + max(0LL, y - (S - *pos2)));
        if(pos != A + N) ans = min(ans, 0 + max(0LL, y - (S - *pos)));
        cout << ans << "\n";
    }
}
