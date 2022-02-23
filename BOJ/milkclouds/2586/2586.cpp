#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e5 + 111;
ll P, F, lv = MAX, ans;
pl A[MAX * 2];
vector<ll> LV[MAX * 2];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> P >> F;
    rep(i, 0, P + F) cin >> A[i].x;
    rep(i, 0, P) A[i].y = 1;
    sort(A, A + P + F);
    rep(i, 0, P + F){
        LV[A[i].y ? ++lv : lv--].eb(A[i].x);
    }
    rep(lv, 0, MAX * 2){
        ll S = 0, t = 0;
        for(int i = 1; i < LV[lv].size(); i += 2) S += LV[lv][i] - LV[lv][i - 1];
        t = S;
        if(LV[lv].size() & 1){
            for(int i = LV[lv].size() - 1; i > 1; i -= 2){
                t = min(t, S += LV[lv][i] - LV[lv][i - 1] * 2 + LV[lv][i - 2]);
            }
        }
        ans += t;
    }
    cout << ans << endl;
}
