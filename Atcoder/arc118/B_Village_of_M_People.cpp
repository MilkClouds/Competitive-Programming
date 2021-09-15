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

const int MAX = 1e5;
ll K, N, M, A[MAX], l, r = 5e18, m, ans_l[MAX], ans_r[MAX], sMin, sMax;
bool possible(ll eps){
    sMax = 0; sMin = 0;
    rep(i, 0, K) {
        sMax += (A[i] * M + eps) / N;
        sMin += (A[i] * M - eps + N - 1) / N;
        ans_l[i] = (A[i] * M - eps + N - 1) / N;
        ans_r[i] = (A[i] * M + eps) / N;
    }
    return (sMin <= M && M <= sMax);
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> K >> N >> M;
    rep(i, 0, K) cin >> A[i];
    while(l < r){
        m = l + r >> 1;
        if(possible(m)) r = m;
        else l = m + 1;
    }
    possible(l);
    rep(i, 0, K){
        ll tmp = min(M - sMin, ans_r[i] - ans_l[i]);
        sMin += tmp;
        ans_l[i] += tmp;
    }
    rep(i, 0, K) cout << ans_l[i] << " ";
}
