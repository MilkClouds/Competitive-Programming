#include <bits/stdc++.h>
using ll = long long;
using namespace std;



inline ll op_func(ll a, ll b){return a + b;}

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
    void update(int k, ll x){
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
        tree[node] += lazy[node] * (r - l);
        if(r - l > 1) {
            for(auto v: {node * 2 + 1, node * 2 + 2}){
                lazy[v] += lazy[node];
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
            lazy[node] += x;
            push(node, l, r);
            return tree[node];
        }
        int m = l + r >> 1;
        update(node * 2 + 1, l, m, s, e, x);
        update(node * 2 + 2, m, r, s, e, x);
        return tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
};


/*
void update(int node, int s, int e, int l, int r, int v){
  push(node, s, e);
  if(r < s || e < l) return;
  if(l <= s && e <= r){
    tag(node);
    push(node, s, e);
    return;
  }
  int m = s + e >> 1;
  update(node*2, s, m, l, r, v);
  update(node*2+1, m+1, e, l, r, v);
  tree[node] = f(tree[node*2], tree[node*2+1]);
}
void update(int node, int s, int e, int l, int r, int v){
  push(node, s, e);
  if(break_condition()) return;
  if(tag_condition()){
    tag(node);
    push(node, s, e);
    return;
  }
  int m = s + e >> 1;
  update(node*2, s, m, l, r, v);
  update(node*2+1, m+1, e, l, r, v);
  tree[node] = f(tree[node*2], tree[node*2+1]);
}
*/