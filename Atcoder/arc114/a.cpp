# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

vector<int> pn = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int N, X[51];
ll ans = 1e18;
set<int> S[51];

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) {
        cin >> X[i];
        for(auto p: pn) if(X[i] % p == 0) S[p].insert(i);
    }
    rep(i, 0, 1 << 15){
        set<int> SS;
        ll mul = 1;
        rep(j, 0, 15){
            if(i & (1 << j)){
                mul *= pn[j];
                for(auto ii: S[pn[j]]) SS.insert(ii);
            }
        }
        if(SS.size() == N) ans = min(ans, mul);
    }
    cout << ans;
}
