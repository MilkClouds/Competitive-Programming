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

ll exEuclid(ll a, ll b, ll &s, ll &t) {
    if (b == 0) { s = 1; t = 0; return a; }
    ll gcd = exEuclid(b, a % b, s, t);
    ll tmp = t;
    t = s - (a / b)*t;
    s = tmp; if (s <= 0) { s += b; t -= a; }
    return gcd;
}
ll gcd(ll x, ll y){
    if(min(x, y) == 0) return max(x, y);
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
ll N, M, s, t, G;
ll solve(ll N, ll M){
    ll g = gcd(N, M);
    if(min(N, M) == 0) return g * g;
    if(g > 1) return solve(N / g, M / g) * g * g;
    if(N > M) swap(N, M);
    ll s = 0, t = 0;
    exEuclid(N, M, s, t);
    if(N > 1) return solve(1, t * N + s * M);
    if(M % 2) return 4;
    return 1;
}
int main(){
    cin >> N >> M;
    cout << solve(N, M) << endl;

}