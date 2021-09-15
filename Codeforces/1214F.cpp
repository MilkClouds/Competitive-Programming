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
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;

const int MAX = 2e5;
ll M, N, C[MAX];
struct pl{
    ll x,y;
    pl(): pl(0, 0){}
    pl(ll x, ll y): x(x), y(y){}
    bool operator < (const pl& o) const {
        return x < o.x;
    }
} A[MAX], B[MAX];
ll Q[MAX + 1], T = 1e18, t;
void update(ll a, ll b, ll c, ll i, bool flag){
    if(!flag){
        if(a >= b) return;
        b--;
        a -= i; b -= i;
    } else {
        if(a >= b) return;
        b--;
        swap(a, b);
        a = i - a; b = i - b;
    }
    c /= 2;
    a %= N; if(a < 0) a += N;
    b %= N; if(b < 0) b += N;
    if(a <= b){
        Q[a] += c;
        Q[b + 1] -= c;
    } else {
        Q[0] += c;
        Q[b + 1] -= c;
        Q[a] += c;
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> M >> N;
    rep(i, 0, N) cin >> A[i].x;
    rep(i, 0, N) cin >> B[i].x;
    rep(i, 0, N) A[i].y = B[i].y = i;
    rep(i, 0, N){
        A[i].x *= 2;
        B[i].x *= 2;
    }
    M *= 2;
    sort(A, A + N); sort(B, B + N);
    rep(i, 0, N){
        int a = lower_bound(B, B + N, pl(A[i].x - M / 2, -1)) - B;
        int b = lower_bound(B, B + N, pl(A[i].x, -1)) - B;
        int c = lower_bound(B, B + N, pl(A[i].x + M / 2, -1)) - B;
        update(0, a, M - A[i].x, i, 0);
        update(a, b, A[i].x, i, 0);
        update(b, c, -A[i].x, i, 0);
        update(c, N, M + A[i].x, i, 0);
    }
    rep(i, 0, N){
        int a = upper_bound(A, A + N, pl(B[i].x - M / 2, -1)) - A;
        int b = upper_bound(A, A + N, pl(B[i].x, -1)) - A;
        int c = upper_bound(A, A + N, pl(B[i].x + M / 2, -1)) - A;
        update(0, a, -B[i].x, i, 1);
        update(a, b, B[i].x, i, 1);
        update(b, c, -B[i].x, i, 1);
        update(c, N, B[i].x, i, 1);
    }
    rep(i, 1, N) Q[i] += Q[i - 1];
    rep(i, 0, N){
        if(T > Q[i]){
            T = Q[i];
            t = i;
        }
    }
    rep(i, 0, N){
        C[A[i].y] = B[(i + t) % N].y;
    }
    cout << T << endl;
    rep(i, 0, N) cout << C[i] + 1 << " ";
}
