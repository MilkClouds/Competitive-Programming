#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
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

ll N;
vector<pl> ans;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(r, 2, 1000001){
        ll i = 1, s = 1, j = 1;
        while(1){
            i *= r;
            s += i;
            if(s > N) break;
            if(++j >= 3) ans.eb(s, r);
        }
        if(j < 3) break;
    }
    for(auto [s, r]: ans){
        if(N % s == 0){
            vector<ll> ret;
            ll ii = N / s, ss = ii;
            ret.eb(ii);
            while(ss < N){
                ii *= r;
                ss += ii;
                ret.eb(ii);
            }
            cout << ret.size() << "\n";
            for(auto i: ret) cout << i << " ";
            return 0;
        }
    }
    cout << "-1\n";
}
