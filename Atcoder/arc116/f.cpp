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

const int MAX = 2e5;
int K, NN, N[MAX], t;
ll ans;
vector<int> A[MAX], v;
int get(int i, int s, int e){
    if(s == e) return A[i][s];
    int m = s + e >> 1;
    if(!t) return min(max(A[i][m + 1], A[i][m - 1]), A[i][m]);
    return max(min(A[i][m + 1], A[i][m - 1]), A[i][m]);
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> K;
    rep(i, 0, K){
        cin >> N[i];
        t += N[i];
        A[i].resize(N[i]);
        rep(j, 0, N[i]) {
            cin >> A[i][j];
        }
    }
    t = t - K & 1;
    rep(i, 0, K){
        if(N[i] & 1) ans += get(i, 0, N[i] - 1);
        else {
            int a = get(i, 1, N[i] - 1), b = get(i, 0, N[i] - 2);
            if(a < b) swap(a, b);
            ans += b;
            v.pb(a - b);
        }
    }
    sort(all(v), greater<int>());
    rep(i, 0, v.size()) ans += v[i++];
    cout << ans << endl;
}
