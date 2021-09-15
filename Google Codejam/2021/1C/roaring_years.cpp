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

const ll INF = 9e18;
int TC;
ll Y, ans;

ll f(ll n, ll m){
    string S;
    rep(i, 0, n) S += to_string(m + i);
    try{
        return stoll(S);
    } catch(out_of_range& expn) {
        return INF;
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    rep(tc, 1, TC + 1){
        cin >> Y;
        ans = INF;
        rep(n, 2, 20){
            ll l = 1, r = 12345678910LL;
            while(l < r){
                ll m = l + r >> 1;
                if(f(n, m) > Y) r = m;
                else l = m + 1;
            }
            ans = min(ans, f(n, l));
        }
        printf("Case #%d: %lld\n", tc, ans);
    }
}
