#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
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

const int MAX = 2e5;
int N, TC, A[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        ll ans = 0;
        map<ll, ll> M;
        cin >> N;
        cinA(A, N);
        rep(i, 0, N) M[A[i]]++;
        ll S = accumulate(A, A + N, 0LL);
        if(S * 2 % N){
            cout << "0\n";
            continue;
        }
        for(auto [i, j]: M){
            ll k = S * 2 / N - i;
            if(i == k){
                ans += j * (j - 1) / 2;
            } else if(i > k){
                break;
            } else {
                ans += j * M[k];
            }
        }
        cout << ans << "\n";
    }
}
