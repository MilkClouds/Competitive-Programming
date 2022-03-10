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

ll solve(ll n, ll s, ll e){
    ll ret = 0, sq = sqrt(n);
    if(e - s < sq * 4){
        for(ll i = s; i <= e; i++) ret += n / i;
        return ret;
    }
    for(ll i = s, j; i <= n; i = j + 1){
        if(i < sq){
            j = i;
            ret += n / i;
            continue;
        }
        j = n / (n / i);
        ret += (j - i + 1) * (n / i);
    }
    for(ll i = e + 1, j; i <= n; i = j + 1){
        if(i < sq){
            j = i;
            ret += n / i;
            continue;
        }
        j = n / (n / i);
        ret -= (j - i + 1) * (n / i);
    }
    return ret;
}
map<pl, ll> M;
ll solve2(ll n, ll s, ll e){
    ll ret = 0, sq = sqrt(n);
    e = min(e, n);
    if(e - s < sq * 2){
        for(ll i = s; i <= e; i++) ret += n / i;
        return ret;
    }
    ll j = n / (n / s);
    ret += (j - s + 1) * (n / s) + M[pl(n, j + 1)];
    if(e < n){
        s = e + 1;
        j = n / (n / s);
        ret -= (j - s + 1) * (n / s) + M[pl(n, j + 1)];
    }
    return ret;
}
set<ll> S;
vector<tl> query;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    ll Q, n, s, e;
    cin >> Q;
    query.resize(Q);
    rep(i, 0, Q){
        cin >> n >> s >> e;
        query[i] = {n, s, e};
        S.insert(n);
    }
    if(S.size() == 1){
        ll tmp = 0;
        for(ll i = 1, j; i <= n; i = j + 1){
            j = n / (n / i);
            tmp += (j - i + 1) * (n / i);
        }
        for(ll i = 1, j; i <= n; i = j + 1){
            j = n / (n / i);
            M[pl(n, i)] = tmp;
            tmp -= (j - i + 1) * (n / i);
        }
        M[pl(n, n + 1)] = 0;
    }
    for(auto [n, s, e]: query) cout << (S.size() == 1 ? solve2 : solve)(n, s, e) << "\n";
}
