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

const int MAX = 1e5;
int N, u, ans[MAX], chk[MAX], rchk[MAX];
set<int> adj[MAX], rev[MAX];
void solve(){
    cin >> N;
    fill(ans, ans + N, -1);
    fill(chk, chk + N, 0);
    fill(rchk, rchk + N, 0);
    rep(i, 0, N) adj[i].clear(), rev[i].clear();
    rep(i, 0, N){
        cin >> u; u--;
        adj[i].insert(u); rev[u].insert(i);
    }
    rep(i, 0, N){
        cin >> u; u--;
        adj[i].insert(u); rev[u].insert(i);
    }
    //rep(i, 0, N) for(auto j: adj[i]) if(adj[j].count(i)){cout << "IMPOSSIBLE\n"; return;}
    rep(i, 0, N){
        int tmp = chk[i], rtmp = rchk[i];
        for(auto j: adj[i]) tmp |= chk[j];
        for(auto j: rev[i]) rtmp |= rchk[j];
        int k = 0;
        for(; k < 13 && ((tmp | rtmp) & (1 << k)); k++);
        if(k == 13){
            cout << "IMPOSSIBLE\n";
            return;
        }
        ans[i] = k;
        for(auto j: rev[i]){
            if(rchk[j] & (1 << k)){
                cout << "IMPOSSIBLE\n";
                return;
            }
            chk[j] |= 1 << k;
        }
        for(auto j: adj[i]){
            if(chk[j] & (1 << k)){
                cout << "IMPOSSIBLE\n";
                return;
            }
            rchk[j] |= 1 << k;
            //if(i == 0 && j == 1) cout << k << " " << rchk[j] << "!" << endl;
        }
    }
    rep(i, 0, N){
        for(auto j: adj[i]){
            for(auto k: adj[j]){
                if(ans[i] == ans[j] || ans[j] == ans[k] || ans[i] == ans[k]){
                    cout << i << " " << j << " " << k << endl;
                    cout << ans[i] << " " << ans[j] << " " << ans[k] << endl;
                    cout << endl;
                }
            }
        }
    }
    rep(i, 0, N) cout << "ACDEHIJKMORST"[ans[i]]; cout << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}