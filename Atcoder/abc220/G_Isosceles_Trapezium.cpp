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

const int MAX = 1e3 + 1;
int N;
struct Point{
    ll x, y, c;
} A[MAX];
istream& operator >> (istream& is, Point& p){
    return is >> p.x >> p.y >> p.c;
}
ll gcd(ll x, ll y){
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
map<tl, map<ll, ll>> M;
ll ans = -1;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N){
        cin >> A[i];
    }
    rep(i, 0, N) rep(j, i + 1, N){
        ll dx = A[i].x - A[j].x;
        ll dy = A[i].y - A[j].y;
        if(dx < 0){
            dx *= -1;
            dy *= -1;
        }
        if(dy == 0) dx = 1;
        else if(dx == 0) dy = 1;
        else {
            int g = gcd(dx, abs(dy));
            dx /= g; dy /= g;
        }
        auto tmp = tl({dx, dy, dx * (A[i].x + A[j].x) + dy * (A[i].y + A[j].y)});
        if(M.find(tmp) == M.end()) M[tmp] = map<ll, ll>();
        ll b = dy * (A[i].x + A[j].x) - dx * (A[i].y + A[j].y);
        M[tmp][b] = max(M[tmp][b], A[i].c + A[j].c);
    }
    for(auto [_, MM]: M){
        vector<ll> v;
        for(auto [i, j]: MM) v.eb(j);
        sort(all(v), greater<ll>());
        if(v.size() < 2) continue;
        ans = max(ans, v[0] + v[1]);
    }
    cout << ans << endl;
}
