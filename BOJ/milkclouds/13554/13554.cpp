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
using ti = tuple<int, int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e5;
int N, A[MAX], B[MAX], Q, i, j, k, sq, l = 1, r;
ti query[MAX];
ll ans[MAX];
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
} treeA(MAX + 1), treeB(MAX + 1);
void update(int i, int j){
    treeA.update(A[i], j);
    treeB.update(B[i], j);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cinA(A, N); cinA(B, N);
    cin >> Q; sq = sqrt(Q);
    rep(t, 0, Q){
        cin >> i >> j >> k; i--; j--;
        query[t] = {i, j, k, t};
    }
    sort(query, query + Q, [](ti& a, ti& b){
        if(get<0>(a) / sq == get<0>(b) / sq) return get<1>(a) < get<1>(b);
        return get<0>(a) < get<0>(b);
    });
    rep(_, 0, Q){
        auto [nl, nr, k, t] = query[_];
        while(l < nl) update(l++, -1);
        while(nl < l) update(--l, 1);
        while(r < nr) update(++r, 1);
        while(nr < r) update(r--, -1);
        int sk = sqrt(k);
        rep(i, 1, sk + 1){
            ans[t] += treeA.query(i, i) * treeB.query(sk + 1, k / i);
            ans[t] += treeB.query(i, i) * treeA.query(k / i);
        }
    }
    rep(i, 0, Q) cout << ans[i] << "\n";
}
