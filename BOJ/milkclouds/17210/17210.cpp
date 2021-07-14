# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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

ll N, A[123456];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> A[1];
    rep(i, 1, min(1234LL, N)) A[i + 1] = A[i] ^ 1;
    rep(i, 0, min(1234LL, N + 1)) if((i > 2 && i % 2 == 0 && A[i] != A[i - 2]) || (i > 3 && i % 3 == 0 && A[i] != A[i - 3])){
        cout << "Love is open door\n";
        return 0;
    }
    rep(i, 1, N) cout << A[i + 1] << "\n";
}
