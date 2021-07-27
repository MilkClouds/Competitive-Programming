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

int TC, N, A[50001][5], ans;
bool fLag;
bool cmp(int *a, int *b){
    rep(i, 0, 5) rep(j, i + 1, 5) rep(k, j + 1, 5){
        if(*(a + i) < *(b + i) && *(a + j) < *(b + j) && *(a + k) < *(b + k)) return 1;
    }
    return 0;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N;
        rep(i, 0, N) rep(j, 0, 5) cin >> A[i][j];
        A[N][0] = A[N][1] = A[N][2] = A[N][3] = A[N][4] = 50001; ans = N;
        rep(i, 0, N){
            if(cmp(A[i], A[ans])){
                ans = i;
            }
        }
        fLag = 0;
        rep(i, 0, N){
            if(ans == i || cmp(A[ans], A[i])) continue;
            fLag = 1;
        }
        cout << (fLag ? -1: ans + 1) << "\n";
    }
}
