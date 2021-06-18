# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(register int i = (a); i < (b); i++)
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

const int INF = 2e9, MAXB = 30, MOD = 1999, MAX = 1e6;
int N, C[MAXB], D[MAXB], E[MAXB], S1, S2, A[MAX], B[MAX];

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, N){
        rep(k, 0, MAXB){
            if(A[i] & (1 << k)) C[k]++;
            if(B[i] & (1 << k)) D[k]++;
        }
    }
    E[0] = 1;
    rep(i, 1, MAXB){
        E[i] = (E[i - 1] << 1) % MOD;
    }
    rep(i, 0, MAXB){
        S1 += ((ll) E[i] * C[i] * D[i]) % MOD;
    }
    S1 %= MOD;
    rep(k, 0, MAXB){
        int am[2] = {INF, INF}, aM[2] = {-1, -1};
        int bm[2] = {INF, INF}, bM[2] = {-1, -1};
        rep(i, 0, N){
            int cat = (A[i] & (1 << k)) > 0;
            int mask = A[i] & ((1 << k) - 1);
            am[cat] = min(am[cat], mask);
            aM[cat] = max(aM[cat], mask);
        }
        rep(i, 0, N){
            int cat = (B[i] & (1 << k)) > 0;
            int mask = B[i] & ((1 << k) - 1);
            bm[cat] = min(bm[cat], mask);
            bM[cat] = max(bM[cat], mask);
        }
        if(am[0] != INF && bm[0] != INF && !((am[0] + bm[0]) & (1 << k))) continue;
        if(am[1] != INF && bm[1] != INF && !((am[1] + bm[1]) & (1 << k))) continue;
        if(aM[0] != -1 && bM[1] != -1 && ((aM[0] + bM[1]) & (1 << k))) continue;
        if(aM[1] != -1 && bM[0] != -1 && ((aM[1] + bM[0]) & (1 << k))) continue;
        S2 |= 1 << k;
    }
    cout << S1 << " " << S2;
}
