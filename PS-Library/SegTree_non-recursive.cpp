#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MAX = 1e5, INF = 1e9;
struct SegTree{
    SegTree(): SegTree(0) {}
    SegTree(int n){
        t.assign(n * 4, INF);
        this -> n = n;
    }
    int op_func(int a, int b){
        return min(a, b);
    }
    void update(int pos, int val) {
        t[pos + n] = val;
        for (pos += n; pos > 1; pos >>= 1) {
            t[pos >> 1] = op_func(t[pos], t[pos ^ 1]);
        }
    }
    int query(int l, int r){
        int ans = INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = op_func(ans, t[l++]);
            if (r & 1) ans = op_func(ans, t[--r]);
        }
        return ans;
    }
    vector<int> t;
    int n;
};