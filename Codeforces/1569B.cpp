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

void solve(){
    int N, T[] = {0, 0};
    string S, ans[51];
    cin >> N >> S;
    rep(i, 0, N) ans[i] = S;
    for(auto i: S) T[i - '1']++;
    if(T[1] == 1 || T[1] == 2){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    rep(i, 0, N) {
        bool flag = 0;
        rep(j, i, N){
            if(i == j) {
                ans[i][j] = 'X';
                continue;
            }
            if(S[i] == '1' || S[j] == '1') ans[i][j] = '=';
            else ans[i][j] = (flag ^= 1) ? '+' : '-';
        }
    }
    rep(i, 0, N) rep(j, 0, i) {
        if(ans[j][i] == '+') ans[i][j] = '-';
        else if(ans[j][i] == '-') ans[i][j] = '+';
        else ans[i][j] = ans[j][i];
    }
    rep(i, 0, N) cout << ans[i] << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--) solve();
}
