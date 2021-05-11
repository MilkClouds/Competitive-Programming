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

int TC, a;
int calc(int a){
    vector<int> v;
    rep(i, 0, 4){
        v.pb(a % 10);
        a /= 10;
    }
    sort(all(v));
    a = v[0] + 10 * v[1] + 100 * v[2] + 1000 * v[3];
    reverse(all(v));
    return a - (v[0] + 10 * v[1] + 100 * v[2] + 1000 * v[3]);
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> a;
        int cnt = 0;
        while(1){
            if(a == 6174) break;
            a = calc(a);
            cnt++;
        }
        cout << cnt << "\n";
    }
}
