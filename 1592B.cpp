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

const int MAX = 1e5;
int TC, n, x, A[MAX];
void solve(){
    cin >> n >> x;
    rep(i, 0, n) cin >> A[i];
    if(n >= 2 * x){
        cout << "YES\n";
        return;
    }
    vector<int> S;
    rep(i, 0, n - x){
        S.eb(A[i]);
        S.eb(A[i + x]);
    }
    sort(all(S));
    rep(i, 0, n - x){
        A[i] = S[i];
        A[i + x] = S[i + n - x];
    }
    rep(i, 1, n) if(A[i - 1] > A[i]){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--) solve();
}
