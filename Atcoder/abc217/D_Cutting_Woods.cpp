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

set<int> S;
int L, Q, c, x;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> L >> Q;
    S.insert(0); S.insert(L);
    rep(i, 0, Q){
        cin >> c >> x;
        if(c == 1){
            S.insert(x);
        } else{
            auto pos = S.lower_bound(x);
            cout << (*pos - *(--pos)) << "\n";
        }
    }
}
