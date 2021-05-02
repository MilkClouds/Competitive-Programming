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

const int INF = 1e9;
int TC, ans;
string S, E;
inline char inv_(char c){
    return c == '0' ? '1' : '0';
}
inline char inv(char c, int i){
    return i % 2 ? inv_(c) : c;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    rep(tc, 1, TC + 1){
        ans = INF;
        cin >> S >> E;
        int a = 1, b = 1, bias = 0;
        rep(i, 0, S.size() - 1) if(S[i] != S[i + 1]) a++;
        rep(i, 0, E.size() - 1) if(E[i] != E[i + 1]) b++;
        if(S == "0") {
            if(E == "0") {
                printf("Case #%d: %d\n", tc, 0);
                continue;
            }
            bias = 1;
            S = "1";
        }
        if(E == "0"){
            printf("Case #%d: %d\n", tc, a);
            continue;
        }
        rep(aa, 0, 1 + a){
            int k = 1, i = 0, flag = 0;
            for(; i < S.size(); i++) {
                if(k == aa + 1) break;
                if(i != S.size() - 1 && S[i] != S[i + 1]) k++;
            }
            if(S.size() - i > E.size()) continue;
            rep(j, i, S.size()){
                if(inv(S[j], aa) != E[j - i]) {flag = 1; break;}
            }
            if(flag) continue;
            if(E.size() == S.size() - i){
                ans = min(ans, aa);
                continue;
            }
            string tmp(1, E[S.size() - i]);
            rep(j, S.size() - i, E.size()) {
                if(E[j] != tmp[tmp.size() - 1]) tmp += E[j];
            }
            if(tmp.size() > aa + 1 || ((tmp.size() == aa + 1) && (aa % 2 ? tmp[0] != '1' : tmp[0] != '0'))) continue;
            ans = min(ans, (int)E.size() - ((int)S.size() - i) + aa);
        }
        if(ans == INF){
            printf("Case #%d: IMPOSSIBLE\n", tc);
        } else {
            printf("Case #%d: %d\n", tc, ans + bias);
        }
    }
}
