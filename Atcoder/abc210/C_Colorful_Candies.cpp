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

const int MAX = 3e5;
int N, K, C[MAX], ans, cnt;
multiset<int> MS;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    rep(i, 0, N) cin >> C[i];
    rep(i, 0, K) {
        if(MS.find(C[i]) == MS.end()) cnt++;
        MS.insert(C[i]);
    }
    ans = cnt;
    rep(i, 0, N - K){
        MS.erase(MS.find(C[i]));
        if(MS.find(C[i]) == MS.end()) cnt--;
        if(MS.find(C[i + K]) == MS.end()) cnt++;
        MS.insert(C[i + K]);
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}
