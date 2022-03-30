#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

const int MAX = 2e5 + 1;
string S;
int TC, N, M, A[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N >> M >> S;
        ll cnt = count_if(all(S), [](auto i){return i == '1';});
        if(cnt * M % N){
            cout << "-1\n";
            continue;
        }
        A[0] = count_if(S.begin(), S.begin() + M, [](auto i){return i == '1';});
        rep(i, 1, N) A[i] = A[i - 1] + (S[(M - 1 + i) % N] == '1') - (S[i - 1] == '1');
        rep(i, 0, N){
            if(A[i] == cnt * M / N){
                if(i + M <= N) cout << "1\n" << i + 1 << " " << i + M << "\n";
                else cout << "2\n" << 1 << " " << (i + M) % N << "\n" << i + 1 << " " << N << "\n";
                break;
            }
        }
    }
}
