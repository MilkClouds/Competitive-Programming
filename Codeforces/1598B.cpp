#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

int N, A[1001][5];
bool solve(){
    cin >> N;
    rep(i, 0, N) rep(j, 0, 5) cin >> A[i][j];
    rep(i, 0, 5) rep(j, i + 1, 5){
        int a = 0, b = 0, c = 0;
        rep(k, 0, N){
            if(A[k][i] && A[k][j]) a++;
            else if(A[k][i]) b++;
            else if(A[k][j]) c++;
        }
        if(a + b < N / 2){
            continue;
        }
        if(a - max(0, N / 2 - b) + c < N / 2){
            continue;
        }
        return 1;
    }
    return 0;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--) cout << (solve() ? "YES" : "NO") << "\n";
}
