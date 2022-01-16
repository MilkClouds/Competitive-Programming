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

ll a, N;
map<ll, ll> M;
set<pl> Q;
ll poow(ll i){
    ll k = 1;
    rep(j, 0, i) k *= 10;
    return k;
}
ll loog(ll j){
    rep(i, 0, 19) if(j < poow(i)) return i - 1;
    return -1;
}
ll conv(ll i){
    if(i % 10 == 0) return 1;
    return i / 10 + (i % 10) * poow(loog(i));
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> a >> N; Q.insert(pi(0, 1)); M[1] = 0;
    do{
        auto [cnt, u] = *Q.begin(); Q.erase(pi(cnt, u));
        // cout << u << " " << cnt << '\n';
        for(auto v: {conv(u), u * a}){
            if(M.find(v) != M.end()) continue;
            if(loog(v) > loog(N)) continue;
            M[v] = cnt + 1;
            Q.insert(pi(cnt + 1, v));
        }
    } while(!Q.empty() && M.find(N) == M.end());
    cout << (M[N] ? M[N] : -1) << endl;
}
