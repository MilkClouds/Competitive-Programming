#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct FenwickTree {
public:
    FenwickTree() : FenwickTree(0) {}
    explicit FenwickTree(int N) : N(N), tree(N + 1, 0) {}
    ll query(int i) {
        ll ret = 0;
        for(; i; i ^= i & -i) ret += tree[i];
        return ret;
    }
    void update(int i, int x) {
        for(; i <= N; i += i & -i) tree[i] += x;
    }
private:
    int N;
    vector<int> tree;
};
