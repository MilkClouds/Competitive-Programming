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
using ull = unsigned ll;

const ll M = 1e9;
int TC;
ull a, b, c, d;
string S, T;
int main() {
    cin >> TC;
    while(TC--){
        bool flag = 0;
        cin >> S >> T;
        if(S[0] == '-') S = S.substr(1), flag ^= 1;
        if(T[0] == '-') T = T.substr(1), flag ^= 1;
        sscanf(S.c_str(), "%llu.%llu", &a, &b);
        sscanf(T.c_str(), "%llu.%llu", &c, &d);
        ull ans = (a * M + b) * (c * M + d);
        if(flag) cout << "-";
        printf("%llu.%.018llu\n", ans / (M * M), ans % (M * M));
    }
}
