#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define x first
#define y second
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

const int MLOG = 21;
const int MAX = 1 << MLOG;
array<ll, MAX> M, nM;
ll A[MAX], P;
pi B[MAX], C[MAX];
ll product(ll q){
    if(A[q]) return A[q];
    ll ret = 0;
    rep(i, 0, MLOG){
        if(P & (1LL << i)){
            ret ^= q << i;
        }
    }
    return A[q] = ret;
}

inline pi calc(ll a, bool type = 0){
    if(type){
        if(C[a].x) return C[a];
        ll b = a;
        a = product(a);
        ll R = 0, S = 0;
        ll k = 1, t = 1;
        rep(i, 0, 2 * MLOG - 1) {
            if(a & k) (i & 1 ? R : S) ^= t;
            k <<= 1;
            if(i & 1) t <<= 1;
        }
        return C[b] = pi(R, S);
    }
    if(B[a].x) return B[a];
    ll R = 0, S = 0;
    ll k = 1, t = 1;
    rep(i, 0, MLOG) {
        if(a & k) (i & 1 ? R : S) ^= t;
        k <<= 1;
        if(i & 1) t <<= 1;
    }
    return B[a] = pi(R, S);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    ll d, t, n, ans = 0;
    cin >> d;
    rep(i, 0, d + 1){
        cin >> t;
        if(t) P ^= 1 << i;
    }
    cin >> n;
    M[1 << 0]++;
    while(n){
        rep(Q, 0, MAX){
            if(M[Q] == 0) continue;
            ll cnt = M[Q];
            M[Q] = 0;
            if(n & 1){
                auto [R, S] = calc(Q, 1);
                nM[R] += cnt;
                nM[S] += cnt;
            } else {
                auto [R, S] = calc(Q);
                nM[R] += cnt;
                nM[S] += cnt;
            }
        }
        nM.swap(M);
        n >>= 1;
    }
    rep(Q, 0, MAX) if(M[Q]) ans += __builtin_popcountll(Q) * M[Q];
    cout << ans << "\n";
}