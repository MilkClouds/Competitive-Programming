# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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

const int MAX = 50002;
int N, T, C[MAX];
string S;
char E[MAX];
void solve(){
    cin >> N >> T >> S;
    fill(C, C + N + 1, 0);
    fill(E, E + N + 1, 0);
    rep(i, 0, N){
        if(S[i] == '0'){
            if(i - T >= 0) E[i - T] = '0';
            if(i + T < N) E[i + T] = '0';
        }
    }
    rep(i, 0, N){
        if(S[i] == '1'){
            if(i >= T && E[i - T] == '1') continue;
            if(i + T < N && E[i + T] == 0){
                E[i + T] = '1';
            } else {
                assert(i - T >= 0);
                E[i - T] = '1';
            }
        }
    }
    rep(i, 0, N) if(E[i] == 0) E[i] = '0';
    cout << E << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << '\n';
        solve();
    }
}
