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

int N, K;
string S;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K >> S;
    rep(i, 1, N + 1){
        if(N % i) continue;
        rep(s, 0, N){
            // [s, s+i)
            ll cnt = 0;
            vector<vector<int>> count(i, vector<int>(26));
            rep(j, 0, N / i){
                rep(k, 0, i){
                    count[k][S[(s + j * i + k) % N] - 'a']++;
                    //if(S[(s + j * i + k) % N] != S[(s + k) % N]) cnt++;
                }
            }
            rep(k, 0, i){
                int me = 1e9;
                rep(a, 0, 26) if(a != S[(s + k) % N] - 'a') me = min(me, N / i - count[k][a]);
                cnt += min(N / i - count[k][S[(s + k) % N] - 'a'], me);
            }
            if(cnt <= K){
                cout << i << "\n";
                return 0;
            }
        }
    }
    return 1;
}
