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

const int MAX = 1<<17;
int TC, L, R, A[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> L >> R;
        cinA(A, R - L + 1);
        vector<int> P(17), Q(17);
        rep(i, L, R + 1){
            rep(j, 0, 17) if(i & (1 << j)) P[j]++;
            rep(j, 0, 17) if(A[i - L] & (1 << j)) Q[j]++;
        }
        int ans = 0;
        rep(i, 0, 17) if(P[i] ^ Q[i]) ans ^= 1 << i;
        cout << ans << "\n";
    }
}
