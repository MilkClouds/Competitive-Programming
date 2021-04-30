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

ll gcd(ll a, ll b){
    if(a % b == 0) return b;
    return gcd(b, a % b);
}
map<pl, ll> m;
ll ans, N, a, b, c;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) {
        cin >> a >> b >> c;
        if(b == 0) m[{0, 1}]++;
        else if(a == 0) m[{1, 0}]++;
        else {
            ll g = gcd(a, b);
            m[{a / g, b / g}]++;
        }
    }
    ans = N * (N - 1) / 2;
    for(auto [_, i]: m){
        ans -= i * (i - 1) / 2;
    }
    cout << ans;
}
