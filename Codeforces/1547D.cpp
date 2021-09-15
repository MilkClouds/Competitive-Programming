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

const int MAX = 2e5;
int TC, N, A[MAX], B[MAX];
int cnt(int a){
    int ret = 0;
    while(a){
        a >>= 1;
        ret++;
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N;
        rep(i, 0, N) cin >> A[i];
        fill(B, B + N, 0);
        rep(i, 1, N){
            int c = A[i - 1] ^ B[i - 1];
            rep(j, 0, 30){
                int x = c & (1 << j);
                int y = A[i] & (1 << j);
                if(x && y == 0) B[i] ^= 1 << j;
            }
        }
        rep(i, 0, N) cout << B[i] << " \n"[i == N - 1];
    }
}
