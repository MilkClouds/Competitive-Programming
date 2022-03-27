#include <bits/stdc++.h>
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

const int MAX = 1e6 + 1;
int N, A[MAX], R[MAX] = {1};
ll pw(ll a, ll b, ll M){
    ll ret = 1;
    for(; b; b >>= 1, a = (a * a) % M) if(b & 1) ret = (a * ret) % M;
    return ret;
}
int solve(int N, int i){
    if(N == 0) return i;
    int j = 1;
    for(; j * (j - 1) / 2 <= N; j++); j--;
    A[i] = pw(R[i], 5, 7) % 10;
    fill(A + i + 1, A + i + j, 7);
    return solve(N - j * (j - 1) / 2, i + j);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, MAX) R[i] = R[i - 1] * 10 % 7;
    int i = solve(N, 0);
    rep2(j, 0, i) cout << A[j];
}
