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

const int MAX = 1e5;
ll N, L, W, A[MAX], S, T, ans;
map<ll, ll> event;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> L >> W;
    cinA(A, N);
    rep(i, 0, N){
        event[A[i]]++;
        event[A[i] + W]--;
    }
    event[0] += 0;
    event[L] += 0;
    for(auto [i, j]: event){
        if(T == 0) {
            ans += (W + i - S - 1) / W;
        }
        S = i;
        T += j;
    }
    cout << ans << endl;
}
