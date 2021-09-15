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
ll N, K, A[103];
set<ll> C;
void process(ll u){
    ll sq = (ll) sqrt(u);
    rep(i, 1, sq + 2){
        ll tmp = (u + i - 1) / i;
        C.insert(tmp);
        C.insert((tmp + i - 1) / i);
    }
}
ll solve(ll u){
    ll b = 0, a = 0;
    rep(i, 0, N){
        ll t = (u + A[i] - 1) / u;
        b += t * u - A[i];
        a += t;
    }
    if(K - b < 0) return -1;
    return (K - b) / a + u;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) {
        process(A[i]);
    }
    for(auto pos = C.rbegin(); pos != C.rend(); pos++){
        //cout << (*pos) << " " << solve(*pos) << endl;
        ll tmp = solve(*pos);
        if(~tmp){
            cout << tmp << endl;
            return 0;
        }
    }
}
