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
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;
using mi = atcoder::modint998244353;

const int MAX = 5e6 + 1;
int N, A, B, C;
mi fact[MAX], inv[MAX], ans;

void prepare(){
    fact[0] = 1;
    rep(i, 1, MAX){
        fact[i] = fact[i - 1] * i;
    }
    inv[MAX - 1] = fact[MAX - 1].pow(fact[0].mod() - 2);
    rep2(i, 1, MAX){
        inv[i - 1] = inv[i] * i;
    }
}
mi combination(int N, int r){
    if(r < 0 || N < r) return 0;
    return fact[N] * inv[r] * inv[N - r];
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> A >> B >> C;
    mi a = 1, b = 1, c = 1;
    prepare();
    rep(i, 0, N + 1){
        ans += ((N - i) % 2 ? -1 : 1) * combination(N, i) * a * b * c;
        a = 2 * a - combination(i, A);
        b = 2 * b - combination(i, B);
        c = 2 * c - combination(i, C);
    }
    cout << ans.val() << endl;
}
