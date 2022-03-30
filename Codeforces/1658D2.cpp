#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
using namespace std;
using ll = long long;

const int MAX = 1<<17;
int TC, L, R, A[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> L >> R;
        cinA(A, R - L + 1);
        vector<map<int, int>> P(17), Q(17);
        rep(i, L, R + 1){
            rep(j, 0, 17) P[j][i >> j]++;
            rep(j, 0, 17) Q[j][A[i - L] >> j]++;
        }
        int ans = 0;
        rep2(i, 0, 17){
            ans <<= 1;
            for(auto [mask, cnt]: P[i]){
                if(Q[i][mask ^ ans] != cnt){
                    ans ^= 1;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}
