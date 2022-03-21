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
using vi = vector<ll>;
const int MAX = 1e6 + 1;
int N, M, K, A[MAX];
vi solve(int N, int K){
    if(N <= 0){
        return vi(1 << K);
    }
    if(K == 0){
        return vi{A[N - 1]};
    }
    vi&& l = solve(N - (1 << K - 1), K - 1);
    vi&& r = solve(N, K - 1);
    vi ret(1 << K);
    rep(i, 0, 1 << K - 1){
        ret[i] = l[i] ^ r[i];
        ret[i + (1 << K - 1)] = r[i];
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    cinA(A, N);
    for(; (1 << K) < max(N, M); K++);
    auto&& ret = solve(N, K);
    rep(i, 0, M) cout << ret[i] << " ";
}
