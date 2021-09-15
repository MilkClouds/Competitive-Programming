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

const int MAX = 1e5 + 5;
ll P, a, b, c, d, S, n, m;
set<int> SS;
long long pow(long long a, long long b) {
	long long ret = 1;
	while (b) {
		if (b & 1) ret *= a;
		a *= a;
		a %= P;
		ret %= P;
		b >>= 1;
	}
	return ret;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> P >> a >> b;
    c = pow(a, P - 2);
    d = pow(b, P - 2);
    S = 1;
    rep(i, 1, P) {
        S = (S * a) % P;
        SS.insert(S);
        if(S == 1) {
            n = i;
            break;
        }
    }
    S = 1;
    rep(i, 1, P) {
        S = (S * b) % P;
        if(SS.count(S)) {
            m = i;
            break;
        }
    }
    if(P - 1 != n * m){
        cout << "No";
        return 0;
    }
    S = 1;
    cout << "Yes\n";
    if(n == 1){
        rep(i, 0, m){
            cout << S << " ";
            S = (S * b) % P;
        }
        cout << 1;
        return 0;
    }
    if(m == 1){
        rep(i, 0, n){
            cout << S << " ";
            S = (S * a) % P;
        }
        cout << 1;
        return 0;
    }
    rep(i, 1, m){
        cout << S << " ";
        S = (S * b) % P;
    }
    rep(i, 1, n){
        cout << S << " ";
        S = (S * a) % P;
    }
    rep(i, 1, m){
        cout << S << " ";
        S = (S * d) % P;
        rep(j, 2, n){
            cout << S << " ";
            if(i & 1) S = (S * c) % P;
            else S = (S * a) % P;
        }
    }
    cout << S << " ";
    cout << 1;
}
