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


int TC, N, K, M, mask;
string T;
struct ABC{
    int x,y,z;
    ABC(): ABC(0,0,0){}
    ABC(int x, int y, int z): x(x), y(y), z(z){}
    bool operator < (const ABC& o) const {
        return x < o.x;
    }
};
multiset<ABC> S;
inline int op_func(int a, int b){return max(a, b);}
struct SegTree{
public:
    SegTree() : SegTree(0) {}
    explicit SegTree(int N): N(N), tree(N * 4, 0) {}
    explicit SegTree(int N, vector<int>& v): N(N), tree(N * 4, 0) {init(0, 0, N, v);}
    // range query
    int query(int s, int e){
        return query(0, 0, N, s, e);
    }
    void update(int k, int x){
        update(0, 0, N, k, x);
    }
    void traverse(){
        traverse(0, 0, N);
    }
private:
    int N;
    vector<int> tree;
    int init(int node, int l, int r, vector<int>& v){
        if(r - l == 1) {
            return tree[node] = v[l];
        }
        int m = l + r >> 1;
        return tree[node] = op_func(init(node * 2 + 1, l, m, v), init(node * 2 + 2, m, r, v));
    }
    int query(int node, int l, int r, int s, int e){
        if(r <= s || e <= l) return 0;
        if(s <= l && r <= e) return tree[node];
        int m = l + r >> 1;
        return op_func(query(node * 2 + 1, l, m, s, e), query(node * 2 + 2, m, r, s, e));
    }
    int update(int node, int l, int r, int k, int x){
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
int solve(){
    int ans = 0;
    cin >> N >> K >> M >> T;
    SegTree tree(N + 1);
    mask = 1;
    rep(i, 1, K) mask *= 10;
    S.clear();
    rep(i, 0, N - K + 1){
        int tt = 0;
        rep(j, 0, K){
            tt = tt * 10 + T[i + j] - '0';
        }
        S.insert({tt, 0, 1});
        rep(k, 0, K){
            int tmp = 0;
            if(T[i + k] == '1') continue;
            rep(j, 0, K){
                if(j == k) tmp = tmp * 10 + 1;
                else tmp = tmp * 10 + T[i + j] - '0';
            }
            S.insert({tt, i + k + 1, -1});
            S.insert({tmp, i + k + 1, 1});
        }
    }
    deque<ABC> deq;
    for(auto p = S.begin(); p != S.end();){
        auto i = *p;
        tree.update(i.y, i.z);
        deq.push_back(i);
        p++;
        // remove
        while(deq.size() > 1 && deq.front().x < deq.back().x - M){
            tree.update(deq.front().y, -deq.front().z);
            deq.pop_front();
        }
        // insert
        while(p != S.end() && (deq.empty() || deq.front().x >= (p -> x) - M)){
            auto i = *p;
            tree.update(i.y, i.z);
            deq.push_back(i);
            p++;
        }
        //if(mask == 1 || (!deq.empty() && deq.front().x >= mask)) ans = max(ans, max(tree.query(0, 1), tree.query(1, N + 1) + tree.query(0, 1)));
        ans = max(ans, max(tree.query(0, 1), tree.query(1, N + 1) + tree.query(0, 1)));
        //cout << tree.query(0, 1) << " " << tree.query(1, N + 1) << " " << ans << endl;
    }
    return ans;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << "\n";
        cout << solve() << "\n";
    }
}