#include <bits/stdc++.h>
#include <atcoder/modint>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
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
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;
using mi = atcoder::modint998244353;

const int MAX = 2e6 + 1;
ll N, D;
mi ans, tmp, A[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> D;
    A[0] = 1;
    rep(i, 1, MAX) A[i] = A[i - 1] * 2;
    rep(i, 0, N){
        tmp = 0;
        if(i + D <= N - 1) tmp += A[D];
        tmp += A[D - 2] * max(0LL, (1 + min(D - 1, (N - 1 - i)) - max(1LL, i + D + 1 - N)));
        ans += tmp * 2 * A[i];
    }
    cout << ans.val();
}
