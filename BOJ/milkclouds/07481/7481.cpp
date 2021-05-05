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

ll a, b, L, t, s;
ll gcd(ll a, ll b){
    return a % b ? gcd(b, a % b) : b;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> a >> b >> L;
        if(L % gcd(a, b) != 0){
            cout << "Impossible\n";
            continue;
        }
        s = 0;
        if(a > b) {s = 1; swap(a, b);}
        int flag = 0;
        rep2(i, 0, L / b + 1){
            if((L - b * i) % a == 0){
                if(!s) cout << (L - b * i) / a << " " << i << "\n";
                else cout << i << " " <<  (L - b * i) / a << "\n";
                flag = 1;
                break;
            }
            if(flag) break;
        }
        if(!flag) cout << "Impossible\n";
    }
}
