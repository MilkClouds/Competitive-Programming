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

// https://codeforces.com/contest/1539/problem/E

const int MAX = 1e5;
int N, M, K, l, r = 1, a, b, c, d, ans[MAX];
deque<pi> A, B;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, N){
        cin >> K >> a >> b >> c >> d;
        if(a <= K && K <= b){
            if(c <= K && K <= d){
                A.eb(K, i);
                B.eb(K, i);
            } else {
                ans[i] = 0;
                l = K;
                A.clear();
            }
        } else {
            if(c <= K && K <= d){
                ans[i] = 1;
                r = K;
                B.clear();
            } else {
                cout << "No\n";
                return 0;
            }
        }
        
    }
}
