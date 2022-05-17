#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define rep2(i,a,b) for(ll i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

// 11:55~13:40
const int MAX = 3001;
ll N, M, K, A[MAX], S[MAX], F, ans = 1, MP, MN;
vector<int> B;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    cinA(A, N);
    rep(i, 0, N) S[i + 1] = S[i] + A[i]; F = -S[N];
    rep(i, 0, N) if(A[i] == 0) B.eb(i);
    M = B.size();
    if(abs(F) > M * K){cout << -1; return 0;}
    int namu = M - (abs(F) + K - 1) / K;
    ll extra = (M - namu) * K - abs(F);
    if(F < 0){
        MP = (namu / 2) * K;
        MN = -(namu / 2) * K + F;
        if(namu % 2) MP += extra, MN -= extra;
    } else {
        MP = (namu / 2) * K + F;
        MN = -(namu / 2) * K;
        if(namu % 2) MN -= extra, MP += extra;
    }
    assert(MP + MN == F);
    rep(i, 0, N){
        int lcount = upper_bound(all(B), i) - B.begin();
        ll plus = min(MP, lcount * K);
        if(MP < lcount * K) assert((MP - F) - (M - lcount) * K>=0);
        if(MP < lcount * K) plus -= max(0LL, (MP - F) - (M - lcount) * K);
        rep(j, i + 1, N){
            int rcount = upper_bound(all(B), j) - B.begin(); rcount -= lcount;
            F -= plus; M -= lcount;
            namu = M - (abs(F) + K - 1) / K;
            extra = (M - namu) * K - abs(F);
            if(F < 0){
                MN = -(namu / 2) * K + F;
                if(namu % 2) MN -= extra;
            } else {
                MN = -(namu / 2) * K;
                if(namu % 2) MN -= extra;
            }
            ll minus = max(MN, -rcount * K);
            if(MN > -rcount * K) minus += F - MN - (M - rcount) * K;
            F += plus; M += lcount;
            ll a = S[i + 1] + plus;
            ll b = S[j + 1] + plus + minus;
            if(a < 0 || b > 0) continue;
            ans = max(ans, a - b + 1);
        }
    }
    // ===
    rep(i, 0, N) A[i] *= -1, S[i + 1] *= -1; F *= -1;
    namu = M - (abs(F) + K - 1) / K;
    extra = (M - namu) * K - abs(F);
    if(F < 0){
        MP = (namu / 2) * K;
        MN = -(namu / 2) * K + F;
        if(namu % 2) MP += extra, MN -= extra;
    } else {
        MP = (namu / 2) * K + F;
        MN = -(namu / 2) * K;
        if(namu % 2) MN -= extra, MP += extra;
    }
    assert(MP + MN == F);
    rep(i, 0, N){
        int lcount = upper_bound(all(B), i) - B.begin();
        ll plus = min(MP, lcount * K);
        if(MP < lcount * K) assert((MP - F) - (M - lcount) * K>=0);
        if(MP < lcount * K) plus -= max(0LL, (MP - F) - (M - lcount) * K);
        rep(j, i + 1, N){
            int rcount = upper_bound(all(B), j) - B.begin(); rcount -= lcount;
            F -= plus; M -= lcount;
            namu = M - (abs(F) + K - 1) / K;
            extra = (M - namu) * K - abs(F);
            if(F < 0){
                MN = -(namu / 2) * K + F;
                if(namu % 2) MN -= extra;
            } else {
                MN = -(namu / 2) * K;
                if(namu % 2) MN -= extra;
            }
            ll minus = max(MN, -rcount * K);
            if(MN > -rcount * K) minus += F - MN - (M - rcount) * K;
            F += plus; M += lcount;
            ll a = S[i + 1] + plus;
            ll b = S[j + 1] + plus + minus;
            if(a < 0 || b > 0) continue;
            ans = max(ans, a - b + 1);
        }
    }
    cout << ans << "\n";
}
