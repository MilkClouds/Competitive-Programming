#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class TreeNode {
public:
    int node, l, r;
    ll value, lazy;
    TreeNode *left, *right;
    TreeNode(){}
    TreeNode(int node, int l, int r, vector<ll>& v): node(node), l(l), r(r) {
        if(r - l == 1){
            left = right = nullptr;
            value = v[node];
            return;
        }
        int m = l + r >> 1;
        left = new TreeNode(node * 2, l, m, v);
        right = new TreeNode(node * 2 + 1, m, r, v);
        value = left -> value + right -> value;
    }
    void push(){
        if(lazy == 0) return;
        for(auto child: {left, right}){
            if(child != nullptr) child -> lazy += lazy;
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
            child -> update(s, e, x);
        }
    }
    ll query(int s, int e){
        push();
        cout << l << " " << r << " " <<s<< " " << e << endl;
        if(s <= l && r <= e) return value;
        if(e <= l || r <= s) return 0;
        ll ret = 0;
        for(auto child: {left, right}){
            ret += child -> query(s, e);
        }
        return ret;
    }
} root;