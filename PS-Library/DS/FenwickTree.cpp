#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 0-indexed
struct FenwickTree {
public:
    FenwickTree() : FenwickTree(0) {}
    explicit FenwickTree(int N) : N(N), tree(N + 1, 0) {}
    ll query(int i) {
        ll ret = 0; i++;
        for(; i; i ^= i & -i) ret += tree[i];
        return ret;
    }
    void update(int i, ll x) {
        i++;
        for(; i <= N; i += i & -i) tree[i] += x;
    }
private:
    int N;
    vector<ll> tree;
};
