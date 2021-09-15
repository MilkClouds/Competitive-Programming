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

const ll MOD = 998244353;
const int MAX = 2e5 + 1;
int N, f[MAX], fin[MAX], vis[MAX], cnt;

bool dfs(int u){
    bool ret = 0;
    vis[u] = 1;
    int v = f[u];
    if(!vis[v]) ret |= dfs(v);
    else if(!fin[v]) {ret = 1; cnt++;}
    fin[u] = 1;
    return ret;
}
ll calc(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    ret = (ret + MOD - 1) % MOD;
    return ret;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 1, N + 1) cin >> f[i];
    rep(i, 1, N + 1) if(!vis[i]) dfs(i);
    cout << calc(2, cnt);
}
