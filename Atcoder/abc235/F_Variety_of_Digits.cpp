#include <bits/stdc++.h>
#include <atcoder/modint>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
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
using mi = atcoder::modint998244353;
using arr = array<mi, 1024>;


string N;
int M, mask, digits, x;
arr c, s;
mi ans, S;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, M){
        cin >> x;
        mask |= 1 << x;
    }
    rep(i, 0, N.size()){
        int k = N[i] - '0';
        arr nc, ns;
        rep(j, 1, 1024){
            rep(d, 0, 10){
                nc[j | 1 << d] += c[j];
                ns[j | 1 << d] += s[j] * 10 + c[j] * d;
            }
        }
        if(i){
            rep(d, 1, 10){
                nc[1 << d] += 1;
                ns[1 << d] += d;
            }
        }
        rep(d, !i, k){
            nc[digits | 1 << d] += 1;
            ns[digits | 1 << d] += S * 10 + d;
        }
        c = nc; s = ns;
        digits |= 1 << k;
        S = S * 10 + k;
    }
    rep(j, 0, 1024) if((j & mask) == mask) ans += s[j];
    if((digits & mask) == mask) ans += S;
    cout << ans.val() << endl;
}
