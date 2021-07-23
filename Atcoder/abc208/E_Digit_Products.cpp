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

const ll MOD = 1e9 + 7;
ll N, K, l, ans, ans2, oo, fac[20], r;
vector<int> B(10, 0);
string S;
ostream& operator << (ostream& os, const vector<int>& v){
    for(auto i: v) os << i << " ";
    return os;
}
ll process(){
    ll ret = fac[oo];
    rep(i, 1, 10) {
        ret /= fac[B[i]];
    }
    return ret;
}
ll calc(int i){
    ll ret = 0, tmp = 0;
    if(i == l) return 1;
    rep(j, 1, S[i] - '0') tmp += B[j];
    ret += process() * tmp / oo;
    int j = S[i] - '0';
    if(B[j]){
        B[j]--; oo--;
        ret += calc(i + 1);
        B[j]++; oo++;
    }
    return ret;
}
void dfs(int u, ll p){
    B[u]++; oo++;
    if(p <= K){
        if(l == oo){
            ans += calc(0);
        } else ans += process();
    }
    if(l == oo){
        ans2 += calc(0);
    } else ans2 += process();
    rep(v, 1, u + 1){
        if(oo >= l) continue;
        dfs(v, p * v);
    }
    B[u]--; oo--;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    fac[0] = fac[1] = 1;
    rep(i, 2, 20) fac[i] = fac[i - 1] * i;
    S = to_string(N);
    ll tmp = N;
    while(tmp){
        tmp /= 10;
        l++;
    }
    rep(i, 1, 10) dfs(i, i);
    cout << ans + N - ans2 << endl;
}
