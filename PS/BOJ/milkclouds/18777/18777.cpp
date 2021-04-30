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

const int MAX = 1e5;
int N, K, u, v, flag, rt;
vector<int> adj[MAX];


int dfs(int u, int p){
    vector<int> vv;
    for(auto v: adj[u]) if(v ^ p) vv.pb(dfs(v, u) + 1);
    if(sz(vv) % 2 == 0) vv.pb(0);
    sort(all(vv));
    auto func = [&](int x){
        vector<int> w;
        rep(i, 0, sz(vv)) if(i ^ x) w.pb(vv[i]);
        rep(i, 0, sz(w) / 2) if(w[i] + w[sz(w) - i - 1] < K) return 0;
        return 1;
    };
    int s = 0, e = sz(vv) - 1;
    if(!func(0)){
        flag = 0;
        return 0;
    }
    while(s < e){
        int m = s + e + 1 >> 1;
        if(func(m)) s = m;
        else e = m - 1;
    }
    return vv[s];
}


bool trial(int m){
    K = m;
    flag = 1;
    if(dfs(rt, -1) < K) flag = 0;
    return flag;
}


int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 1, N){
        cin >> u >> v; u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    while(sz(adj[rt]) > 1) rt++;
    if(N <= 3) {
        cout << N - 1;
        return 0;
    }
    int s = 1, e = N;
    while(s < e){
        int m = s + e + 1 >> 1;
        if(trial(m)) s = m;
        else e = m - 1;
    }
    cout << s;
}
