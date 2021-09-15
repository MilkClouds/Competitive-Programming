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

const int MAX = 1e5 + 10;
int H, W, N;
pi A[MAX];
vector<pi> RR, CC;
set<int> R, C;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> H >> W >> N;
    rep(i, 0, N) cin >> A[i].x >> A[i].y;
    rep(i, 0, N){
        R.insert(A[i].x);
        C.insert(A[i].y);
    }
    int cnt = 0;
    for(auto i: R){
        RR.eb(i, ++cnt);
    }
    cnt = 0;
    for(auto i: C){
        CC.eb(i, ++cnt);
    }
    rep(i, 0, N){
        cout << lower_bound(all(RR), pi(A[i].x, 0))->y << " " << lower_bound(all(CC), pi(A[i].y, 0))->y << "\n";
    }
}
