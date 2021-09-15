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
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e5 + 10;
int N, M, l, r;
vector<ll> A, B;
ll c;

ll gcd(ll a, ll b){
    a = abs(a); b = abs(b);
    if(a < b) swap(a, b);
    if(b == 0) return a;
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

inline ll op_func(ll a, ll b) {return gcd(a, b);}

struct SegTree{
public:
    SegTree() : SegTree(0) {}
    explicit SegTree(int N): N(N), tree(N * 4, 0) {}
    explicit SegTree(int N, vector<ll>& v): N(N), tree(N * 4, 0) {init(0, 0, N, v);}
    // range query
    ll query(int s, int e){
        return query(0, 0, N, s, e);
    }
    // query
    ll query(int k){
        return query(0, 0, N, k);
    }
    void update(int k, int x){
        update(0, 0, N, k, x);
    }
    void traverse(){
        traverse(0, 0, N);
    }
private:
    int N;
    vector<ll> tree;
    ll init(int node, int l, int r, vector<ll>& v){
        if(r - l == 1) {
            return tree[node] = v[l];
        }
        int m = l + r >> 1;
        return tree[node] = op_func(init(node * 2 + 1, l, m, v), init(node * 2 + 2, m, r, v));
    }
    ll query(int node, int l, int r, int s, int e){
        if(r <= s || e <= l) return 0;
        if(s <= l && r <= e) return tree[node];
        int m = l + r >> 1;
        return op_func(query(node * 2 + 1, l, m, s, e), query(node * 2 + 2, m, r, s, e));
    }
    ll query(int node, int l, int r, int k){
        if(k < l || r <= k) return 0;
        if(r - l == 1) return tree[node];
        int m = l + r >> 1;
        return op_func(query(node * 2 + 1, l, m, k), query(node * 2 + 2, m, r, k));
    }
    ll update(int node, int l, int r, int k, ll x){
        if(r <= k || k < l) return tree[node];
        if(r - l == 1){
            tree[node] += x;
            return tree[node];
        }
        int m = l + r >> 1;
        return tree[node] = op_func(update(node * 2 + 1, l, m, k, x), update(node * 2 + 2, m, r, k, x));
    }
    void traverse(int node, int l, int r){
        cout << node << " " << l << " " << r << " " << tree[node] << endl;
        if(r - l == 1){
            return;
        }
        int m = l + r >> 1;
        traverse(node * 2 + 1, l, m);
        traverse(node * 2 + 2, m, r);
    }
};

struct FenwickTree {
public:
    FenwickTree() : FenwickTree(0) {}
    explicit FenwickTree(int N) : N(N), tree(N + 1, 0) {}
    ll query(int i) {
        ll ret = 0; i++;
        for(; i; i ^= i & -i) ret += tree[i];
        return ret;
    }
    void update(int i, ll x) {
        i++;
        for(; i <= N; i += i & -i) tree[i] += x;
    }
private:
    int N;
    vector<ll> tree;
};

FenwickTree tree(MAX);
ll get(int k){
    return A[k] + tree.query(k);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    A.assign(N, 0);
    B.assign(N - 1, 0);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N - 1) B[i] = A[i + 1] - A[i];
    SegTree segtree(N - 1, B);
    cin >> M;
    while(M--) {
        cin >> c >> l >> r; l--; r--;
        if(c == 0) {
            if(l == r) cout << get(l) << "\n";
            else if(r - l == 1) cout << gcd(get(l), get(r)) << "\n";
            else cout << gcd(get(l), segtree.query(l, r)) << "\n";
        }
        else{
            tree.update(l, c);
            if(r < N - 1) tree.update(r + 1, -c);
            if(l > 0) segtree.update(l - 1, c);
            if(r < N - 1) segtree.update(r, -c);
        }
    }
}
