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

const int MAX = 1000, INF = 1e9;
ll TC, N, K[MAX], H[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        map<ll, ll> S;
        cin >> N;
        cinA(K, N);
        cinA(H, N);
        rep(i, 0, N){
            S[K[i] - H[i] + 1]++;
            S[K[i]]--;
        }
        ll st = 0, save = INF, ans = 0;
        for(auto& [pos, d]: S){
            st += d;
            save = min(save, pos);
            if(st == 0){
                ans += (pos - save + 1) * (pos - save + 2) >> 1;
                save = INF;
            }
        }
        cout << ans << "\n";
    }
}
