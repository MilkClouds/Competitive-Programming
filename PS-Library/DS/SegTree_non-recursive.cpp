#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MAX = 1e5, INF = 1e9;
template <class S, S (*op)(S, S), S (*e)()>
struct SegTree{
    SegTree(): SegTree(0) {}
    SegTree(int n): n(n), t(n * 4, e()) {}
    void update(int pos, S val) {
        t[pos + n] = val;
        for (pos += n; pos > 1; pos >>= 1) {
            t[pos >> 1] = op(t[pos], t[pos ^ 1]);
        }
    }
    S query(int l, int r){
        S ans = e();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = op(ans, t[l++]);
            if (r & 1) ans = op(ans, t[--r]);
        }
        return ans;
    }
    vector<S> t;
    int n;
};