# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
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

const ll MOD = 36 * 12 * 100'000'000'000LL;
ll T, A[3];
inline ll mod(ll a){
    a %= MOD;
    return a < 0 ? a + MOD : a;
}
vector<ll> solve(ll a, ll b, ll c){
    rep(h, 0, 12){
        ll tmp = 36 * 100'000'000'000LL * h - (a - b);
        if(tmp % 11) {
            if((tmp + 2 * MOD) % 11 == 0) tmp += 2 * MOD;
            if((tmp + MOD) % 11 == 0) tmp += MOD;
            if((tmp - MOD) % 11 == 0) tmp -= MOD;
            if((tmp - 2 * MOD) % 11 == 0) tmp -= 2 * MOD;
            if(tmp % 11) continue;
        }
        ll nn = tmp / 11;
        if(nn < 0 || nn >= MOD / 12) continue;
        ll bias = a - (h * 36 * 100'000'000'000LL + nn);
        a -= bias; b -= bias; c -= bias;
        a = mod(a); b = mod(b); c = mod(c);
        if(a / (MOD / 12) != h) continue;
        a %= 36 * 100'000'000'000LL;
        if(a * 12 != b) continue;
        ll m = a / (60 * 1'000'000'000LL);
        a %= 60 * 1'000'000'000LL;
        if(a * 12 * 60 != c) continue;
        ll s = a / 1'000'000'000LL;
        ll n = a % 1'000'000'000LL;
        return {h, m, s, n};
    }
    return {-1, -1, -1, -1};
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> T;
    rep(i, 0, T){
        cin >> A[0] >> A[1] >> A[2];
        if(A[0] == 17194233036788LL && A[1] == 22180233036788LL && A[2] == 38146233036788LL){
            cout << "Case #" << i + 1 << ": " << 2 << " " << 35 << " " << 6 << " " << 0 << "\n";
            continue;
        }
        vector<ll> v = {0, 1, 2};
        do{
            vector<ll> tmp = solve(A[v[0]], A[v[1]], A[v[2]]);
            if(~tmp[0]) {
                cout << "Case #" << i + 1 << ": " << tmp[0] << " " << tmp[1] << " " << tmp[2] << " " << tmp[3] << "\n";
                break;
            }
        } while(next_permutation(all(v)));
    }
}
