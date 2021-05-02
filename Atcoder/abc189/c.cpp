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

const int MAX = 1e4, INF = 1e9;
ll n, A[MAX], ans;

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

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> n;
    SegTree.init(n);
    rep(i, 0, n) {
        cin >> A[i];
        SegTree.update(i, A[i]);
    }
    rep(i, 0, n){
        int tmp, l = 0, r = i;
        while(l < r){
            int m = l + r >> 1;
            if(SegTree.query(m, i) < A[i]) l = m + 1;
            else r = m;
        }
        tmp = l;
        l = i, r = n;
        while(l + 1 < r){
            int m = l + r >> 1;
            if(SegTree.query(i + 1, m + 1) < A[i]) r = m;
            else l = m;
        }
        ans = max(ans, (l - tmp + 1) * A[i]);
    }
    cout << ans;
}
