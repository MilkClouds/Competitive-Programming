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

ll N, a, T, b, u[1000003], v[1000003];
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) rep(j, 0, N){
        cin >> a;
        T += a; v[i * N + j] = a;
    }
    sort(v, v + N * N);
    rep(i, 0, N * N) u[i + 1] = u[i] + v[i];
    rep(i, 0, 10'000'000 + 1){
        auto pos = upper_bound(v, v + N * N, i);
        if(u[pos - v] + (N * N - (pos - v)) * i >= (T + 1) / 2){
            cout << i << endl;
            return 0;
        }
    }
}
