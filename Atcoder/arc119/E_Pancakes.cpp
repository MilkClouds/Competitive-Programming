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
const ll INF = 1e18;
ll N, ans, a[MAX], b[MAX], c[MAX];
ll t;
map<ll, ll> X, Y;
map<ll, vector<ll>> A, B;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) c[i] = a[i];
    rep(i, 1, N) b[i - 1] = a[i];
    N--;
    rep(i, 0, N){
        if(a[i] <= b[i]){
            X[a[i]] = max(X[a[i]], b[i]);
            // if(A.count(a[i]) == 0) A[a[i]] = vector<ll>();
            A[a[i]].pb(b[i]);
        } else {
            Y[b[i]] = max(Y[b[i]], a[i]);
            // if(B.count(b[i]) == 0) B[b[i]] = vector<ll>();
            B[b[i]].pb(a[i]);
        }
    }
    ll tmp = 0;
    for(auto& p: X){
        p.y = max(p.y, tmp);
        sort(all(A[p.x]));
        if(A[p.x].size() > 1) ans = min(ans, 2 * (p.x - A[p.x][A[p.x].size() - 2]));
        tmp = p.y;
    }
    tmp = 0;
    for(auto& p: Y){
        p.y = max(p.y, tmp);
        sort(all(B[p.x]));
        if(B[p.x].size() > 1) ans = min(ans, 2 * (p.x - B[p.x][B[p.x].size() - 2]));
        tmp = p.y;
    }
    tmp = 0;
    rep(i, 0, N){
        auto& v = a[i] <= b[i] ? X : Y;
        if(a[i] > b[i]) swap(a[i], b[i]);
        t += b[i] - a[i];
        auto pos = v.lower_bound(a[i]);
        if(pos == v.begin()) continue;
        pos--;
        tmp = max(tmp, min(b[i], pos -> y) - a[i]);
    }
    ans = min(ans, - tmp * 2);
    N++;
    rep(i, 0, N) a[i] = c[i];
    rep(i, 1, N){
        ans = min(ans, abs(a[0] - a[i]) - abs(a[i] - a[i - 1]));
    }
    reverse(a, a + N);
    rep(i, 1, N){
        ans = min(ans, abs(a[0] - a[i]) - abs(a[i] - a[i - 1]));
    }
    cout << t + ans;
}
