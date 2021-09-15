# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 15e5 + 1, INF = 1e7;
int N, M, A[MAX], ans = INF;

struct AB{
    int x;
    AB(int x): x(x){}
    AB():AB(0){}
    int get(int v){
        if(x < 0) return INF;
        if(x == 0) return v;
        return x;
    }
};

struct SegTree{
    AB tree[MAX * 4];
    void update(int node, int l, int r, int x, int v){
        if(r <= x || x < l) return;
        if(r - l == 1){
            tree[node].x -= v;
            return;
        }
        int m = l + r >> 1;
        update(node * 2, l, m, x, v);
        update(node * 2 + 1, m + 1, r, x, v);
        tree[node].x = min(tree[node * 2].get(node * 2), tree[node * 2 + 1].get(node * 2 + 1));
    }
} tree;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, 0, N) {cin >> A[i]; A[i]++;}
    rep(i, 0, M) tree.update(1, 0, N, A[i], 1);
    rep(i, 0, N - M + 1){
        ans = min(ans, tree.tree[1].x);
        cout << tree.tree[1].x << endl;
        tree.update(1, 0, N, A[i], -1);
        tree.update(1, 0, N, A[i + M], 1);
    }
    cout << ans - 1;
}
