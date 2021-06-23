#include <bits/stdc++.h>
using ll = long long;
using namespace std;
struct tree{
    int t[MAX * 4];
    void init(int n){
        fill(t, t + n, INF);
    }
    void update(int pos, int val) {
        t[pos + n] = val;
        for (pos += n; pos > 1; pos >>= 1) {
            t[pos >> 1] = min(t[pos], t[pos ^ 1]);
        }
    }
    int query(int l, int r){
        int ans = INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = min(ans, t[l++]);
            if (r & 1) ans = min(ans, t[--r]);
        }
        return ans;
    }
} SegTree;

class TreeNode {
public:
    int node, l, r;
    ll value, lazy;
    TreeNode* left, right;
    TreeNode(){}
    TreeNode(int node, int l, int r, vector<ll>& v){
        value = v[node];
        left = right = nullptr;
        if(r - l == 1) return;
        int m = l + r >> 1;
        left = new TreeNode(node * 2, l, m, v);
        right = new TreeNode(node * 2 + 1, m, r, v);
    }
    void push(){
        if(lazy == 0) return;
        for(auto child: {left, right}){
            if(child != nullptr) child.lazy += lazy;
        }
        lazy = 0;
    }
    void update(int s, int e, int x){
        push();
        if(s <= l && r <= e){
            lazy += x;
            push();
            return;
        }
        if(e <= l || r <= s) return;
        for(auto child: {left, right}){
            child.update(s, e, x);
        }
    }
    ll query(int s, int e){
        push();
        if(s <= l && r <= e) return value;
        if(e <= l || r <= s) return 0;
        ll ret = 0;
        for(auto child: {left, right}){
            ret += child.query(s, e);
        }
        return ret;
    }
};