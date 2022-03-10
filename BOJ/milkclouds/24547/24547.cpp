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

const int MAX = 101010;
struct FenwickTree {
public:
    FenwickTree() : FenwickTree(0) {}
    explicit FenwickTree(int N) : N(N), tree(N + 1, 0) {}
    ll query(int i) {
        ll ret = 0; i++;
        for(; i; i ^= i & -i) ret += tree[i];
        return ret;
    }
    ll query(int i, int j){
        return query(j) - query(i - 1);
    }
    void update(int i, ll x) {
        i++;
        for(; i <= N; i += i & -i) tree[i] += x;
    }
private:
    int N;
    vector<ll> tree;
} tree(MAX + 1), tree2(MAX + 1);
ll N, A[MAX], Q, F[MAX], S;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cinA(A, N);
    S = accumulate(A, A + N, 0LL);
    rep(i, 0, N){
        tree.update(A[i], 1), tree2.update(A[i], A[i]);
        ll k = sqrt(A[i]);
        rep(j, 1, k + 1) F[j] += j * (A[i] / j);
    }
    cin >> Q;
    while(Q--){
        ll c;
        cin >> c;
        if(c == 3){
            ll i, v;
            cin >> i >> v; i--;
            S += v - A[i];
            tree.update(A[i], -1);
            tree2.update(A[i], -A[i]);
            ll k = sqrt(A[i]);
            rep(j, 1, k + 1) F[j] -= j * (A[i] / j);
            tree.update(A[i] = v, 1);
            tree2.update(A[i], A[i]);
            k = sqrt(A[i]);
            rep(j, 1, k + 1) F[j] += j * (A[i] / j);
        } else{
            ll X;
            cin >> X;
            if(c == 1){
                ll ans = S - F[X];
                for(ll q = 1; q < min((MAX + X - 1) / X, X); q++) ans -= tree.query(X * q, min((ll)MAX, X * (q + 1) - 1)) * q * X;
                cout << ans << "\n";
            } else {
                ll k = sqrt(X);
                ll ans = X * N;
                rep(j, 1, X / k + 1) ans -= tree.query(j, j) * j * (X / j);
                for(ll q = 1; q < k; q++){
                    // a = (X / (q+1), X / q]
                    ans -= tree2.query(X / (q + 1) + 1, X / q) * q;
                }
                cout << ans << "\n";
            }
        }
    }
}
