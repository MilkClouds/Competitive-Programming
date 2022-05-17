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

const int MAX = 5000;
int R, A[MAX][MAX], B[MAX][MAX];
void draw(int x, int y, bool flag = 0){
    (flag ? A : B)[x + R][y + R] = 1;
}
void draw_circle_perimeter(ll R){
    rep(x, -R, R + 1){
        int y=round(sqrt(R * R - x * x));
        draw(x, y);
        draw(x, -y);
        draw(y, x);
        draw(-y, x);
    }
}
void draw_circle_filled(ll R){
    rep(x, -R, R + 1){
        rep(y, -R, R + 1){
            if(round(sqrt(x * x + y * y)) <= R){
                draw(x, y, 1);
            }
        }
    }
}
void draw_circle_filled_wrong(ll R){
    rep(r, 0, R + 1) draw_circle_perimeter(r);
}
ll getans(ll R){
    fill(A[0], A[MAX], 0);
    fill(B[0], B[MAX], 0);
    draw_circle_filled_wrong(R);
    draw_circle_filled(R);
    ll cnt = 0;
    rep(x, 0, 2 * R + 1){
        rep(y, 0, 2 * R + 1) cnt += A[x][y] != B[x][y];
    }
    return cnt;
}
void solve(){
    ll N;
    cin >> N; R = N;
    cout << getans(N) << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}

