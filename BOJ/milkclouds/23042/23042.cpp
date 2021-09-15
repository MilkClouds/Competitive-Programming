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

const int MOD = 1e9 + 7;
int N, n, A[30], ans = 1;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N){
        cin >> n;
        rep(j, 0, 30){
            if(n & (1 << j)) A[j]++;
        }
    }
    rep(i, 0, N){
        int tmp = 0;
        rep(j, 0, 30) if(A[j]) tmp |= 1 << j, A[j]--;
        ans = ((ll) ans * tmp) % MOD;
    }
    cout << ans << endl;
}
