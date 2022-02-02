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

const int MAX = 2e5 + 1;
int N, par[MAX], root, x, dist[MAX], ans[MAX], TC;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N;
        rep(i, 1, N + 1){
            cin >> par[i];
            if(i == par[i]) root = i;
        }
        fill(dist, dist + N + 1, -1);
        bool flag = 0;
        rep(i, 0, N){
            cin >> x;
            dist[x] = i;
            if(dist[par[x]] == -1){
                flag = 1;
            }
            ans[x] = dist[x] - dist[par[x]];
        }
        if(flag) cout << "-1\n";
        else rep(i, 1, N + 1) cout << ans[i] << " \n"[i == N];
    }
}
