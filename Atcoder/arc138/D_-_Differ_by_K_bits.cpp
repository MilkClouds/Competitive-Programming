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

int N, K, t;
set<int> S;
vector<int> v, z;
void construct(int s, int k){
    if(k == 0) {
        v.eb(t); S.insert(t);
        return;
    }
    construct(s, k - 1);
    t ^= z[k - 1];
    construct(s + (1 << k - 1), k - 1);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    if(K % 2 == 0 || (1 < K && N == K)) {cout << "No\n"; return 0;}
    rep(i, 0, K - 1) z.pb(((1 << K + 1) - 1) ^ 1 << i);
    rep(i, K - 1, N) z.pb(((1 << K - 1) - 1) ^ 1 << i);
    construct(0, N);
    cout << "Yes\n";
    for(auto i: v) cout << i << " ";
}
