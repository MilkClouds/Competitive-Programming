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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e5 + 1;
int N, Q, x, y, c, nxt[MAX], pre[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> Q;
    while(Q--){
        cin >> c;
        if(c != 3){
            cin >> x >> y;
            if(c == 1){
                nxt[y] = x;
                pre[x] = y;
            } else {
                nxt[y] = pre[x] = 0;
            }
        } else {
            cin >> x;
            deque<int> ans = {x};
            int t = x;
            while(nxt[t]){
                t = nxt[t];
                ans.push_front(t);
            }
            t = x;
            while(pre[t]){
                t = pre[t];
                ans.push_back(t);
            }
            cout << ans.size() << " "; for(auto i: ans) cout << i << " ";
            cout << "\n";
        }
    }
}
