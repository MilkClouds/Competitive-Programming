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

int N, K, t, b;
string S, T;
vector<int> v;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K >> S;
    rep(i, 1, N) {
        if(S[i] > S[0]) {
            N = i;
            break;
        }
        if(S[i] == S[0]) v.pb(i);
    }
    v.pb(N);
    t = v[0];
    rep(i, 0, v.size() - 1){
        bool flag = 0;
        rep(j, 0, v[i + 1] - v[i]){
            if(S[j + v[i]] == S[j % v[i]]) continue;
            if(S[j + v[i]] > S[j % v[i]]) flag = 1;
            break;
        }
        //cout << i << " " << v[i] << " " << flag << endl;
        if(flag) break;
        t = v[i + 1];
    }
    T = S.substr(0, t);
    rep(_, 0, K / t){
        cout << T;
    }
    rep(i, 0, K - (K / t) * t){
        cout << S[i];
    }
    cout << '\n';
}
