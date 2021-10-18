#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 5000;
ll N, M, S, A[MAX], pS[MAX + 1];
double ans;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> S;
    cinA(A, N);
    rep(i, 0, N) pS[i + 1] = pS[i] + A[i];
    rep(i, 0, N) rep(j, i + 1, N){
        double tmp = S - (double)M * (N - j);
        double x1 = tmp / (j - i);
        double x2 = M - x1;
        if(x1 < 0 || x2 < 0) continue;
        ans = max(ans, (pS[N] - pS[i]) * x1 + (pS[N] - pS[j]) * x2);
    }
    rep(i, 0, N){
        ans = max(ans, (pS[N] - pS[i]) * min((double)M, (double)S / (N - i)));
    }
    cout.precision(16);
    cout << fixed << ans << "\n";
}
