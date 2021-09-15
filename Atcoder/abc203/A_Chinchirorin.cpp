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

int j, s[7], c;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    rep(i, 0, 3){
        cin >> j;
        s[j] ^= 1;
    }
    rep(i, 0, 6) c += s[i + 1];
    if(c > 1) cout << 0;
    else rep(i, 0, 6){
        if(s[i + 1]) {
            cout << i + 1;
        }
    }
}
