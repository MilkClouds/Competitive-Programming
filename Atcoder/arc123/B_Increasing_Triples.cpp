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

const int MAX = 1e5 + 10;
int N, A[MAX], B[MAX], C[MAX], cnt;
multiset<int> seta, setc;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, N) cin >> C[i];
    sort(B, B + N);
    rep(i, 0, N) seta.insert(A[i]), setc.insert(C[i]);
    rep(j, 0, N){
        auto ap = seta.lower_bound(B[j]);
        auto cp = setc.upper_bound(B[j]);
        if(ap == seta.begin() || cp == setc.end()) continue;
        ap--;
        seta.erase(ap);
        setc.erase(cp);
        cnt++;
    }
    cout << cnt << endl;
}
