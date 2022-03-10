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

const int MAX = 1e6 + 1;
int N, K, A[MAX], cnt;
vector<pi> ans;
void solve(int l, int r, int k1, int k2){
    if(l > r) return;
    int m = l + r >> 1;
    if(K){
        ans.eb(k1, m);
        K--;
    } else ans.eb(k2, m), k1 = k2;
    solve(l, m - 1, k1 - (m - l), k1 + (m - l));
    solve(m + 1, r, k1 + (r - m), k1 - (r - m));
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    solve(1, N, 0, 0);
    sort(all(ans));
    cnt = 1;
    for(auto [i, j]: ans) A[j] = cnt++;
    cout << "YES\n";
    rep(i, 1, N + 1) cout << A[i] << " ";
}
