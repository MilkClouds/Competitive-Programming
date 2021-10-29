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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

ll TC, N, K;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N >> K;
        ll t1 = floor(log2(K));
        if((1LL << t1 + 1) <= K) t1++;
        if((1LL << t1 - 1) > K) t1--;
        if(N - (1LL << t1 + 1) < 0){
            ll t = 0;
            N--;
            while(N > 0){
                N -= 1LL << t++;
            }
            cout << t << '\n';
            continue;
        } 
        ll t2 = (N - (1LL << t1 + 1) + K - 1) / K;
        cout << t1 + t2 + 1 << "\n";
    }
}
