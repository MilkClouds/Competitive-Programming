#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
using namespace std;
using ll = long long;

const int MAX = 1e6 + 1;
int TC, N, A[MAX], B[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        ll ans = 0;
        cin >> N; cinA(A, N); B[N] = 0;
        rep2(i, 0, N) B[i] = max(B[i + 1], A[i]);
        rep(i, 0, N) ans += B[i] - A[i];
        cout << ans << "\n";
    }
}
