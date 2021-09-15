# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
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
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 2e5, INF = 2e9;
int TC, N, H[MAX];
void solve(){
    cin >> N;
    rep(i, 0, N) cin >> H[i];
    sort(H, H + N);
    int T = INF;
    vector<int> t;
    rep(i, 1, N){
        int diff = H[i] - H[i - 1];
        if(diff < T){
            T = diff;
            t.clear();
            t.pb(i);
        }
    }
    if(N == 2){
        cout << H[0] << " " << H[1] << "\n";
        return;
    }
    rep(i, t[0], N) cout << H[i] << " ";
    rep(i, 0, t[0]) cout << H[i] << " \n"[i == t[0] - 1];
    // if(N == 3){
    //     if(t[0] == 1) cout << H[0] << " " << H[2] << " " << H[1] << "\n";
    //     else cout << H[1] << " " << H[0] << " " << H[2] << "\n";
    //     return;
    // }
    // if(N == 4){

    // }
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--) solve();
}
