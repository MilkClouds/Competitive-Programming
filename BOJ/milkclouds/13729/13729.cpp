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

const ll mod = 1e13;
ll N;
typedef vector<vector<__int128>> matrix;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<__int128>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}
ll fibo(ll n){
    matrix ans = {{1, 0}, {0, 1}};
    matrix a = {{1, 1}, {1, 0}};
    while(n){
        if(n % 2) ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans[0][1];
}
ll cpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
vector<ll> f(ll n, ll k){
    ll tmod = cpow(10, k - 1) * 15;
    ll vmod = cpow(10, k);
    vector<ll> ret;
    if(k == 3){
        rep(i, 1, tmod + 1){
            if(fibo(i) % vmod == n) ret.pb(i);
        }
        return ret;
    }
    auto prev = f(n % (vmod / 10), k - 1);
    for(auto j: prev){
        rep(i, 0, 10){
            if(fibo(j + i * tmod / 10) % vmod == n) ret.pb(j + i * tmod / 10);
        }
    }
    sort(all(ret));
    return ret;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    auto tmp = f(N, 13);
    cout << (tmp.empty() ? -1 : tmp[0]);
}
