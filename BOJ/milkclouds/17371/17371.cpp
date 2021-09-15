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

int N, ans;
double minDist = 123456789;
pi A[1003];
double dist(pi a, pi b){
    double x = a.x - b.x;
    double y = a.y - b.y;
    return sqrt(x * x + y * y);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i].x >> A[i].y;
    rep(i, 0, N) {
        double d = 0;
        rep(j, 0, N){
            d = max(d, dist(A[i], A[j]));
        }
        if(d < minDist){
            minDist = d;
            ans = i;
        }
    }
    cout << A[ans].x << " " << A[ans].y << endl;
}
