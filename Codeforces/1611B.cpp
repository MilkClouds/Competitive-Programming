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

ll TC, a, b;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> a >> b;
        ll ans = 0;
        for(int i = 0; i < 2; i++, swap(a,b)){
            ll tmp = (a - b) / 2;
            tmp = min({tmp, a / 3, b});
            if(tmp <= 0) continue;
            a -= tmp * 3;
            b -= tmp;
            ans += tmp;
        }
        ll tmp = min(a, b) / 2;
        a -= tmp * 2; b -= tmp * 2;
        ans += tmp;
        cout << ans << '\n';
    }
}
