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


struct Circle{
    pi a;
    int r;
} C[51];
inline int dist(pi a, pi b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool contain(Circle c, pi a){
    return dist(c.a, a) < c.r * c.r;
}

void solve(){
    pi S, E;
    int ans = 0, N;
    cin >> S.x >> S.y >> E.x >> E.y;
    cin >> N;
    rep(i, 0, N){
        cin >> C[i].a.x >> C[i].a.y >> C[i].r;
        ans += contain(C[i], S) ^ contain(C[i], E);
    }
    cout << ans << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--){
        solve();
    }
}