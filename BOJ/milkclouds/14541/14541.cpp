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
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

int n, a, b, c;
int main() {
    // cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    while(~scanf("%d", &n)){
        if(n == -1) break;
        ll d = 0;
        c = 0;
        rep(i, 0, n) {
            cin >> a >> b;
            d += a * (b - c);
            c = b;
        }
        printf("%lld miles\n", d);
    }
}