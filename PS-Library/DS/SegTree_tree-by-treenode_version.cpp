#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MAX = 1e9;

class TreeNode {
public:
    int node, l, r;
    ll value = 0, lazy = 0;
    TreeNode *left = nullptr, *right = nullptr;
    TreeNode(): TreeNode(0, 0, MAX) {}
    TreeNode(int node, int l, int r): node(node), l(l), r(r) {}
    TreeNode(int node, int l, int r, vector<ll>& v): node(node), l(l), r(r) {
        if(r - l == 1){
            left = right = nullptr;
            value = v[node];
            return;
        }
        int m = l + r >> 1;
        left = new TreeNode(lnode(), l, m, v);
        right = new TreeNode(rnode(), m, r, v);
        value = left -> value + right -> value;
    }
    void push(){
        if(lazy == 0) return;
        value += lazy * (r - l);
        if(r - l > 1) {
            int m = l + r >> 1;
            if(left == nullptr) left = new TreeNode(lnode(), l, m);
            if(right == nullptr) right = new TreeNode(rnode(), m, r);
            for(auto& child: {left, right}){
                child -> lazy += lazy;
            }
        }
        lazy = 0;
    }
    ll update(int s, int e, ll x){
        push();
        if(e <= l || r <= s) return value;
        // cout << l << " " << r << " " << s << " " << e << " " << x << endl;
        if(s <= l && r <= e){
            lazy += x;
            push();
            return value;
        }
        int m = l + r >> 1;
        if(left == nullptr) left = new TreeNode(lnode(), l, m);
        if(right == nullptr) right = new TreeNode(rnode(), m, r);
        return value = left -> update(s, e, x) + right -> update(s, e, x);
    }
    ll query(int s, int e){
        if(e <= l || r <= s) return 0;
        push();
        // cout << l << " " << r << " " << s << " " << e << " " << value << endl;
        if(s <= l && r <= e) return value;
        ll ret = 0;
        for(auto& child: {left, right}){
            if(child != nullptr) ret += child -> query(s, e);
        }
        return ret;
    }
private:
    int lnode(){return node * 2 + 1;}
    int rnode(){return node * 2 + 2;}
} root;