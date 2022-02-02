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

const int MAX = 2e5 + 1;
ll TC, N, S, A[MAX], pSum[MAX];
pl ret;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N >> S;
        cinA(A, N);
        rep(i, 0, N) pSum[i + 1] = pSum[i] + A[i];
        vector<pl> v; v.eb(pSum[N], N);
        ll ans = 0;
        rep2(i, 0, N){
            auto pos = lower_bound(all(v), pl(pSum[i] - S, -1));
            if(pos != v.end()){
                if(ans < pos -> y - i){
                    ret = {i + 1, pos -> y};
                    ans = pos -> y - i;
                }
            }
            ll tmp = i;
            while(!v.empty() && v.back().x > pSum[i]){
                tmp = max(tmp, v.back().y);
                v.pop_back();
            }
            v.eb(pSum[i], tmp);
        }
        if(ans == 0) cout << "-1\n";
        else cout << ret.x << " " << ret.y << '\n';
    }
}
