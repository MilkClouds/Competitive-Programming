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

const int MAXN = 1e5, MAX = 1e6 + 1, bias = 5e5 + 1;

struct FenwickTree {
public:
    FenwickTree() : FenwickTree(0) {}
    explicit FenwickTree(int N) : N(N), tree(N + 1, 0) {}
    int query(int i) {
        int ret = 0;
        for (; i; i ^= i & -i)ret += tree[i];
        return ret;
    }
    void update(int i, int x) {
        for (; i <= N; i += i & -i)tree[i] += x;
    }
private:
    int N;
    vector<int> tree;
} FT_Y(MAX), FT_X(MAX);

int N, ans;
pi A[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) cin >> A[i].x >> A[i].y;
    rep(i, 0, N){
        int j = (i + 1) % N;
        if(A[i].x == A[j].x){
            int a = A[i].y, b = A[j].y;
            if(a > b) swap(a, b);
            FT_Y.update(a + bias, 1);
            FT_Y.update(b + bias, -1);
        } else {
            int a = A[i].x, b = A[j].x;
            if(a > b) swap(a, b);
            FT_X.update(a + bias, 1);
            FT_X.update(b + bias, -1);
        }
    }
    rep(i, 0, MAX){
        ans = max(ans, FT_X.query(i));
        ans = max(ans, FT_Y.query(i));
    }
    cout << ans;
}

