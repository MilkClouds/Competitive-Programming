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
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

#include <ext/pb_ds/assoc_container.hpp> // for gp_hash_table
using namespace __gnu_pbds;

const int MAX = 5001;
int N, Q, A[MAX];
ll cnt[MAX][MAX], ans[MAX][MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> Q;
    cinA(A, N);
    rep(i, 0, N){
        gp_hash_table<int,int> M({},{},{},{},{1<<13}); 
        rep(j, i + 1, N){
            if(j - i > 1) cnt[i][j] = M[-A[i] - A[j]];
            M[A[j]]++;
        }
    }
    rep(k, 2, N) rep(i, 0, N - k) ans[i][i + k] = ans[i + 1][i + k] + ans[i][i + k - 1] - ans[i + 1][i + k - 1] + cnt[i][i + k];
    while(Q --> 0){
        int u, v;
        cin >> u >> v; u--; v--;
        cout << ans[u][v] << "\n";
    }
}
