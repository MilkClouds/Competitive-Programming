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

const int MAX = 3e5;
int N, ans, a[MAX], b[MAX];
ll t;
map<int, int> X, Y;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> b[i];
    rep(i, 0, N){
        if(a[i] <= b[i]){
            X[a[i]] = max(X[a[i]], b[i]);
        } else {
            Y[b[i]] = max(Y[b[i]], a[i]);
        }
    }
    int tmp = 0;
    for(auto& p: X){
        p.y = max(p.y, tmp);
        tmp = p.y;
    }
    tmp = 0;
    for(auto& p: Y){
        p.y = max(p.y, tmp);
        tmp = p.y;
    }
    rep(i, 0, N){
        auto& v = a[i] <= b[i] ? Y : X;
        if(a[i] > b[i]) swap(a[i], b[i]);
        t += b[i] - a[i];
        auto pos = v.upper_bound(a[i]);
        if(pos == v.begin()) continue;
        pos--;
        ans = max(ans, min(b[i], pos -> y) - a[i]);
    }
    cout << (t - 2 * ans);
}
