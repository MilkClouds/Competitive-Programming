#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define rep2(i,a,b) for(ll i = (b) - 1; i >= (a); i--)
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

// 30 min(distracted)
const int MAX = 2e5 + 1, INF = 2e9;
int N, Q, c, x, m, A[MAX][30], L[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i][0], A[i][0]--;
    fill(L + 1, L + N, INF);
    rep(j, 0, 30){
        rep(i, 0, N){
            if(j) A[i][j] = A[A[i][j - 1]][j - 1];
            if(L[i] == INF && L[A[i][j]] < INF) L[i] = L[A[i][j]] + (1 << j);
        }
    }
    cin >> Q;
    while(Q--){
        cin >> c;
        if(c & 1){
            cin >> x;
            A[0][0] = --x;
        } else {
            cin >> m >> x; x--;
            if(L[x] < m){
                m -= L[x] + 1;
                if(A[0][0] == 0) m = 0;
                x = A[0][0];
            }
            m %= L[x] + 1;
            for(int j = 30; ~j; j--) if(m >= (1 << j)){
                m -= 1 << j;
                x = A[x][j];
            }
            cout << x + 1 << "\n";
        }
    }
}
