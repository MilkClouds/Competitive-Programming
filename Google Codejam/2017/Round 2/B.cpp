# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
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
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1111;
int N, C, M, CC[MAX];
multiset<int> S[MAX];
pi A[MAX];

void solve(){
    int ans1 = 0, ans2 = 0;
    cin >> N >> C >> M;
    rep(i, 1, N + 1) S[i].clear();
    fill(CC, CC + MAX, 0);
    rep(i, 0, M) cin >> A[i].x >> A[i].y, S[A[i].x].insert(A[i].y), CC[A[i].y]++;
    int SS = 0;
    rep(i, 1, N + 1){
        SS += S[i].size();
        ans1 = max(ans1, (i - 1 + SS) / i);
    }
    rep(i, 1, C + 1) ans1 = max(ans1, CC[i]);
    rep(i, 1, N + 1){
        ans2 += max(0, (int)S[i].size() - ans1);
    }
    cout << ans1 << " " << ans2 << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}