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
struct ABC{
    int l, r, x;
} A[MAX];

class SegTree{
public:
    SegTree() : SegTree(0) {}
    SegTree(int N): SegTree(N, vector<ll>(N, 0)) {}
    SegTree(int N, vector<ll> v): N(N), tree(N * 4), lazy(N * 4){
        init(0, 0, N, v);
    }
    // range query
    ll query(int s, int e){
        return query(0, 0, N, s, e);
    }
    // query
    ll query(int k){
        return query(0, 0, N, k);
    }
    void update(int s, int e, int x){
        update(0, 0, N, s, e, x);
    }
private:
    int N;
    vector<ll> tree, lazy;
    ll init(int node, int l, int r, vector<ll>& v){
        if(r - l == 1) {
            return tree[node] = v[l];
        }
        int m = l + r >> 1;
        return tree[node] = init(node * 2 + 1, l, m, v) + init(node * 2 + 2, m, r, v);
    }
    void push(int node, int l, int r){
        if(lazy[node] == 0) return;
        tree[node] = lazy[node] * (r - l);
        if(r - l > 1) {
            for(auto v: {node * 2 + 1, node * 2 + 2}){
                lazy[v] = lazy[node];
            }
        }
        lazy[node] = 0;
    }
    ll query(int node, int l, int r, int s, int e){
        push(node, l, r);
        if(r <= s || e <= l) return 0;
        if(s <= l && r <= e) return tree[node];
        int m = l + r >> 1;
        return query(node * 2 + 1, l, m, s, e) + query(node * 2 + 2, m, r, s, e);
    }
    ll query(int node, int l, int r, int k){
        push(node, l, r);
        if(k < l || r <= k) return 0;
        if(r - l == 1) return tree[node];
        int m = l + r >> 1;
        return query(node * 2 + 1, l, m, k) + query(node * 2 + 2, m, r, k);
    }
    ll update(int node, int l, int r, int s, int e, ll x){
        push(node, l, r);
        if(r <= s || e <= l) return tree[node];
        if(s <= l && r <= e){
            lazy[node] = x;
            push(node, l, r);
            return tree[node];
        }
        int m = l + r >> 1;
        update(node * 2 + 1, l, m, s, e, x);
        update(node * 2 + 2, m, r, s, e, x);
        return tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
} tree(MAX);

int N, M;
vector<int> E[MAX];
ll ans[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 1, M + 1){
        cin >> A[i].l >> A[i].r >> A[i].x;
        E[A[i].r].eb(i);
    }
    rep(j, 1, N + 1){
        if(E[j].empty()) continue;
        for(auto i: E[j]){
            A[i].x -= tree.query(A[i].l, A[i].r + 1);
            if(A[i].x <= 0) continue;
            int l = 0, r = A[i].r + 1 - A[i].x;
            while(l < r) {
                int m = l + r + 1 >> 1;
                if(A[i].r + 1 - m - tree.query(m, A[i].r + 1) >= A[i].x) l = m;
                else r = m - 1;
            }
            tree.update(l, A[i].r + 1, 1);
        }
    }
    rep(i, 1, N + 1) cout << tree.query(i) << " \n"[i == N];
}
