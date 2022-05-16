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

int N, K;
ll _solve(vector<pi>& Q){
    sort(all(Q));
    ll ans = 0;
    vector<int> C, D;
    rep(i, 0, Q.size()) (Q[i].y ? C : D).eb(Q[i].x);
    while(!C.empty() && !D.empty()){
        if(C.back() > D.back()) C.swap(D);
        vector<pi> cand;
        if(D.size() > 1){
            cand.eb(-(D[D.size() - 2] * 2 - K), 1);
        }
        cand.eb(-C[C.size() - 1] * 2, 0);
        sort(all(cand));
        ans += D.back() * 2;
        if(cand[0].y){
            D.pop_back();
            ans += K;
        } else C.pop_back();
        D.pop_back();
    }
    if(!D.empty()) C.swap(D);
    while(!C.empty()){
        vector<pi> cand;
        if(C.size() > 1){
            cand.eb(-(C[C.size() - 2] * 2 - K), 1);
        }
        cand.eb(0, 0);
        sort(all(cand));
        ans += C.back() * 2;
        if(cand[0].y){
            C.pop_back();
            ans += K;
        }
        C.pop_back();
    }
    return ans;
}
void solve(){
    cin >> N >> K;
    vector<pi> A, B;
    rep(i, 0, N){
        pi P;
        cin >> P.x >> P.y;
        if(P.x < 0) A.eb(-P.x, P.y);
        else B.pb(P);
    }
    cout << _solve(A) + _solve(B) << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}

