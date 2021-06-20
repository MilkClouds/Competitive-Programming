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
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 1e4;
int N, a;
ll ans;
vector<int> A, B, C;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) {
        cin >> a;
        if(a < 0) A.eb(-a);
        else if(a > 0) B.eb(a);
        else C.eb(a);
    }
    sort(all(A));
    sort(all(B));
    rep2(i, 0, A.size()){
        if(i == 0){
            ans -= A[i] * C.empty();
            break;
        }
        ans += A[i] * A[i - 1];
        i--;
    }
    rep2(i, 0, B.size()){
        if(i == 0){
            ans += B[i];
            break;
        }
        if(B[i - 1] == 1) ans += B[i] + B[i - 1];
        else ans += B[i] * B[i - 1];
        i--;
    }
    cout << ans << endl;
}
