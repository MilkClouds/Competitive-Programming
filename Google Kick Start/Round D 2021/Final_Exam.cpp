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

const int MAX = 1e5;
int TC;
int N, M;
pl A[MAX];
ll x;
set<pl> S;
void solve(){
    cin >> N >> M;
    S.clear();
    rep(i, 0, N) {
        cin >> A[i].x >> A[i].y;
        S.insert(A[i]);
    }
    rep(i, 0, M){
        cin >> x;
        auto pos = S.lower_bound({x + 1, 0});
        if(pos == S.begin()){
            cout << pos->x << " ";
            if(pos->y != pos->x) S.emplace(pos->x + 1, pos->y);
            S.erase(pos);
        } else{
            auto pos2 = pos;
            pos--;
            if(x <= pos->y){
                if(pos->x <= x - 1) S.emplace(pos->x, x - 1);
                if(pos->y >= x + 1) S.emplace(x + 1, pos->y);
                cout << x << " ";
                S.erase(pos);
            } else {
                if(pos2 == S.end() || x - pos->y <= pos2->x - x){
                    if(pos->x != pos->y)S.emplace(pos->x, pos->y - 1);
                    cout << pos->y << " ";
                    S.erase(pos);
                } else {
                    if(pos2->x != pos2->y) S.emplace(pos2->x + 1, pos2->y);
                    cout << pos2->x << " ";
                    S.erase(pos2);
                }
            }
        }
    }
    cout << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}
