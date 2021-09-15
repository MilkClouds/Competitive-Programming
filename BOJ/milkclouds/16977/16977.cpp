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

const int MAX = 1e5 + 1, INF = 1e9;
int N, H[MAX], Q, HH[MAX];
struct Query{
    int l, r, w;
    int s, e;
} query[MAX];
map<int, vector<int>> height;
struct node{
    int l, r, m, s;
    node(): node(0, 0, 0, 1){}
    node(int l, int r, int m, int s): l(l), r(r), m(m), s(s){}
    void set(int i){
        l = r = m = i;
    }
};
node merge(node l, node r){
    return node(max(l.l, r.l + (l.s == l.m ? l.m : -INF)), 
        max(r.r, l.r + (r.s == r.m ? r.m : -INF)),
        max({l.r + r.l, l.m, r.m}),
        l.s + r.s
    );
}
struct SegTree{
    int N;
    vector<node> tree;
    SegTree(int N): tree(N * 4), N(N) {init(1, 0, N);}
    int init(int node, int l, int r){
        if(r - l == 1) return 1;
        int m = l + r >> 1;
        return tree[node].s = init(node * 2, l, m) + init(node * 2 + 1, m, r);
    }
    void update(int i){
        update(1, 0, N, i);
    }
    void update(int node, int l, int r, int i){
        if(r <= i || i < l) return;
        if(r - l == 1){
            tree[node].set(1);
            return;
        }
        int m = l + r >> 1;
        update(node * 2, l, m, i);
        update(node * 2 + 1, m, r, i);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
    int query(int s, int e){
        return query(1, 0, N, s, e).m;
    }
    node query(int node, int l, int r, int s, int e){
        if(s <= l && r <= e){
            return tree[node];
        }
        if(r <= s || e <= l){
            return {0, 0, 0, r - l};
        }
        int m = l + r >> 1;
        return merge(query(node * 2, l, m, s, e), query(node * 2 + 1, m, r, s, e));
    }
};
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> H[i];
    rep(i, 0, N){
        if(height.find(H[i]) == height.end()){
            height[H[i]] = vector<int>{i};
        } else height[H[i]].eb(i);
    }
    int cnt = 0;
    for(auto& i: height) HH[cnt++] = i.x;
    cin >> Q;
    rep(i, 0, Q){
        cin >> query[i].l >> query[i].r >> query[i].w;
        query[i].l--;
        query[i].r--;
        query[i].s = 0;
        query[i].e = height.size();
    }
    while(1){
        vector<vector<int>> events(height.size());
        SegTree tree(N);
        bool flag = 0;
        rep(i, 0, Q){
            if(query[i].s + 1 == query[i].e) continue;
            int m = query[i].s + query[i].e >> 1;
            events[m].eb(i);
            flag = 1;
        }
        if(!flag) break;
        int cnt = height.size();
        for(auto pos = height.rbegin(); pos != height.rend(); pos++){
            for(auto i: pos->y) tree.update(i);
            for(auto i: events[--cnt]){
                if(tree.query(query[i].l, query[i].r + 1) >= query[i].w) query[i].s = cnt;
                else query[i].e = cnt;
            }
        }
    }
    rep(i, 0, Q) cout << HH[query[i].s] << "\n";
}
