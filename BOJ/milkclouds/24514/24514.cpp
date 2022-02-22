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

const int MAX = 1e5;
ll T, K, N, j, S[MAX], A[MAX];
ll f(ll num, ll nth){
    vector<ll> v;
    while(num){
        v.eb(num % K);
        num /= K;
    }
    reverse(all(v));
    return v[nth - 1];
}
ll loog(ll i, ll K){
    ll t = 1, j = 0;
    while(t * K <= i){
        t *= K;
        j++;
    }
    return j;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> T >> K;
    rep(i, 1, MAX){
        j += loog(i, K) + 1;
        A[i] = j;
        S[i] = S[i - 1] + j;
    }
    while(T--){
        cin >> N;
        ll rem = N - *(lower_bound(S, S + MAX, N) - 1);
        auto pos = lower_bound(A, A + MAX, rem) - 1;
        cout << f(pos - A + 1, rem - *pos) << "\n";
    }
}
