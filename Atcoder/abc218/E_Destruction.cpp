#include <bits/stdc++.h>
#include <atcoder/dsu>
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

int N, M;
ll ans;
priority_queue<ti> pq;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    atcoder::dsu DSU(N + 1);
    rep(i, 0, M){
        int u, v, c;
        cin >> u >> v >> c;
        ans += c;
        pq.em(-c, u, v);
    }
    while(!pq.empty()){
        auto [c, u, v] = pq.top(); pq.pop(); c *= -1;
        if(DSU.same(u, v) && c > 0) continue;
        DSU.merge(u, v);
        ans -= c;
    }
    cout << ans << endl;
}
