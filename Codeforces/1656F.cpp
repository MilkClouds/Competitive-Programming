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

const int MAX = 2e5;
ll TC, N, A[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N;
        cinA(A, N);
        sort(A, A + N);
        pl W;
        ll ans = -1e18;
        rep(i, 1, N){
            W.x += A[i] * A[0];
            W.y += A[i] + A[0];
        }
        ans = max(ans, W.x - A[1] * W.y);
        if(W.y > 0) {cout << "INF\n"; continue;}
        rep(i, 1, N - 1){
            W.x += A[i] * (A[N - 1] - A[0]);
            W.y += A[N - 1] - A[0];
            ans = max(ans, W.x - A[i + 1] * W.y);
        }
        if(W.y < 0) {cout << "INF\n"; continue;}
        cout << ans << "\n";
    }
}
