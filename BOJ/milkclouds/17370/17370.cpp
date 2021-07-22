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

struct ABC{
    int x, y;
    ABC(): ABC(0, 0){}
    ABC(int x, int y): x(x), y(y){}
    ABC operator + (ABC o){
        return ABC(x + o.x, y + o.y);
    }
    bool operator < (const ABC& o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
} v[6] = {{0, 2}, {-1, 1}, {-1, -1}, {0, -2}, {1, -1}, {1, 1}};
ostream& operator << (ostream& os, const ABC& abc){
    return os << abc.x << " " << abc.y;
}
int N, cnt;
map<ABC, bool> vis;
void gogo(ABC pos, int i, int r){
    if(vis[pos]){
        if(r == N) cnt++;
        return;
    }
    if(r > N) return;
    vis[pos] = 1;
    gogo(pos + v[(i + 1) % 6], (i + 1) % 6, r + 1);
    gogo(pos + v[(i + 5) % 6], (i + 5) % 6, r + 1);
    vis.erase(pos);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    vis[{0, 0}] = 1;
    gogo(v[0], 0, 0);
    cout << cnt << endl;
}
