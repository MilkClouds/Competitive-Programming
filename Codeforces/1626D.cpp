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

int TC;
ll calc(ll i){
    rep(j, 0, 19) if((1 << j) >= i) return (1 << j) - i;
    return -1;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        ll N, x, ans = 1e16;
        cin >> N;
        vector<ll> v(N + 1), S(N + 1);
        rep(i, 0, N){
            cin >> x;
            v[x]++;
        }
        rep(i, 0, N) S[i + 1] = S[i] + v[i + 1];
        rep(i, 0, 19){
            auto pos = upper_bound(all(S), 1 << i); pos--;
            ll tmp = (1 << i) - *pos;
            if(S[N] - *pos == 0){
                ans = min(ans, tmp + 2);
                continue;
            }
            rep(j, 0, 19){
                auto pos2 = upper_bound(pos + 2, S.end(), (1 << j) + *pos); pos2--;
                if(*pos2 - *pos > (1 << j)) continue;
                // cout << i << " " << j << " " << (1 << j) << " " << *pos2 - *pos << endl;
                // cout << "!" << calc(S[N] - *pos2) << endl;
                // cout << tmp << " " << (1 << j) - *pos2 << " " << calc(S[N] - *pos2) << endl;
                ans = min(ans, tmp + (1 << j) - *pos2 + *pos + calc(S[N] - *pos2));
            }
        }
        cout << ans << "\n";
    }
}
