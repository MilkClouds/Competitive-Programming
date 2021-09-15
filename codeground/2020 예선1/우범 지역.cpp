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

const int MAX = 2e5 + 10;
int TC, N;
struct ABC{
    int x, y;
    double p;
    ABC(): ABC(0, 0){}
    ABC(int x, int y): x(x), y(y) {}
    bool operator < (const ABC& o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
} A[MAX], S;
ll ccw(const ABC& A, const ABC& B, const ABC& C){
    return 1LL * A.x * B.y + 1LL * B.x * C.y + 1LL * C.x * A.y - 1LL * B.x * A.y - 1LL * C.x * B.y - 1LL * A.x * C.y;
}
ll ccw(const ABC& A, const ABC& B){
    return 1LL * A.x * B.y - 1LL * A.y * B.x;
}
struct tree{
    double t[MAX * 4];
    int n;
    void init(int n){
        fill(t, t + n, 1);
        tree::n = n;
    }
    double op_func(double a, double b){
        return a * b;
    }
    void update(int pos, double val) {
        t[pos + n] = val;
        for (pos += n; pos > 1; pos >>= 1) {
            t[pos >> 1] = op_func(t[pos], t[pos ^ 1]);
        }
    }
    double query(int l, int r){
        double ans = 1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = op_func(ans, t[l++]);
            if (r & 1) ans = op_func(ans, t[--r]);
        }
        return ans;
    }
} SegTree;
double solve(){
    double ans = 1;
    cin >> N;
    rep(i, 0, N) cin >> A[i].x;
    rep(i, 0, N) cin >> A[i].y;
    rep(i, 0, N) cin >> A[i].p;
    cin >> S.x >> S.y;
    rep(i, 0, N) {
        A[i].x -= S.x;
        A[i].y -= S.y;
    }
    sort(A, A + N, [&](const ABC& a, const ABC& b){
        if((ABC(0, 0) < a) ^ (ABC(0, 0) < b)) return b < a;
        return ccw(a, b) > 0;
        assert(0);
        return true;
    });
    if(ccw(A[0], A[N - 1]) > 0) return 0;
    rep(i, 0, N) A[i + N] = A[i];
    rep(i, 0, N) ans *= 1 - A[i].p;
    SegTree.init(N * 2);
    rep(i, 0, N * 2) SegTree.update(i, 1 - A[i].p);
    int j = 1;
    rep(i, 0, N){
        while(j < 2 * N && ccw({0, 0}, A[i], A[j]) > 0){
            j++;
        }
        ans += A[i].p * SegTree.query(i + 1, j);
    }
    return 1 - ans;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    cout << fixed << setprecision(15); 
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << "\n";
        cout << solve() << "\n";
    }
}
