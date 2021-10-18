#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const ll INF = 1e18;

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
    void update(int s, int e, ll x){
        update(0, 0, N, s, e, x);
    }
    int N;
    vector<ll> tree, lazy;
    ll init(int node, int l, int r, vector<ll>& v){
        if(r - l == 1) {
            return tree[node] = v[l];
        }
        int m = l + r >> 1;
        return tree[node] = min(init(node * 2 + 1, l, m, v), init(node * 2 + 2, m, r, v));
    }
    void push(int node, int l, int r){
        if(lazy[node] == 0) return;
        tree[node] += lazy[node];
        if(r - l > 1) {
            for(auto v: {node * 2 + 1, node * 2 + 2}){
                lazy[v] += lazy[node];
            }
        }
        lazy[node] = 0;
    }
    ll query(int node, int l, int r, int s, int e){
        push(node, l, r);
        if(r <= s || e <= l) return INF;
        if(s <= l && r <= e) return tree[node];
        int m = l + r >> 1;
        return min(query(node * 2 + 1, l, m, s, e), query(node * 2 + 2, m, r, s, e));
    }
    ll query(int node, int l, int r, int k){
        push(node, l, r);
        if(k < l || r <= k) return INF;
        if(r - l == 1) return tree[node];
        int m = l + r >> 1;
        return min(query(node * 2 + 1, l, m, k), query(node * 2 + 2, m, r, k));
    }
    ll update(int node, int l, int r, int s, int e, ll x){
        push(node, l, r);
        if(r <= s || e <= l) return tree[node];
        if(s <= l && r <= e){
            lazy[node] += x;
            push(node, l, r);
            return tree[node];
        }
        int m = l + r >> 1;
        update(node * 2 + 1, l, m, s, e, x);
        update(node * 2 + 2, m, r, s, e, x);
        return tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
};
const int MAX = 2e5 + 1;
int N, Q;
vector<ll> A;
string S;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> Q >> S;
    A.assign(N, 0);
    rep(i, 0, N){
        A[i] = (i ? A[i - 1] : 0) + (S[i] == '(' ? 1 : -1);
    }
    SegTree tree(N + 1, A);
    while(Q--){
        int c, l, r;
        cin >> c >> l >> r; l--; r--;
        if(c == 1){
            if(S[l] == S[r]) continue;
            int tmp = (S[l] == '(' ? 1 : -1);
            swap(S[l], S[r]);
            tree.update(l, r, -2 * tmp);
        } else {
            ll tmp =  l ? tree.query(l - 1) : 0;
            // cout << tree.query(l, r + 1) - tmp << " " << (tree.query(r) - tmp) << endl;
            if(tree.query(l, r + 1) - tmp >= 0 && tree.query(r) - tmp == 0) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
