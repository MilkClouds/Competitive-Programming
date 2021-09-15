#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const ll INF = 1e16;
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    ll l = -1, r = INF;
    int N = g.size();
    while(l + 1 < r){
        ll m = l + r >> 1;
        ll totl = 0, lmax = 0, totr = 0, rmax = 0;
        rep(i, 0, N){
            ll cnt = (m / t[i] + 1) / 2;
            ll left = min(cnt * w[i], (ll) g[i]);
            ll right = min(cnt * w[i] - left, (ll) s[i]);
            lmax += left;
            totl += left + right;
        }
        rep(i, 0, N){
            ll cnt = (m / t[i] + 1) / 2;
            ll right = min(cnt * w[i], (ll) s[i]);
            ll left = min(cnt * w[i] - right, (ll) g[i]);
            rmax += right;
            totr += left + right;
        }
        assert(totl == totr);
        if(lmax >= a && rmax >= b && totl >= a + b) r = m;
        else l = m;
    }
    assert(r < INF);
    return r;
}