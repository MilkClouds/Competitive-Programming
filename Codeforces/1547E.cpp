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

const int MAX = 3e5, INF = 2e9;
int N, K;
pi A[MAX];
void solve(){
    cin >> N >> K;
    rep(i, 0, K) cin >> A[i].x;
    rep(i, 0, K) cin >> A[i].y;
    sort(A, A + K);
    multiset<int> S1, S2;
    rep(i, 0, K) S1.emplace(A[i].y + A[i].x);
    int j = 0;
    rep(i, 1, N + 1){
        int ans = INF;
        if(j < K && A[j].x == i){
            S1.erase(S1.find(A[j].x + A[j].y));
            S2.emplace(A[j].y - A[j].x);
            j++;
        }
        if(S1.size()) ans = min(ans, *S1.begin() - i);
        if(S2.size()) ans = min(ans, *S2.begin() + i);
        cout << ans << " ";
    }
    cout << "\n";
}


int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--) solve();
}
