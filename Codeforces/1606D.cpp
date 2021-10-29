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

int TC, N, M;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        rep(i, 0, N) rep(j, 0, M) cin >> A[i][j];
        set<int> last;
        vector<pi> tmp;
        rep(i, 0, N) tmp.eb(A[i][0], i);
        sort(all(tmp));
        rep(i, 0, N - 1) last.insert(tmp[i].y);
        int chk = -1;
        rep(j, 0, M){
            vector<pi> tmp;
            rep(i, 0, N) tmp.eb(A[i][j], i);
            ~chk ? sort(all(tmp), greater<pi>()) : sort(all(tmp));
            set<int> nxt;
            for(int k = 0; k < min(tmp.size(), last.size()); k++){
                if(last.count(tmp[k].y)) nxt.insert(tmp[k].y);
                else break;
            }
            cout << nxt.size() << " " << j << endl;
            if(nxt.size() == 0 && chk == -1){
                chk = j;
                cout << nxt.size() << " " << j << endl;
                sort(all(tmp), greater<pi>());
                for(int k = 0; k < min(tmp.size(), last.size()); k++){
                    if(last.count(tmp[k].y)) nxt.insert(tmp[k].y);
                    else break;
                }
            }
            last.swap(nxt);
            if(last.empty()) break;
        }
        if(last.empty() || chk == -1) cout << "NO\n";
        else {
            cout << "YES\n";
            vector<char> ans(N, 'R');
            for(auto i: last) ans[i] = 'B';
            rep(i, 0, N) cout << ans[i];
            cout << " " << chk << "\n"; 
        }
    }
}
