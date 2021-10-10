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


int N, M, R[101], W[101];
char A[101][101];
void process(int p, char i, int q, char j){
    if(i == 'G'){
        if(j == 'C'){
            W[p]++;
        } else if(j == 'P'){
            W[q]++;
        }
    } else if(i == 'C'){
        if(j == 'P'){
            W[p]++;
        } else if(j == 'G'){
            W[q]++;
        }
    } else {
        if(j == 'G'){
            W[p]++;
        } else if(j == 'C'){
            W[q]++;
        }
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, 2 * N) rep(j, 0, M) cin >> A[i][j];
    rep(i, 0, 2 * N) R[i] = i;
    rep(j, 0, M){
        rep(i, 0, N){
            process(R[i * 2], A[R[i * 2]][j], R[i * 2 + 1], A[R[i * 2 + 1]][j]);
        }
        sort(R, R + 2 * N, [](int i, int j){
            if(W[i] != W[j]) return W[i] > W[j];
            return i < j;
        });
    }
    rep(i, 0, 2 * N) cout << R[i] + 1 << "\n";
}
