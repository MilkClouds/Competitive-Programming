# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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

ll TC, p, q, n;
ll gcd(ll x, ll y){
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
ll calc(ll p, ll q, ll n){
    ll ans = (p / q) * n * (n + 1) / 2;
    if(p % q == 0) return ans;
    p = p % q;
    return ans + n * ((p * n) / q) - calc(q, p, (p * n) / q) + n / (q / gcd(p, q));
}
void solve(){
    cin >> p >> q >> n;
    cout << (p * n * (n + 1) / 2 - q * calc(p, q, n)) << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--) solve();
}
