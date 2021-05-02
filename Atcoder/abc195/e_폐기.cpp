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
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

int N, dp[1 << 7][N];
string S, X;

int mod(int i){
    i = i % 7;
    return i < 0 ? i + 7 : i;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> S >> X;
    SET.insert(0);
    rep(i, 0, N){
        set<int> tmp;
        for(auto k: SET){
            tmp.insert(mod((S[i] - '0') + k * 10));
            tmp.insert(mod(k * 10));
        }
        for(auto j: tmp) cout << j << " " ;
        cout << endl;
        if(i < N - 1 && X[i] != X[i + 1]){
            if(X[i] == 'A'){
                tmp.erase(0);
            } else {
                rep(j, 1, 7) tmp.erase(j);
            }
        }
        SET = tmp;
    }
    cout << (SET.count(0) ? "Takahashi" : "Aoki");
}
