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

const int MAX = 1e3;
ll TC, N, K, A[MAX];
void solve(){
    cin >> N >> K; cinA(A, N);
    ll t = 0, s = accumulate(A, A + N, 0LL);
    rep(i, 0, N) rep(j, i + 1, N) t += A[i] * A[j];
    if(t == 0){
        cout << "0";
        return;
    }
    if(s == 0){
        cout << "IMPOSSIBLE";
        return;
    }
    if(t % s == 0){
        cout << -t / s;
        return;
    }
    if(K == 1){
        cout << "IMPOSSIBLE";
        return;
    }
    cout << s * s - t - s << " " << 1 - s;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    rep(tc, 1, TC + 1){
        cout << "Case #" << tc << ": "; solve(); cout << "\n";
    }
}
