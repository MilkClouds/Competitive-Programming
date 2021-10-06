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

int A, B, N, D[2001];
set<pi> S, tmp;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> A >> B;
    A = A + B, B = A - 2 * B;
    rep(i, 0, N) cin >> D[i];
    S.emplace(0, 0);
    rep(k, 0, N){
        for(auto [i, j]: S){
            cout << i << " " << j << " " << D[k] << endl;
            tmp.emplace(i - D[k], -1);
            tmp.emplace(i + D[k], 1);
        }
        cout << endl;
        S = tmp;
    }
}
