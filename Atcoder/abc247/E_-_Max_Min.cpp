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

const int MAX = 2e5 + 1;
int N, X, Y, A[MAX], S[MAX], SM[MAX], Sm[MAX];
ll ans;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> X >> Y;
    cinA(A, N);
    rep(i, 0, N){
        S[i + 1] = S[i] + (A[i] > X || A[i] < Y);
        SM[i + 1] = SM[i] + (A[i] == X);
        Sm[i + 1] = Sm[i] + (A[i] == Y);
    }
    rep(i, 0, N){
        int r1 = upper_bound(S, S + N + 1, S[i]) - S - 1;
        int r2 = upper_bound(SM, SM + N + 1, SM[i]) - SM - 1;
        int r3 = upper_bound(Sm, Sm + N + 1, Sm[i]) - Sm - 1;
        if(r2 == N || r3 == N) break;
        ans += max(0, r1 - max(r2, r3));
    }
    cout << ans << endl;
}
