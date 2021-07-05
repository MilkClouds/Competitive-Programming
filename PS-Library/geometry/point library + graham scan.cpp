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

struct Point{
    ll x, y;
    Point(): Point(0, 0){}
    Point(ll x, ll y): x(x), y(y) {}
    bool operator < (const Point& o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
    Point operator + (const Point& o) const {
        return Point(x + o.x, y + o.y);
    }
    Point operator - (const Point& o) const {
        return Point(x - o.x, y - o.y);
    }
};
ll ccw(const Point& A, const Point& B){
    return 1LL * A.x * B.y - 1LL * A.y * B.x;
}
ll ccw(const Point& A, const Point& B, const Point& C){
    return ccw(B - A, C - A);
}
void solve(){
    int j = 1;
    rep(i, 0, N){
        while(j < 2 * N && ccw({0, 0}, A[i], A[j]) > 0){
            j++;
        }
        // query for i ~ j
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    
}
