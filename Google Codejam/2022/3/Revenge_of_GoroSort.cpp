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

int T, N, K, A[101], B[101], cnt, vis[101];
queue<int> Q;
void dfs(int u){
    if(vis[u]){
        cnt++;
        while(!Q.empty()) {
            B[Q.front()] = cnt;
            Q.pop();
        }
        return;
    }
    Q.push(u);
    vis[u] = 1;
    dfs(A[u] - 1);
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> T >> N >> K;
    rep(tc, 0, T){
        cinA(A, N);
        bool finish = 0;
        do{
            cnt = 0;
            fill(vis, vis + N + 1, 0);
            rep(i, 0, N) if(!vis[i]) dfs(i);
            rep(i, 0, N) cout << B[i] << " "; cout << endl;
            cin >> finish;
            if(finish == -1 || K-- == 0) return 0;
            if(!finish) cinA(A, N);
        } while(!finish);
    }
}

