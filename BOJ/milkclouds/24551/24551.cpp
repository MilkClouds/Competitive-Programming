#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

ll N, ret, M;
ll f(ll x){
    ll ret = 0;
    rep(_, 0, x) ret = ret * 10 + 1;
    return ret;
}
__int128 gcd(__int128 x, __int128 y){return x % y ? gcd(y, x % y) : y;}
__int128 lcmm(__int128 x, __int128 y){return x * y / gcd(x, y);}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    M = ceil(log10l(N)) - 1;
    rep(i, 1, 1 << M){
        __int128 d = 1, c = 0;
        rep(j, 0, M){
            if(i & (1 << j)) d = lcmm(d, f(j + 2)), c++;
        }
        ret += (c % 2 ? 1 : -1) * N / d;
    }
    cout << ret << "\n";
}
