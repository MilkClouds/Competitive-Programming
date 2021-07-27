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

const int MAX = 2e5;
int TC, N;
vector<ll> A;
int gcd(int a, int b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    if(a % b == 0) return b;
    return gcd(b, a % b);
}
inline ll op_func(ll a, ll b){return gcd(a, b);}

struct SegTree{
public:
    SegTree() : SegTree(0) {}
    explicit SegTree(int N): N(N), tree(N * 4, 0) {}
    explicit SegTree(int N, vector<ll>& v): N(N), tree(N * 4, 0) {init(0, 0, N, v);}
    // range query
    ll query(int s, int e){
        return query(0, 0, N, s, e);
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
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N;
        A.resize(N * 2);
        rep(i, 0, N) cin >> A[i];
        rep(i, 0, N) A[i + N] = A[i];
        int g = gcd(A[0], A[1]);
        rep(i, 2, N){
            g = gcd(g, A[i]);
        }
        SegTree tree(N * 2, A);
        int ans = 0;
        rep(i, 0, N){
            int l = i, r = i + N;
            while(l < r){
                int m = l + r >> 1;
                if(tree.query(i, m + 1) == g) r = m;
                else l = m + 1;
            }
            ans = max(ans, l - i);
        }
        cout << ans << "\n";
    }
}
