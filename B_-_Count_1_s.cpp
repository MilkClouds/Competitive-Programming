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

const int MAX = 3e5 + 2, INF = 1e9;
int N, A[MAX], S[MAX], M = -INF, m = INF;
multiset<int> SS;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cinA(A, N);
    rep(i, 0, N) S[i + 1] = S[i] + A[i];
    rep(i, 1, N + 2) SS.insert(i - 2 * S[i - 1]);
    rep(i, 1, N + 1){
        M = max(M, *SS.rbegin() - (i - 2 * S[i - 1]));
        m = min(m, *SS.begin() - (i - 2 * S[i - 1]));
        SS.erase(SS.find(i - 2 * S[i - 1]));
    }
    cout << M - m + 1;
}
